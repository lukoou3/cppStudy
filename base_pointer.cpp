#include <iostream>
#include "windows.h"

using namespace std;

void test_pointer() {
    int updates = 6;        // declare a variable
    int *p_updates;        // declare pointer to an int

    p_updates = &updates;   // assign address of int to pointer

    // 两种方式获取值
    // express values two ways
    cout << "Values: updates = " << updates;
    cout << ", *p_updates = " << *p_updates << endl;

    // 两种方式获取地址
    // express address two ways
    cout << "Addresses: &updates = " << &updates;
    cout << ", p_updates = " << p_updates << endl;

    // 用指针修改值
    // use pointer to change value
    *p_updates = *p_updates + 1;
    cout << "Now updates = " << updates << endl;
}

void test_pointer_use_new() {
    int nights = 1001;
    int *pt = new int;         // allocate space for an int
    *pt = 1001;                 // store a value there

    cout << "nights value = " << nights << ": location " << &nights << endl;
    cout << "int value = " << *pt << ": location = " << pt << endl;

    double *pd = new double;   // allocate space for a double
    *pd = 10000001.0;           // store a double there

    cout << "double " << "value = " << *pd << ": location = " << pd << endl;
    cout << "location of pointer pt: " << &pt << endl;
    cout << "location of pointer pd: " << &pd << endl;
    cout << "size of pt = " << sizeof(pt) << endl;
    cout << ": size of *pt = " << sizeof(*pt) << endl;
    cout << "size of pd = " << sizeof pd;
    cout << ": size of *pd = " << sizeof(*pd) << endl;

    delete pt;
    delete pd;
}

void test_var_address() {
    int a = 1;
    int b = 1;
    int c = 1;
    cout << "a location: " << &a << endl;
    cout << "b location: " << &b << endl;
    cout << "c location: " << &c << endl;
    cout << "a pointer size: " << sizeof &a << endl;
    cout << "b pointer size: " << sizeof &b << endl;
    cout << "c pointer size: " << sizeof &c << endl;

    int * array_p[3];
    array_p[0] = &a;
    array_p[1] = &b;
    array_p[2] = &c;
    cout << "array_p[0] location: " << &array_p[0] << endl;
    cout << "array_p[1] location: " << &array_p[1] << endl;
    cout << "array_p[2] location: " << &array_p[2] << endl;
}

void test_new_array() {
    double *p3 = new double[3]; // space for 3 doubles
    p3[0] = 0.2;                  // treat p3 like an array name
    p3[1] = 0.5;
    p3[2] = 0.8;

    cout << "p3[1] is " << p3[1] << ".\n";

    // 指针位置增加
    p3 = p3 + 1;                  // increment the pointer
    cout << "Now p3[0] is " << p3[0] << " and ";
    cout << "p3[1] is " << p3[1] << ".\n";

    // 指针位置返回数组开头
    p3 = p3 - 1;                  // point back to beginning

    // 释放数组内存
    delete[] p3;                 // free the memory
    //delete p3; //错误的写法, 数组释放必须是delete [] var;
}

void test_address_pointer() {
    double wages[3] = {10000.0, 20000.0, 30000.0};
    short stacks[3] = {3, 2, 1};

    // 数组名就是数组的地址，也是数组第一个元素的地址
    // Here are two ways to get the address of an array
    double *pw = wages;     // name of an array = address
    short *ps = &stacks[0]; // or use address operator

    // 通过指针获取wages数组元素
    // with array element
    cout << "通过指针获取wages数组元素\n";
    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    pw = pw + 1;
    cout << "add 1 to the pw pointer:\n";
    cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";

    // 通过指针获取stacks数组元素
    cout << "通过指针获取stacks数组元素\n";
    cout << "ps = " << ps << ", *ps = " << *ps << endl;
    ps = ps + 1;
    cout << "add 1 to the ps pointer:\n";
    cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";

    // 数组元素可以通过下标和指针方式访问
    cout << " 数组元素可以通过下标和指针方式访问\n";
    cout << "access two elements with array notation\n";
    cout << "stacks[0] = " << stacks[0] << ", stacks[1] = " << stacks[1] << endl;
    cout << "access two elements with pointer notation\n";
    cout << "*stacks = " << *stacks << ", *(stacks + 1) =  " << *(stacks + 1) << endl;

    // 数组名的大小是数组的大小, 数组指针的大小是指针的大小(4或8)
    cout << "数组名的大小, 数组指针的大小\n";
    cout << sizeof(wages) << " = size of wages array\n";
    cout << sizeof(pw) << " = size of pw pointer\n";
    cout << sizeof(ps) << " = size of ps pointer\n";
}

void test_address_str() {
    char animal[20] = "bear";   // animal holds bear
    const char * bird = "wren"; // bird holds address of string
    char * ps;                  // uninitialized

    cout << animal << " and ";  // display bear
    cout << bird << "\n";       // display wren
    // cout << ps << "\n";      //may display garbage, may cause a crash

    cout << "Enter a kind of animal: ";
    cin >> animal;              // ok if input < 20 chars
    // cin >> ps; Too horrible a blunder to try; ps doesn't
    //            point to allocated space

    ps = animal;                // set ps to point to string
    cout << ps << "!\n";       // ok, same as using animal
    cout << "Before using strcpy():\n";
    cout << animal << " at " << (int *) animal << endl;
    cout << ps << " at " << (int *) ps << endl;

    ps = new char[strlen(animal) + 1];  // get new storage
    strcpy(ps, animal);         // copy string to new storage
    cout << "After using strcpy():\n";
    cout << animal << " at " << (int *) animal << endl;
    cout << ps << " at " << (int *) ps << endl;
    delete [] ps;
}

int main() {
    SetConsoleOutputCP(65001);

    //test_pointer();
    //test_pointer_use_new();
    //test_var_address();
    //test_new_array();
    //test_address_pointer();
    test_address_str();


    return 0;
}