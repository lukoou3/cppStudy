#include <iostream>
#include "windows.h"
#include <string>

using namespace std;

void test_str(){
    // 使用常规的C-风格字符串初始化
    string one("Lottery Winner!");     // ctor #1
    cout << one << endl;               // overloaded <<
    // 由20个$字符初始化
    string two(20, '$');               // ctor #2
    cout << two << endl;
    // 复制构造函数
    string three(one);                 // ctor #3
    cout << three << endl;
    // 重载的+=运算符将字符串“Oops!”附加到字符串one的后面
    one += " Oops!";                   // overloaded +=
    cout << one << endl;
    // 同样，=运算符也被重载，以便可以将string对象、C-风格字符串或char值赋给string对象
    two = "Sorry! That was ";
    // 重载[ ]运算符，可以直接修改字符串
    three[0] = 'P';
    // 默认构造函数创建一个以后可对其进行赋值的空字符串
    string four;                       // ctor #4
    // 使用重载的+运算符创建了一个临时string对象，然后使用重载的=运算符将它赋给对象four。正如所预料的，+运算符将其两个操作数组合成一个string对象。该运算符被多次重载，以便第二个操作数可以是string对象、C-风格字符串或char值。
    four = two + three;                // overloaded +, =
    cout << four << endl;
    char alls[] = "All's well that ends well";
    // 构造函数将一个C-风格字符串和一个整数作为参数，其中的整数参数表示要复制多少个字符
    string five(alls,20);              // ctor #5
    cout << five << "!\n";
    // start,end指针构造函数，[start, end]
    string six(alls+6, alls + 10);     // ctor #6
    cout << six  << ", ";
    // 也是指针地址
    string seven(&five[6], &five[10]); // ctor #6 again
    cout << seven << "...\n";
    // 将一个string对象的部分内容复制到构造的对象中
    string eight(four, 7, 16);         // ctor #7
    cout << eight << " in motion!" << endl;

    // 返回c风格的字符串
    eight.c_str();
}

void test_str_find(){
    string str = "aa_11bb_cc33_11bb";
    string substr = "11bb";
    // 查找子字符串
    auto i = str.find("11bb");
    cout << i << endl;
    cout << str.find(substr) << endl;
    i = str.find("11bbcc");
    cout << i << endl;
    cout << "npos:" << string::npos << endl;
    cout << "--------find_first_of---------" << endl;
    // 查找任一字符
    cout << str.find_first_of("abc") << endl;
    cout << str.find_first_of("bcd") << endl;
    cout << str.find_first_of("xyz") << endl;
}

void test_str_capacity(){
    // 底层数组结构类似arrayList，容量不足会扩容，c++的string不像其他语言是不可变的类型
    string empty;
    string small = "bit";
    string larger = "Elephants are a girl's best friend";
    cout << "Sizes:\n";
    cout << "\tempty: " << empty.size() << endl;
    cout << "\tsmall: " << small.size() << endl;
    cout << "\tlarger: " << larger.size() << endl;
    cout << "Capacities:\n";
    cout << "\tempty: " << empty.capacity() << endl;
    cout << "\tsmall: " << small.capacity() << endl;
    cout << "\tlarger: " << larger.capacity() << endl;
    empty.reserve(50);
    cout << "Capacity after empty.reserve(50): " << empty.capacity() << endl;
}

int main() {
    SetConsoleOutputCP(65001);

    //test_str();
    //test_str_find();
    test_str_capacity();

    return 0;
}