#include <iostream>
#include "windows.h"

using namespace std;

// displays c n times
void n_chars(char c, int n) {
    while (n-- > 0)         // continue until n reaches 0
        cout << c;
}

void test_func_call() {
    n_chars('n', 30);
}

// 函数传入array, 需要传入数组长度
// return the sum of an integer array
int sum_arr(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++)
        total = total + arr[i];
    return total;
}

void test_func_array1() {
    const int ArSize = 8;
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};

    int sum = sum_arr(cookies, ArSize);
    cout << "Total cookies eaten: " << sum << "\n";
}

// return the sum of an integer array
int sum_arr2(int arr[], int n) {
    int total = 0;
    cout << arr << " = arr, ";
    cout << sizeof arr << " = sizeof arr\n";

    for (int i = 0; i < n; i++)
        total = total + arr[i];
    return total;
}

void test_func_array2() {
    const int ArSize = 8;
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};

    cout << cookies << " = array address, ";

    cout << sizeof cookies << " = sizeof cookies\n";
    int sum = sum_arr2(cookies, ArSize);
    cout << "Total cookies eaten: " << sum << endl;
    sum = sum_arr2(cookies, 3);        // a lie
    cout << "First three eaters ate " << sum << " cookies.\n";
    sum = sum_arr2(cookies + 4, 4);    // another lie
    cout << "Last four eaters ate " << sum << " cookies.\n";
}

int fill_array(double ar[], int limit) {
    int i;
    for (i = 0; i < limit; i++) {
        ar[i] = 1000 * (i + 1);
    }
    return i;
}

// the following function can use, but not alter,
// the array whose address is ar
void show_array(const double ar[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Property #" << (i + 1) << ": $";
        cout << ar[i] << endl;
    }
}

// multiplies each element of ar[] by r
void revalue(double r, double ar[], int n) {
    for (int i = 0; i < n; i++)
        ar[i] *= r;
}

void test_func_array3() {
    const int Max = 5;
    double properties[Max];

    int size = fill_array(properties, Max);
    show_array(properties, size);
    cout << endl;
    double factor = 0.8;
    revalue(factor, properties, size);
    show_array(properties, size);
}

// return the sum of an integer array
int sum_arr(const int *begin, const int *end) {
    const int *pt;
    int total = 0;

    for (pt = begin; pt != end; pt++)
        total = total + *pt;
    return total;
}

void test_func_array4() {
    const int ArSize = 8;
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};

    int sum = sum_arr(cookies, cookies + ArSize);
    cout << "Total cookies eaten: " << sum << endl;
    sum = sum_arr(cookies, cookies + 3);        // first 3 elements
    cout << "First three eaters ate " << sum << " cookies.\n";
    sum = sum_arr(cookies + 4, cookies + 8);    // last 4 elements
    cout << "Last four eaters ate " << sum << " cookies.\n";
}

// this function counts the number of ch characters in the string str
unsigned int c_in_str(const char *str, char ch) {
    unsigned int count = 0;

    // quit when *str is '\0'
    while (*str) {
        if (*str == ch)
            count++;
        str++; // move pointer to next char
    }
    return count;
}

void test_func_str_args() {
    char mmm[15] = "minimum";    // string in an array
    char *wail = "ululate";    // wail points to string

    // 传入函数的都是const char *, const限制函数不能修改字符串
    unsigned int ms = c_in_str(mmm, 'm');
    unsigned int us = c_in_str(wail, 'u');
    cout << ms << " m characters in " << mmm << endl;
    cout << us << " u characters in " << wail << endl;
}

// builds string made of n c characters
char *buildstr(char c, int n) {
    char *pstr = new char[n + 1];
    pstr[n] = '\0';         // terminate string
    while (n-- > 0)
        pstr[n] = c;        // fill rest of string
    return pstr;
}

void test_func_str_back() {
    char ch = 'M';
    int times = 46;

    char *ps = buildstr(ch, times);
    cout << ps << endl;
    delete[] ps;                   // free memory
    ps = buildstr('+', 20);         // reuse pointer
    cout << ps << "-DONE-" << ps << endl;
    delete[] ps;                   // free memory
}

struct person {
    char name[20];
    int age;
};

void show_person(person p) {
    cout << "address:" << &p << ", name:" << p.name << " , age:" << p.age << endl;
}

void test_func_struct_args() {
    person p1 = {"莫南", 18};
    person p2 = {"青丝", 16};
    cout << "address:" << &p1 << endl;
    show_person(p1);
    cout << "address:" << &p2 << endl;
    show_person(p2);
}

void show_person(const person *p) {
    cout << "address:" << p << ", name:" << p->name << " , age:" << p->age << endl;
}

void test_func_struct_address_args() {
    person p1 = {"莫南", 18};
    person p2 = {"青丝", 16};
    cout << "address:" << &p1 << endl;
    show_person(&p1);
    cout << "address:" << &p2 << endl;
    show_person(&p2);
}

void display(const string strs[], int n){
    for (int i = 0; i < n; i++)
        cout << i + 1 << ": " << strs[i] << endl;
}

/**
 * 虽然C-风格字符串和string对象的用途几乎相同，但与数组相比，string对象与结构更相似。
 * 例如，可以将一个结构赋给另一个结构，也可以将一个对象赋给另一个对象。
 * 可以将结构作为完整的实体传递给函数，也可以将对象作为完整的实体进行传递。
 * 如果需要多个字符串，可以声明一个string对象数组，而不是二维char数组。
 */
void test_func_string_array() {
    const int SIZE = 5;
    string list[SIZE];
    list[0] = "莫南";
    list[1] = "青丝";
    list[2] = "流沙";
    list[3] = "璇音";
    list[4] = "夕也";

    display(list, SIZE);
}

unsigned long long factorial(unsigned long long n) {
    if(n == 1){
        return 1;
    }

    return n * factorial(n- 1);
}

void test_func_recursion() {
    for (int i = 1; i <= 10; ++i) {
        cout << i << "!:" << factorial(i) << endl;
    }
}

int add10(int n) {
    return n + 10;
}

int add20(int n) {
    return n + 20;
}

int exec_add(int n, int add(int)){
    cout << "exec_add func address:" << (int *)add << endl;
    return add(n);
}

// int add(int)和int (*add)(int) 都是传入的函数指针
int exec_add2(int n, int (*add)(int)){
    cout << "exec_add2 func address:" << (int *)add << endl;
    return add(n);
}

void test_func_pointer() {
    int n = 1;
    cout << "add10:" << exec_add(n, add10) << endl;
    cout << "add10:" << exec_add2(n, add10) << endl;
    cout << "add20:" << exec_add(n, add20) << endl;
    cout << "add20:" << exec_add2(n, add20) << endl;
}

int main() {
    SetConsoleOutputCP(65001);

    //test_func_call();
    //test_func_array1();
    //test_func_array2();
    //test_func_array3();
    //test_func_array4();
    //test_func_str_args();
    //test_func_str_back();
    //test_func_struct_args();
    //test_func_struct_address_args();
    //test_func_string_array();
    //test_func_recursion();
    test_func_pointer();

    return 0;
}
