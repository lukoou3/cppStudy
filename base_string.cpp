#include <iostream>
#include "windows.h"

using namespace std;

void test_strings() {
    const int Size = 15;
    char name1[Size];               // empty array
    char name2[Size] = "C++owboy";  // initialized array

    cout << "Howdy! I'm " << name2;
    cout << "! What's your name?\n";
    cin >> name1; // 读取字符串到字符数组
    cout << "Well, " << name1 << ", your name has ";
    cout << strlen(name1) << " letters and is stored\n";
    cout << "in an array of " << sizeof(name1) << " bytes.\n";
    cout << "Your initial is " << name1[0] << ".\n";
    name2[3] = '\0';                // set to null character
    cout << "Here are the first 3 characters of my name: ";
    cout << name2 << endl;
}

// c字符串和string类操作对比
void test_str_type() {
    char charr1[20];
    char charr2[20] = "jaguar";
    string str1;
    string str2 = "panther";

    // assignment for string objects and character arrays
    str1 = str2;                // copy str2 to str1
    strcpy(charr1, charr2);     // copy charr2 to charr1

    // appending for string objects and character arrays
    str1 += " paste";           // add paste to end of str1
    strcat(charr1, " juice");   // add juice to end of charr1

    // finding the length of a string object and a C-style string
    int len1 = str1.size();     // obtain length of str1
    int len2 = strlen(charr1);  // obtain length of charr1

    cout << "The string " << str1 << " contains " << len1 << " characters.\n";
    cout << "The string " << charr1 << " contains " << len2 << " characters.\n";
}

// 可以使用cin和运算符>>来将输入存储到string对象中，使用cout和运算符<<来显示string对象，其句法与处理C-风格字符串相同。
// 但每次读取一行而不是一个单词时，使用的句法不同
void test_str_type2() {
    char char_str[20];
    string str;

    cout << "输入之前char_str字符串的长度: " << strlen(char_str) << endl;
    cout << "输入之前str字符串的长度: " << str.size() << endl;
    cout << "输入一行字符串enter结束:\n";
    cin.getline(char_str, 20);     // indicate maximum length
    cout << "You entered: " << char_str << endl;
    cout << "输入另外一行字符:\n";
    getline(cin, str);          // cin now an argument; no length specifier
    cout << "You entered: " << str << endl;
    cout << "输入之后char_str字符串的长度: " << strlen(char_str) << endl;
    cout << "输入之后str字符串的长度: " << str.size() << endl;
}

void test_raw_str() {
    string str1 = R"(
    {
        "name": "Judd Trump",
        "credits": 1754500,
        "ranking": 1
    }
)";
    char *str2 = R"(
    {
        "name": "Judd Trump",
        "credits": 1754500,
        "ranking": 1
    }
)";
    cout << str1 << endl;
    string line(20, '#');
    cout << line << endl;
    cout << str2 << endl;
    cout << line << endl;
    string str3 = R"NOT_PRINT_FLAG(
    {
        "name": "Judd Trump",
        "credits": 1754500,
        "ranking": "(1)"
    }
)NOT_PRINT_FLAG";
    cout << str3 << endl;
    // delim是自定义字符
    string str4 = R"delim(
    {
        "name": "Judd Trump",
        "credits": 1754500,
        "ranking": "(1)"
    }
)delim";
    cout << str4 << endl;
}

int main() {
    SetConsoleOutputCP(65001);

    //test_strings();
    //test_str_type();
    //test_str_type2();
    test_raw_str();

    return 0;
}
