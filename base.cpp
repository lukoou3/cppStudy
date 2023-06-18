#include <iostream>
#include "windows.h"

using namespace std;

void hello_word() {
    cout << "Hello, World!" << endl;
    cout << "输出中文" << endl;
}

void test_limit() {
    // 各个整形类型的最大值
    int n_int = INT_MAX;        // initialize n_int to max int value
    short n_short = SHRT_MAX;   // symbols defined in climits file
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    // sizeof操作符输出类型或者变量的字节数
    // sizeof operator yields size of type or of variable
    cout << "int is " << sizeof(int) << " bytes." << endl;
    cout << "short is " << sizeof n_short << " bytes." << endl;
    cout << "long is " << sizeof n_long << " bytes." << endl;
    cout << "long long is " << sizeof n_llong << " bytes." << endl;
    cout << endl;

    // 输出各个整形类型的最大值
    cout << "Maximum values:" << endl;
    cout << "int: " << n_int << endl;
    cout << "short: " << n_short << endl;
    cout << "long: " << n_long << endl;
    cout << "long long: " << n_llong << endl << endl;

    cout << "Minimum int value = " << INT_MIN << endl;
    cout << "Bits per byte = " << CHAR_BIT << endl;
}

// 整形范围溢出
void test_exceed() {
    short a = SHRT_MAX;
    unsigned short b = a;

    cout << "a:" << a << ",b:" << b << endl;
    a += 1;
    b += 1;
    cout << "after + 1" << endl;
    cout << "a:" << a << ",b:" << b << endl;

    a = 0;
    b = 0;
    a -= 1;
    b -= 1;
    cout << "after 0 - 1" << endl;
    cout << "a:" << a << ",b:" << b << endl;
}

// 16进制、8进制
void test_hexoct() {
    int int10 = 42;     // decimal integer literal
    int int16 = 0x42;   // hexadecimal integer literal
    int int8 = 042;   // octal integer literal

    cout << "int10 = " << int10 << " (42 in decimal)\n";
    cout << "int16 = " << int16 << " (0x42 in hex)\n";
    cout << "int8 = " << int8 << " (042 in octal)\n";
}

// 显示成16进制、8进制
void test_hexoct2() {
    int n = 42;

    cout << "n = " << n << " (decimal for 42)" << endl;
    cout << hex;      // manipulator for changing number base
    cout << "n = " << n << " (hexadecimal for 42)" << endl;
    cout << oct;      // manipulator for changing number base
    cout << "n = " << n << " (octal for 42)" << endl;

    // 恢复显示10进制，否则之后的输出都是8进制格式
    cout << dec;
}

void test_chartype() {
    char ch;        // declare a char variable

    cout << "请输出一个charr: " << endl;
    cin >> ch; // 读取一个char到ch
    cout << "Thank you for the " << ch << " character." << endl;
}


void test_morechar() {
    char ch = 'M';       // assign ASCII code for M to ch
    int i = ch;          // store same code in an int
    cout << "The ASCII code for " << ch << " is " << i << endl;

    cout << "Add one to the character code:" << endl;
    ch = ch + 1;          // change character code in ch
    i = ch;               // save new character code in i
    cout << "The ASCII code for " << ch << " is " << i << endl;

    // cout.put(ch)方法 输出一个char
    // using the cout.put() member function to display a char
    cout << "Displaying char ch using cout.put(ch): ";
    cout.put(ch);

    // using cout.put() to display a char constant
    cout.put('!');

    cout << endl << "Done" << endl;
}

void test_floatnum() {
    cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point
    float tub = 10.0 / 3.0;     // good to about 6 places
    double mint = 10.0 / 3.0;   // good to about 15 places
    const float million = 1.0e6;

    cout << "tub = " << tub;
    cout << ", a million tubs = " << million * tub;
    cout << ",\nand ten million tubs = ";
    cout << 10 * million * tub << endl;

    cout << "mint = " << mint << " and a million mints = ";
    cout << million * mint << endl;
}

void test_float_add() {
    float a = 2.34E+22f;
    float b = a + 1.0f;

    cout << "a = " << a << endl;
    cout << "b - a = " << b - a << endl; // 精度问题
}

// 除法,编译型语言都是这样 int/int = int
void test_divide() {
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << "Integer division: 9/5 = " << 9 / 5 << endl;
    cout << "Floating-point division: 9.0/5.0 = ";
    cout << 9.0 / 5.0 << endl;
    cout << "Mixed division: 9.0/5 = " << 9.0 / 5 << endl;
    cout << "double constants: 1e7/9.0 = ";
    cout << 1.e7 / 9.0 << endl;
    cout << "float constants: 1e7f/9.0f = ";
    cout << 1.e7f / 9.0f << endl;
}

void test_typecast(){
    int auks, bats, coots;

    // the following statement adds the values as double,
    // then converts the result to int
    auks = 19.99 + 11.99;

    // these statements add values as int
    bats = (int) 19.99 + (int) 11.99;   // old C syntax
    coots = int (19.99) + int (11.99);  // new C++ syntax
    cout << "auks = " << auks << ", bats = " << bats;
    cout << ", coots = " << coots << endl;

    char ch = 'Z';
    cout << "The code for " << ch << " is ";    // print as char
    cout << int(ch) << endl;                    // print as int
    cout << "Yes, the code is ";
    cout << static_cast<int>(ch) << endl;       // using static_cast
}

int main() {
    SetConsoleOutputCP(65001);

    //hello_word();
    test_limit();
    //test_exceed();
    //test_hexoct();
    //test_hexoct2();
    //test_chartype();
    //test_morechar();
    //test_floatnum();
    //test_float_add();
    //test_divide();
    //test_typecast();

    return 0;
}
