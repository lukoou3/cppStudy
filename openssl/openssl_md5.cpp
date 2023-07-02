#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "windows.h"
#include "openssl/md5.h"

using namespace std;

// ---- md5摘要哈希 ---- //
void md5(const string &srcStr, string &encodedStr, string &encodedHexStr) {
    // 调用md5哈希
    unsigned char mdStr[17] = {0};
    MD5((const unsigned char *)srcStr.c_str(), srcStr.length(), mdStr);

    cout << "mdStr:" << mdStr << strlen((const char *)mdStr) << endl;

    // 哈希后的字符串
    encodedStr = string((const char *)mdStr);
    // 哈希后的十六进制串 32字节
    char buf[33] = {0};
    char tmp[3] = {0};
    for (int i = 0; i < 16; i++) {
        sprintf(tmp, "%02x", mdStr[i]);
        strcat(buf, tmp);
    }
    buf[32] = '\0'; // 后面都是0，从32字节截断
    encodedHexStr = string(buf);
}

void test_md5() {
    // 原始明文
    string srcText = "md5加密";

    string encryptText;
    string encryptHexText;

    cout << "=== text ===" << endl;
    cout << srcText << endl;

    // md5
    cout << "=== md5 ===" << endl;
    md5(srcText, encryptText, encryptHexText);
    cout << "=== md5 rst: ===" << endl;
    cout << encryptText << endl;
    cout << "=== hex rst: ===" << endl;
    cout << encryptHexText << endl;
}

void getMD5(const char* str, char* result) {
    MD5_CTX ctx;
    // 初始化
    MD5_Init(&ctx);
    // 添加数据
    MD5_Update(&ctx, str, strlen(str));
    // 计算结果
    unsigned char md[16] = { 0 };
    MD5_Final(md, &ctx);
    for (int i = 0; i < 16; ++i) {
        sprintf(&result[i * 2], "%02x", md[i]);
    }
}

void test_getMD5() {
    char result[33] = { 0 };
    getMD5("md5加密", result);
    printf("md5 value: %s\n", result);
}

int main(){
    SetConsoleOutputCP(65001);
    test_md5();
    cout << string(20, '#') << endl;
    test_getMD5();
    return 0;
}
