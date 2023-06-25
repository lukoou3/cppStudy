#include <iostream>
#include <functional>

using namespace std;

int add(int x, int y){
    return x + y;
}

void test_func1(int (*func)(int, int)){
    for (int i = 0; i < 10; ++i) {
        int v = func(10, i);
        cout << i << ":" << v << endl;
    }
}

void test_func2(function<int(int, int)> func){
    for (int i = 0; i < 10; ++i) {
        int v = func(10, i);
        cout << i << ":" << v << endl;
    }
}

int main() {
    test_func1(add);
    cout << "-----------------"  << '\n';
    test_func2(add);
    cout << "-----------------"  << '\n';
    test_func1([](int a, int b) { return a + b; });
    cout << "-----------------"  << '\n';
    test_func2([](int a, int b) { return a + b; });
    cout << "-----------------"  << '\n';
    int cnt = 100;
    // 函数指针没法使用闭包
    //test_func1([&cnt](int a, int b) { return a + b + cnt; });
    test_func2([&cnt](int a, int b) { return a + b + cnt; });
    cout << "-----------------"  << '\n';
    auto func = [&cnt](int a, int b) { return a + b + cnt; };
    test_func2(func);
    cout << "-----------------"  << '\n';
    cnt = 200;
    test_func2(func);
}