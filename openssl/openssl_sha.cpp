#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "windows.h"
#include "openssl/sha.h"

using namespace std;

// ---- sha256摘要哈希 ---- //
void sha256(const std::string &srcStr, std::string &encodedStr, std::string &encodedHexStr){
    // 调用sha256哈希
    unsigned char mdStr[33] = {0};
    SHA256((const unsigned char *)srcStr.c_str(), srcStr.length(), mdStr);

    // 哈希后的字符串
    encodedStr = std::string((const char *)mdStr);
    // 哈希后的十六进制串 32字节
    char buf[65] = {0};
    char tmp[3] = {0};
    for (int i = 0; i < 32; i++)
    {
        sprintf(tmp, "%02x", mdStr[i]);
        strcat(buf, tmp);
    }
    buf[65] = '\0'; // 后面都是0，从32字节截断
    encodedHexStr = std::string(buf);
}

void test_sha256(){
    // 原始明文
    string srcText = "sha-256加密";

    string encryptText;
    string encryptHexText;

    cout << "=== text ===" << endl;
    cout << srcText << endl;

    std::cout << "=== sha256哈希 ===" << std::endl;
    sha256(srcText, encryptText, encryptHexText);
    std::cout << "摘要字符： " << encryptText << std::endl;
    std::cout << "摘要串： " << encryptHexText << std::endl;
}

void sha1Test()
{
    // 1. 初始化
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    // 2. 添加数据
    SHA256_Update(&ctx, "sha-256加密", strlen("sha-256加密"));
    // 3. 哈希计算
    unsigned char* md = new unsigned char[SHA256_DIGEST_LENGTH];
    char* res = new char[SHA256_DIGEST_LENGTH*2 + 1];
    SHA256_Final(md, &ctx);
    // 4. 格式转换
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
    {
        sprintf(&res[i * 2], "%02x", md[i]);
    }
    cout << "sha256: " << res << endl;
}

int main(){
    SetConsoleOutputCP(65001);
    test_sha256();
    cout << string(20, '#') << endl;
    sha1Test();
    return 0;
}
