#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "windows.h"
#include "openssl/aes.h"
#include "../base64/base64.h"

using namespace std;

// 测试对称加密，这个没padding有点问题
void aesCBCCrypto() {
    // 1. 准备数据
    const char *pt = "AES加密";
    // 2. 准备秘钥
    const char *key = "fd6b639dbcff0c2a";
    // 3. 初始化秘钥
    AES_KEY encKey;
    AES_set_encrypt_key((const unsigned char *) key, 128, &encKey);
    // 4. 加密
    // 计算长度
    int length = 0;
    int len = strlen((char *) pt);
    if (len % 16 != 0) {
        length = ((len / 16) + 1) * 16;
    } else {
        length = len;
    }
    for (int i = 0; i < len; ++i) {
        printf("%d,", (unsigned char)pt[i]);
    }
    cout  << endl;

    unsigned char *out = new unsigned char[length + 1];
    char *ivecs = "77b07a672d57d64c";
    unsigned char ivec[AES_BLOCK_SIZE];
    //memset(ivec, 9, sizeof(ivec));
    for (int i = 0; i < AES_BLOCK_SIZE; ++i) {
        ivec[i] = ivecs[i];
    }
    // 密文存储在out中
    AES_cbc_encrypt((const unsigned char *) pt, out, length, &encKey, (unsigned char *)ivec, AES_ENCRYPT);

    for (int i = 0; i < length; ++i) {
        printf("%d,", out[i]);
    }
    cout  << endl;
    out[length] = 0;
    string encoded = base64_encode((char *)out);
    cout << encoded << endl;
    cout << base64_decode(encoded) << endl;

    // 5. 解密
    unsigned char *data = new unsigned char[length];
    AES_KEY deckey;
    for (int i = 0; i < AES_BLOCK_SIZE; ++i) {
        ivec[i] = ivecs[i];
    }
    AES_set_decrypt_key((const unsigned char *) key, 128, &deckey);
    AES_cbc_encrypt(out, data, length, &deckey, (unsigned char *)ivec, AES_DECRYPT);
    // 6. 打印
    cout << "data:" << data << endl;

    delete[]out;
    delete[]data;
}

// AES加密，没问题和python、java输出一样
std::string aes_encode(std::string& data, std::string& passwd)
{


    int dataLen = data.length();
    int nPadd = AES_BLOCK_SIZE - dataLen % AES_BLOCK_SIZE;    //pkcs7padding,缺N位就补N个N
    data.append(size_t(nPadd), char(nPadd));

    dataLen = data.length();                                 //补齐之后的数据长度
    unsigned char ivb[AES_BLOCK_SIZE];           			   //一般16位，关于IV这里用的是全‘0’填充
    char *ivecs = "77b07a672d57d64c";
    for (int i = 0; i < AES_BLOCK_SIZE; ++i) {
        ivb[i] = ivecs[i];
    }
    //memset(&ivb, '0', AES_BLOCK_SIZE);		//有兴趣增加密码安全的可以置换或者随机IV随加密结果输出
    unsigned char buf[dataLen];
    memset(&buf, 0, dataLen);

    AES_KEY key;
    AES_set_encrypt_key((unsigned const char *)(passwd.c_str()), 128, &key);       //*8 int bit 设置密钥

    AES_cbc_encrypt((unsigned const char *)(data.c_str()), buf, dataLen, &key, &(ivb[0]), AES_ENCRYPT);
    //enc： 加密/解密模式，AES_ENCRYPT，加密；AES_DECRYPT，解密；

    for (int i = 0; i < dataLen; ++i) {
        printf("%d,", buf[i]);
    }
    cout  << endl;

    auto base64Out = base64_encode(buf, dataLen);				//这个不是加密过程，普通base64


    return base64Out;
}

int main() {
    SetConsoleOutputCP(65001);
    aesCBCCrypto();
    cout << string(20, '#') << endl;
    string pt = "AES加密";
    string key = "fd6b639dbcff0c2a";
    string  out = aes_encode(pt, key);
    cout << out << endl;
    return 0;
}
