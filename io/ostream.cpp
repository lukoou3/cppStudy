#include <iostream>
#include <cstring>  // or else string.h

using namespace std;

void test_write() {
    /**
     * 除了各种operator<<( )函数外，ostream类还提供了put( )方法和write( )方法，前者用于显示字符，后者用于显示字符串。
     * 有些编译器可能指出该程序定义了数组state1和state3但没有使用它们。这不是什么问题，因为这两个数组只是用于提供数组state2前面和后面的数据，以便您知道程序错误地存取state2时发生的情况。
     *
     * 还需要注意的是，write( )方法并不会在遇到空字符时自动停止打印字符，而只是打印指定数目的字符，即使超出了字符串的边界！
     * 在这个例子中，在字符串“kansas”的前后声明了另外两个字符串，以便相邻的内存包含数据。
     * 编译器在内存中存储数据的顺序以及调整内存的方式各不相同。例如，“Kansas”占用6字节，而该编译器使用4字节的倍数调整字符串，因此“Kansas”被填充成占用8字节。
     * 由于编译器之间的差别，因此输出的最后一行可能不同。
     */
    const char *state1 = "Florida";
    const char *state2 = "Kansas";
    const char *state3 = "Euphoria";
    int len = std::strlen(state2);
    cout << "Increasing loop index:\n";
    int i;
    for (i = 1; i <= len; i++) {
        cout.write(state2, i);
        cout << endl;
    }

    // concatenate output
    cout << "Decreasing loop index:\n";
    for (i = len; i > 0; i--)
        cout.write(state2, i) << endl;

    // exceed string length
    cout << "Exceeding string length:\n";
    cout.write(state2, len + 5) << endl;
}

int main() {
    test_write();


    return 0;
}