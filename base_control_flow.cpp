#include <iostream>
#include "windows.h"

using namespace std;


void test_if() {
    char ch;
    int spaces = 0;
    int total = 0;
    string str = "ab cd ef.hi";

    int i = 0;
    ch = str[i];
    while (ch != '.')   // quit at end of sentence
    {
        if (ch == ' ')  // check if ch is a space
            ++spaces;
        ++total;        // done every time
        ++i;
        ch = str[i];
    }
    cout << spaces << " spaces, " << total;
    cout << " characters total in sentence\n";
}

void test_ifelse() {
    char ch;

    string str = "abcd\nefhi.jk";
    cout << str << endl;
    int i = 0;
    ch = str[i];
    while (ch != '.') {
        if (ch == '\n')
            cout << ch;     // done if newline
        else
            cout << ++ch;   // done otherwise
        ++i;
        ch = str[i];
    }
}

void test_ifelseif() {
    const int Fave = 27;
    int n;

    int nums[] = {50, 25, 37, 31, 28, 27, 26, 21};
    int i = 0;

    cout << "Enter a number in the range 1-100 to find ";
    cout << "my favorite number: \n";
    do {
        //cin >> n;
        n = nums[i];
        cout << "in " << n << "\n";
        if (n < Fave)
            cout << "Too low -- guess again: \n";
        else if (n > Fave)
            cout << "Too high -- guess again: \n";
        else
            cout << Fave << " is right!\n";
        i++;
    } while (n != Fave);
}

void test_or() {
    cout << "This program may reformat your hard disk\n"
            "and destroy all your data.\n"
            "Do you wish to continue? <y/n> ";
    char ch;
    cin >> ch;
    if (ch == 'y' || ch == 'Y')             // y or Y
        cout << "You were warned!\a\a\n";
    else if (ch == 'n' || ch == 'N')        // n or N
        cout << "A wise choice ... bye\n";
    else
        cout << "That wasn't a y or n! Apparently you "
                "can't follow\ninstructions, so "
                "I'll trash your disk anyway.\a\a\a\n";
}

void test_and() {
    const char *qualify[4] =       // an array of pointers to strings
            {
                    "10,000-meter race.\n",
                    "mud tug-of-war.\n",
                    "masters canoe jousting.\n",
                    "pie-throwing festival.\n"
            };
    int age;
    cout << "Enter your age in years: ";
    //cin >> age;
    age = 35;
    cout << age;
    int index;

    if (age > 17 && age < 35)
        index = 0;
    else if (age >= 35 && age < 50)
        index = 1;
    else if (age >= 50 && age < 65)
        index = 2;
    else
        index = 3;

    cout << "\nYou qualify for the " << qualify[index];
}

bool is_int(double x) {
    if (x <= INT_MAX && x >= INT_MIN)   // use climits values
        return true;
    else
        return false;
}

void test_not() {
    double nums[] = {6666666666, -80000000000, 9999, 21};
    int i = 0;

    double num;

    cout << "Yo, dude! Enter an integer value: ";
    //cin >> num;
    num = nums[i];
    cout << num << "\n";

    while (!is_int(num))    // continue while num is not int-able
    {
        cout << "Out of range -- please try again: ";
        //cin >> num;
        i++;
        num = nums[i];
        cout << num << "\n";
    }
    int val = int(num);    // type cast
    cout << "You've entered the integer " << val << "\nBye\n";
}

void test_cctypes() {
    cout << "Enter text for analysis, and type @"
            " to terminate input.\n";
    char ch;
    int whitespace = 0;
    int digits = 0;
    int chars = 0;
    int punct = 0;
    int others = 0;

    cin.get(ch);                // get first character
    while (ch != '@')            // test for sentinel
    {
        // 如果是字母，该函数返回true
        if (isalpha(ch))         // is it an alphabetic character?
            chars++;
            // 如果是空格制表符回车等空白字符，该函数返回true
        else if (isspace(ch))    // is it a whitespace character?
            whitespace++;
            // 数字
        else if (isdigit(ch))    // is it a digit?
            digits++;
            // 标点符号
        else if (ispunct(ch))    // is it punctuation?
            punct++;
        else
            others++;
        cin.get(ch);            // get next character
    }
    cout << chars << " letters, "
         << whitespace << " whitespace, "
         << digits << " digits, "
         << punct << " punctuations, "
         << others << " others.\n";
}

void test_condit() {
    int a, b;
    cout << "Enter two integers: ";
    //cin >> a >> b;
    a = 10;
    b = 20;
    cout << a << " " << b;
    cout << "\nThe larger of " << a << " and " << b;
    // 三目表达式
    int c = a > b ? a : b;   // c = a if a > b, else c = b
    cout << " is " << c << endl;
}

void test_switch() {
    int choice = 3;
    switch (choice) {
        case 1:
            cout << "case 1" << endl;
            break;
        case 2:
            cout << "case 2" << endl;
            break;
        case 3:
            cout << "case 3" << endl;
            break;
        case 4:
            cout << "case 4" << endl;
            break;
        case 5:
            cout << "case 5" << endl;
            break;
        default:
            cout << "case other" << endl;
            break;
    }
}

// create named constants for 0 - 6
enum {
    red, orange, yellow, green, blue, violet, indigo
};

// 将枚举量用作标签
void test_enum() {
    cout << "Enter color code (0-6): ";
    int code;
    cin >> code;
    while (code >= red && code <= indigo) {
        switch (code) {
            case red     :
                cout << "Her lips were red.\n";
                break;
            case orange  :
                cout << "Her hair was orange.\n";
                break;
            case yellow  :
                cout << "Her shoes were yellow.\n";
                break;
            case green   :
                cout << "Her nails were green.\n";
                break;
            case blue    :
                cout << "Her sweatsuit was blue.\n";
                break;
            case violet  :
                cout << "Her eyes were violet.\n";
                break;
            case indigo  :
                cout << "Her mood was indigo.\n";
                break;
        }
        cout << "Enter color code (0-6): ";
        cin >> code;
    }
    cout << "Bye\n";
}

void test_jump() {
    // continue和break
    const int ArSize = 80;
    char line[ArSize];
    int spaces = 0;

    cout << "Enter a line of text:\n";
    //cin.get(line, ArSize);
    strcpy(line, "hello word word. two hello");
    cout << "Complete line:\n" << line << endl;
    cout << "Line through first period:\n";
    for (int i = 0; line[i] != '\0'; i++) {
        cout << line[i];    // display character
        if (line[i] == '.') // quit if it's a period
            break;
        if (line[i] != ' ') // skip rest of loop
            continue;
        spaces++;
    }
    cout << "\n" << spaces << " spaces\n";
    cout << "Done.\n";
}


int main() {
    SetConsoleOutputCP(65001);

    //test_if();
    //test_ifelse();
    //test_ifelseif();
    //test_or();
    //test_and();
    //test_not();
    //test_condit();
    //test_switch();
    test_jump();

    return 0;
}
