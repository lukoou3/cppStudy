#include <iostream>
#include "windows.h"

using namespace std;

void test_refer() {
    // 引用是已定义的变量的别名（另一个名称）。
    // 可以把a和ref_a看做完全相同
    int a = 101;
    int &ref_a = a;

    cout << "a = " << a;
    cout << ", ref_a = " << ref_a << endl;
    ref_a++;
    cout << "a = " << a;
    cout << ", ref_a = " << ref_a << endl;

    cout << "a address = " << &a;
    cout << ", ref_a address = " << &ref_a << endl;
}

void swap_value(int a, int b) {
    int temp;
    temp = a;      // use a, b for values of variables
    a = b;
    b = temp;
}

void swap_ref(int &a, int &b) {
    int temp;
    temp = a;       // use a, b for values of variables
    a = b;
    b = temp;
}

void swap_pointer(int *p, int *q) {
    int temp;
    temp = *p;      // use *p, *q for values of variables
    *p = *q;
    *q = temp;
}

void test_refer_args() {
    int wallet1 = 300;
    int wallet2 = 350;

    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Trying to use passing by value:\n";
    swap_value(wallet1, wallet2);   // pass values of variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using references to swap contents:\n";
    swap_ref(wallet1, wallet2);   // pass variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using pointers to swap contents again:\n";
    swap_pointer(&wallet1, &wallet2); // pass addresses of variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;
}

double cube(double a) {
    a *= a * a;
    return a;
}

double refcube(double &ra) {
    ra *= ra * ra;
    return ra;
}

/**
 * refcube( )函数修改了main( )中的x值，而cube( )没有，这提醒我们为何通常按值传递。
 * 变量a位于cube( )中，它被初始化为x的值，但修改a并不会影响x。
 * 但由于refcube( )使用了引用参数，因此修改ra实际上就是修改x。
 * 如果程序员的意图是让函数使用传递给它的信息，而不对这些信息进行修改，同时又想使用引用，则应使用常量引用。
 */
void test_cube() {
    double x = 3.0;

    cout << cube(x);
    cout << " = cube of " << x << endl;
    cout << refcube(x);
    cout << " = cube of " << x << endl;
}

struct person2 {
    string name;
    int age;
};

void show_person(person2 &p) {
    cout << "show_person address:" << &p << ", name:" << p.name << " , age:" << p.age << endl;
}

void set_person(person2 &p) {
    cout << "set_person address:" << &p << endl;
    p.name = "青丝";
    p.age = 17;
}

void test_struct_refer() {
    person2 p = {"莫南", 18};
    show_person(p);
    set_person(p);
    show_person(p);
}


string version1(const string &s1, const string &s2) {
    string temp;
    temp = s2 + s1 + s2;
    return temp;
}

// has side effect
const string &version2(string &s1, const string &s2) {
    s1 = s2 + s1 + s2;
    // safe to return reference passed to function
    return s1;
}

// bad design
const string &version3(string &s1, const string &s2) {
    string temp;
    temp = s2 + s1 + s2;
    // unsafe to return reference to local variable
    return temp;
}

/**
 * 看一个例子，它使用了string类，并演示了一些不同的设计方案，其中的一些是糟糕的。
 * 这个例子的基本思想是，创建一个函数，它将指定的字符串加入到另一个字符串的前面和后面。
 * 提供了三个这样的函数，然而其中的一个存在非常大的缺陷，可能导致程序崩溃甚至不能通过编译。
 */
void test_string_refer() {
    string input;
    string copy;
    string result;

    input = "It's not my fault.";
    copy = input;
    cout << "Your string as entered: " << input << endl;
    result = version1(input, "***");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    result = version2(input, "###");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    cout << "Resetting original string.\n";
    input = copy;
    result = version3(input, "@@@");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;
}

// 函数声明和定义默认参数只能一个加上默认值,建议写在函数声明处,其他人能够看到
int add_with_default(int n, int add = 10);

void test_default_args() {
    int n = 1;
    cout << add_with_default(n) << endl;
    cout << add_with_default(n, 10) << endl;
    cout << add_with_default(n, 100) << endl;
    cout << add_with_default(n, 1000) << endl;
}

int add_with_default(int n, int add) {
    return n + add;
}

void print_line(char *str) {
    printf("%s\n", str);
}

void print_line(int n) {
    printf("%d\n", n);
}

void test_overload() {
    print_line("莫南");
    print_line(18);
}

template<typename T>
void Swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template<typename T>
void Swap(T a[], T b[], int n) {
    T temp;
    for (int i = 0; i < n; i++) {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

void Show(int a[], int n) {
    cout << a[0] << a[1] << "/";
    cout << a[2] << a[3] << "/";
    for (int i = 4; i < n; i++)
        cout << a[i];
    cout << endl;
}

// 就是泛型
void test_func_template() {
    const int Lim = 8;
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap(i, j);              // matches original template
    cout << "Now i, j = " << i << ", " << j << ".\n";

    int d1[Lim] = {0, 7, 0, 4, 1, 7, 7, 6};
    int d2[Lim] = {0, 7, 2, 0, 1, 9, 6, 9};
    cout << "Original arrays:\n";
    Show(d1, Lim);
    Show(d2, Lim);
    Swap(d1, d2, Lim);        // matches new template
    cout << "Swapped arrays:\n";
    Show(d1, Lim);
    Show(d2, Lim);
}

int main() {
    SetConsoleOutputCP(65001);

    //test_refer();
    //test_refer_args();
    //test_cube();
    //test_struct_refer();
    //test_string_refer();
    //test_default_args();
    //test_overload();
    test_func_template();

    return 0;
}
