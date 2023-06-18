#include <iostream>
#include <string>
#include <array>
#include "windows.h"

using namespace std;

void test_forloop() {
    using namespace std;
    int i;  // create a counter
    // initialize; test ; update
    for (i = 0; i < 5; i++)
        cout << "C++ knows loops.\n";
    cout << "C++ knows when to stop.\n";

    for (int j = 0; j < 5; j++) {
        cout << "C++ knows loops.\n";
    }

    cout << "C++ knows when to stop.\n";
}

void test_express() {
    int x;

    // 表达式的值
    cout << "The expression x = 100 has the value ";
    cout << (x = 100) << endl;
    cout << "Now x = " << x << endl;
    cout << "The expression x < 3 has the value ";
    cout << (x < 3) << endl;
    cout << "The expression x > 3 has the value ";
    cout << (x > 3) << endl;
    cout.setf(ios_base::boolalpha);   //a newer C++ feature
    cout << "The expression x < 3 has the value ";
    cout << (x < 3) << endl;
    cout << "The expression x > 3 has the value ";
    cout << (x > 3) << endl;
}

void test_formore() {
    const int ArSize = 16;
    long long factorials[ArSize];
    factorials[1] = factorials[0] = 1LL;
    for (int i = 2; i < ArSize; i++) {
        factorials[i] = i * factorials[i - 1];
    }
    for (int i = 0; i < ArSize; i++) {
        cout << i << "! = " << factorials[i] << endl;
    }
}

void test_step() {
    cout << "Enter an integer: ";
    int by = 10;
    cout << "Counting by " << by << "s:\n";
    for (int i = 0; i < 100; i = i + by)
        cout << i << endl;
}

void test_for_str1() {
    string word = "123456";

    // display letters
    for (int i = 0; i < word.size(); i++)
        cout << word[i];
    cout << "\nBye.\n";

    // display letters in reverse order
    for (int i = word.size() - 1; i >= 0; i--)
        cout << word[i];
    cout << "\nBye.\n";
}

void test_for_str2() {
    string word = "123456789";
    cout << "str:" << word << "\n";

    // c++的string是可以原地修改的
    // physically modify string object
    char temp;
    int i, j;
    for (j = 0, i = word.size() - 1; j < i; --i, ++j) {
        temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
    cout << word << "\nDone\n";
}

void test_for_equal() {
    /**
     * 第一个循环在显示了前5个测验成绩后正确地终止，但第二个循环显示整个数组。更糟糕的是，显示的每个值都是20。
     * 更加糟糕的是，它到了数组末尾还不停止。最糟糕的是，该程序可能导致其他应用程序无法运行，您必须重新启动计算机。
     */
    int quizscores[10] = {20, 20, 20, 20, 20, 19, 20, 18, 20, 20};

    cout << "Doing it right:\n";
    int i;
    for (i = 0; quizscores[i] == 20; i++) {
        cout << "quiz " << i << " is a 20\n";
    }

    // 错误的写法, c++表达式非0都是true
    // Warning: you may prefer reading about this program
    // to actually running it.
    cout << "Doing it dangerously wrong:\n";
    for (i = 0; quizscores[i] = 20; i++) {
        cout << "quiz " << i << " is a 20\n";
    }
}

void test_compare_str() {
    // c语言风格的字符串使用strcmp判断相等, word1是char指针
    char word1[5] = "?ate";

    for (char ch = 'a'; strcmp(word1, "mate"); ch++) {
        cout << word1 << endl;
        word1[0] = ch;
    }
    cout << "After loop ends, word1 is " << word1 << endl;

    // string类可以用==判断相等
    string word2 = "?ate";

    for (char ch = 'a'; word2 != "mate"; ch++) {
        cout << word2 << endl;
        word2[0] = ch;
    }
    cout << "After loop ends, word2 is " << word2 << endl;
}

void test_while() {
    char name[20] = "abcde";
    int i = 0;                  // start at beginning of string
    while (name[i] != '\0')     // process to end of string
    {
        cout << name[i] << ": " << int(name[i]) << endl;
        i++;                    // don't forget this step
    }

    cout << "###################" << endl;
    i = 0;
    // '\0' == 0 == false
    while (name[i]) {
        cout << name[i] << ": " << int(name[i]) << endl;
        i++;
    }
}

void test_do_while() {
    char name[20] = "abcde";
    int i = 0;
    do {
        cout << name[i] << ": " << int(name[i]) << endl;
        i++;
    } while (name[i]);
}

void test_nested() {
    const int Cities = 5;
    const int Years = 4;
    const char *cities[Cities] =   // array of pointers
            {                               // to 5 strings
                    "Gribble City",
                    "Gribbletown",
                    "New Gribble",
                    "San Gribble",
                    "Gribble Vista"
            };

    int maxtemps[Years][Cities] =   // 2-D array
            {
                    {96, 100, 87, 101, 105},   // values for maxtemps[0]
                    {96, 98,  91, 107, 104},   // values for maxtemps[1]
                    {97, 101, 93, 108, 107}, // values for maxtemps[2]
                    {98, 103, 95, 109, 108}   // values for maxtemps[3]
            };

    cout << "Maximum temperatures for 2008 - 2011\n";
    for (int city = 0; city < Cities; ++city) {
        cout << cities[city] << ":\t";
        for (int year = 0; year < Years; ++year)
            cout << maxtemps[year][city] << "\t";
        cout << endl;
    }
}

void test_nested2() {
    const int Cities = 5;
    const int Years = 4;
    const string cities[Cities] =   // array of pointers
            {                               // to 5 strings
                    "Gribble City",
                    "Gribbletown",
                    "New Gribble",
                    "San Gribble",
                    "Gribble Vista"
            };

    array<array<int,Cities>, Years> maxtemps =

            /*   int maxtemps[Years][Cities] =   // 2-D array */
            {
                    96, 100, 87, 101, 105,   // values for maxtemps[0]
                    96, 98, 91, 107, 104,   // values for maxtemps[1]
                    97, 101, 93, 108, 107, // values for maxtemps[2]
                    98, 103, 95, 109, 108   // values for maxtemps[3]
            };


    cout << "Maximum temperatures for 2008 - 2011\n";
    for (int city = 0; city < Cities; ++city)
    {
        cout << cities[city] << ":\t";
        for (int year = 0; year < Years; ++year)
            cout << maxtemps[year][city] << "\t";
        cout << endl;
    }
}

int main() {
    SetConsoleOutputCP(65001);

    //test_forloop();
    //test_express();
    //test_formore();
    //test_step();
    //test_for_str1();
    //test_for_str2();
    //test_for_equal();
    //test_compare_str();
    //test_while();
    //test_do_while();
    test_nested();
    test_nested2();

    return 0;
}
