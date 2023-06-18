#include <iostream>
#include "windows.h"

using namespace std;

struct people   // structure declaration
{
    char name[20];
    string address;
    int age;
    double score;
};

void test_struct() {
    people data1 = {"小明", "江苏 扬州", 22, 90};
    cout << "name:" << data1.name << ",address:" << data1.address << ",age:" << data1.age << "score:" << data1.score << "\n";

    people data2;
    cout << "name:" << data2.name << ",address:" << data2.address << ",age:" << data2.age << ",score:" << data2.score << "\n";
    //错误的语法, 数组是const的
    //data2.name = "小明";
    strcpy(data2.name, "小明");
    data2.address = "江苏 扬州";
    data2.age = 22;
    data2.score = 80;
    cout << "name:" << data2.name << ",address:" << data2.address << ",age:" << data2.age << ",score:" << data2.score << "\n";
}

void test_struct_assign() {
    people data1 = {"小明", "江苏 扬州", 22, 90};
    cout << "name:" << data1.name << ",address:" << data1.address << ",age:" << data1.age << "score:" << data1.score << "\n";

    people data2;
    cout << "name:" << data2.name << ",address:" << data2.address << ",age:" << data2.age << ",score:" << data2.score << "\n";
    cout << "data:" << &data2 << ",name:" << &data2.name << ",address:" << &data2.address << ",age:" << &data2.age << ",score:" << &data2.score << "\n";
    // 可以使用赋值运算符（=）将结构赋给另一个同类型的结构，这样结构中每个成员都将被设置为另一个结构中相应成员的值，即使成员是数组。这种赋值被称为成员赋值（memberwise assignment）
    data2 = data1;
    cout << "name:" << data2.name << ",address:" << data2.address << ",age:" << data2.age << ",score:" << data2.score << "\n";
    cout << "data:" << &data2 << ",name:" << &data2.name << ",address:" << &data2.address << ",age:" << &data2.age << ",score:" << &data2.score << "\n";
}

void test_struct_array() {
    // 可以创建元素为结构的数组，方法和创建基本类型数组完全相同
    // 在内存中是连续的
    people datas[3] = {
            {"莫南", "江都", 18, 90},
            {"燕青丝", "江都", 17, 90},
            {"苏流沙", "江都", 20, 90},
    };

    cout << sizeof(datas)  << "," << sizeof(people) << endl;
    cout << hex;
    cout << sizeof(people) << endl;
    cout << dec;
    for (int i = 0; i < sizeof(datas) / sizeof(people); ++i) {
        cout << &datas[i] << "," << ",name:" << datas[i].name << endl;
    }
    cout << &datas[1] - &datas[0]  << "," << &datas[2] - &datas[1] << endl;
}

int main() {
    SetConsoleOutputCP(65001);

    //test_struct();
    //test_struct_assign();
    test_struct_array();

    return 0;
}
