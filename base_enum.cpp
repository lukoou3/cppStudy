#include <iostream>
#include "windows.h"

using namespace std;

enum color{red, yellow, blue};

void test_enum(){
    color c;
    c = red;
    // c++中enum可以转为int
    cout << c << "," << yellow << "," << blue << endl;
    int n = c;
    cout << n << endl;
}

// 显式地设置枚举量的值
enum color2{red2=1, yellow2=3, blue2=5};

void test_enum2(){
    color2 c;
    c = red2;
    // c++中enum可以转为int
    cout << c << "," << yellow2 << "," << blue2 << endl;
    int n = c;
    cout << n << endl;
}

int main() {
    SetConsoleOutputCP(65001);

    //test_enum();
    test_enum2();

    return 0;
}