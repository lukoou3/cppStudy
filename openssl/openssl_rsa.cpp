#include <iostream>
#include <string>
#include <cstring>
#include "windows.h"
#include "openssl/rsa.h"
#include <openssl/pem.h>	// 将秘钥写文件的时候
extern "C"
{
//#include <openssl/applink.c> // 编译的时候将applinc.c包含进去参与编译
};

using namespace std;

// 生成rsa密钥对
void generateRsaKey() {
    // 1. 创建rsa变量
    RSA* rsa = RSA_new();
    // 1.5 创建bignum对象, 并初始化
    BIGNUM* e = BN_new();
    BN_set_word(e, 12345);
    // 2. 生成密钥对 -> 密钥对在内存中
    RSA_generate_key_ex(rsa, 1024, e, NULL);

    // 3. 将密钥对写入到磁盘
    /*FILE* fp = fopen("public.pem", "w");
    PEM_write_RSAPublicKey(fp, rsa);
    fclose(fp);
    // 写私钥
    fp = fopen("private.pem", "w");
    PEM_write_RSAPrivateKey(fp, rsa, NULL, NULL, 0, NULL, NULL);
    fclose(fp);*/

    BIO* bio = BIO_new_file("public-1.pem", "w");
    PEM_write_bio_RSAPublicKey(bio, rsa);
    // 释放资源
    BIO_free(bio);
    bio = BIO_new_file("private-1.pem", "w");
    PEM_write_bio_RSAPrivateKey(bio, rsa, NULL, NULL, 0, NULL, NULL);
    BIO_free(bio);
}

// 公钥加密
string encryptPublicKey()
{
    // 1. 准备要加密数据
    string text = "让编程改变世界...";
    // 2. 准备秘钥 -> 公钥
    // 从磁盘文件读秘钥
    // 使用bio的方式
    BIO* bio = BIO_new_file("public-1.pem", "r");
    RSA* pubKey = RSA_new();
    if (PEM_read_bio_RSAPublicKey(bio, &pubKey, NULL, NULL) == NULL)
    {
        cout << "读公钥失败了..." << endl;
        return string();
    }
    BIO_free(bio);
    // 3. 加密 -> 密文
    // 数据被加密之后, 长度和秘钥长度相同
    // 通过函数计算秘钥长度
    int keyLen = RSA_size(pubKey);
    char *buf = new char[keyLen];
    // 返回值就是密文长度
    int len = RSA_public_encrypt(text.size(), (const unsigned char*)text.data(),
                                 (unsigned char*)buf, pubKey, RSA_PKCS1_PADDING);
    // 4. 将密文返回
    cout << "加密之后的数据: " << buf << endl;
    cout << "加密之后的数据长度: " << len << endl;
    return string(buf, len);
}

// 私钥解密
string decryptPrivateKey(string str){
    // 1. 准备秘钥 ->私钥
    // 从磁盘文件读秘钥
    // 使用bio的方式
    BIO* bio = BIO_new_file("private-1.pem", "r");
    RSA* priKey = RSA_new();
    if (PEM_read_bio_RSAPrivateKey(bio, &priKey, NULL, NULL) == NULL)
    {
        cout << "读私钥失败..." << endl;
        return string();
    }
    BIO_free(bio);
    // 解密 -> 明文
    // 数据被加密之后, 长度和秘钥长度相同
    // 通过函数计算秘钥长度
    int keyLen = RSA_size(priKey);
    char *buf = new char[keyLen];
    // 返回值是解密之后的数据长度 == 原始数据长度
    int len = RSA_private_decrypt(str.size(), (const unsigned char*)str.data(),
                                  (unsigned char*)buf, priKey, RSA_PKCS1_PADDING);
    // 4. 将明文返回
    cout << "buf: " << buf << endl;
    return string(buf, len);
}

// ---- rsa非对称加解密 ---- //
#define KEY_LENGTH  2048               // 密钥长度
#define PUB_KEY_FILE "pubkey.pem"    // 公钥路径
#define PRI_KEY_FILE "prikey.pem"    // 私钥路径

// 函数方法生成密钥对
void generateRSAKey(std::string strKey[2])
{
    // 公私密钥对
    size_t pri_len;
    size_t pub_len;
    char *pri_key = NULL;
    char *pub_key = NULL;

    // 生成密钥对
    RSA *keypair = RSA_generate_key(KEY_LENGTH, RSA_3, NULL, NULL);

    BIO *pri = BIO_new(BIO_s_mem());
    BIO *pub = BIO_new(BIO_s_mem());

    PEM_write_bio_RSAPrivateKey(pri, keypair, NULL, NULL, 0, NULL, NULL);
    PEM_write_bio_RSAPublicKey(pub, keypair);

    // 获取长度
    pri_len = BIO_pending(pri);
    pub_len = BIO_pending(pub);

    // 密钥对读取到字符串
    pri_key = (char *)malloc(pri_len + 1);
    pub_key = (char *)malloc(pub_len + 1);

    BIO_read(pri, pri_key, pri_len);
    BIO_read(pub, pub_key, pub_len);

    pri_key[pri_len] = '\0';
    pub_key[pub_len] = '\0';

    // 存储密钥对
    strKey[0] = pub_key;
    strKey[1] = pri_key;

    // 存储到磁盘（这种方式存储的是begin rsa public key/ begin rsa private key开头的）
    FILE *pubFile = fopen(PUB_KEY_FILE, "w");
    if (pubFile == NULL)
    {
        return;
    }
    fputs(pub_key, pubFile);
    fclose(pubFile);

    FILE *priFile = fopen(PRI_KEY_FILE, "w");
    if (priFile == NULL)
    {
        return;
    }
    fputs(pri_key, priFile);
    fclose(priFile);

    // 内存释放
    RSA_free(keypair);
    BIO_free_all(pub);
    BIO_free_all(pri);

    free(pri_key);
    free(pub_key);
}

// 命令行方法生成公私钥对（begin public key/ begin private key）
// 找到openssl命令行工具，运行以下
// openssl genrsa -out prikey.pem 1024
// openssl rsa - in privkey.pem - pubout - out pubkey.pem

// 公钥加密
std::string rsa_pub_encrypt(const std::string &clearText, const std::string &pubKey)
{
    std::string strRet;
    RSA *rsa = NULL;
    BIO *keybio = BIO_new_mem_buf((unsigned char *)pubKey.c_str(), -1);
    // 此处有三种方法
    // 1, 读取内存里生成的密钥对，再从内存生成rsa
    // 2, 读取磁盘里生成的密钥对文本文件，在从内存生成rsa
    // 3，直接从读取文件指针生成rsa
    RSA* pRSAPublicKey = RSA_new();
    rsa = PEM_read_bio_RSAPublicKey(keybio, &rsa, NULL, NULL);

    int len = RSA_size(rsa);
    char *encryptedText = (char *)malloc(len + 1);
    memset(encryptedText, 0, len + 1);

    // 加密函数
    int ret = RSA_public_encrypt(clearText.length(), (const unsigned char*)clearText.c_str(), (unsigned char*)encryptedText, rsa, RSA_PKCS1_PADDING);
    if (ret >= 0)
        strRet = std::string(encryptedText, ret);

    // 释放内存
    free(encryptedText);
    BIO_free_all(keybio);
    RSA_free(rsa);

    return strRet;
}

// 私钥解密
std::string rsa_pri_decrypt(const std::string &cipherText, const std::string &priKey)
{
    std::string strRet;
    RSA *rsa = RSA_new();
    BIO *keybio;
    keybio = BIO_new_mem_buf((unsigned char *)priKey.c_str(), -1);

    // 此处有三种方法
    // 1, 读取内存里生成的密钥对，再从内存生成rsa
    // 2, 读取磁盘里生成的密钥对文本文件，在从内存生成rsa
    // 3，直接从读取文件指针生成rsa
    rsa = PEM_read_bio_RSAPrivateKey(keybio, &rsa, NULL, NULL);

    int len = RSA_size(rsa);
    char *decryptedText = (char *)malloc(len + 1);
    memset(decryptedText, 0, len + 1);

    // 解密函数
    int ret = RSA_private_decrypt(cipherText.length(), (const unsigned char*)cipherText.c_str(), (unsigned char*)decryptedText, rsa, RSA_PKCS1_PADDING);
    if (ret >= 0)
        strRet = std::string(decryptedText, ret);

    // 释放内存
    free(decryptedText);
    BIO_free_all(keybio);
    RSA_free(rsa);

    return strRet;
}



int main() {
    SetConsoleOutputCP(65001);

    //generateRsaKey();
    string str = encryptPublicKey();
    string str1 = decryptPrivateKey(str);
    cout << "解密数据: " << str1 << endl;

    cout << string(20, '#') << endl;
    // 原始明文
    string srcText = "sha-256加密";

    string encryptText;
    string encryptHexText;
    string decryptText;

    string strKey[2];
    generateRSAKey(strKey);

    std::cout << "公钥: " << std::endl;
    std::cout << strKey[0] << std::endl;
    std::cout << "私钥： " << std::endl;
    std::cout << strKey[1] << std::endl;
    encryptText = rsa_pub_encrypt(srcText, strKey[0]);
    std::cout << "加密字符： " << std::endl;
    std::cout << encryptText << std::endl;
    decryptText = rsa_pri_decrypt(encryptText, strKey[1]);
    std::cout << "解密字符： " << std::endl;
    std::cout << decryptText << std::endl;std::string key[2];
    generateRSAKey(strKey);
    std::cout << "公钥: " << std::endl;
    std::cout << strKey[0] << std::endl;
    std::cout << "私钥： " << std::endl;
    std::cout << strKey[1] << std::endl;
    encryptText = rsa_pub_encrypt(srcText, strKey[0]);
    std::cout << "加密字符： " << std::endl;
    std::cout << encryptText << std::endl;
    decryptText = rsa_pri_decrypt(encryptText, strKey[1]);
    std::cout << "解密字符： " << std::endl;
    std::cout << decryptText << std::endl;
    return 0;
}