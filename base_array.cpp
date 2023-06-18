#include <iostream>
#include "windows.h"

using namespace std;

void test_array(){
    // 马铃薯数量和价格数组
    int yams[3];    // creates array with three elements
    yams[0] = 7;    // assign value to first element
    yams[1] = 8;
    yams[2] = 6;

    int yamcosts[3] = {20, 30, 5}; // create, initialize array

    int total_cost = yams[0] * yamcosts[0] + yams[1] * yamcosts[1]  + yams[2] * yamcosts[2];
    cout << "The total cost is " << total_cost << ".\n";

    cout << "数组的字节大小：" << sizeof yams << " bytes.\n";
    cout << "数组中一个元素的字节大小： " << sizeof yams[0] << " bytes.\n";
}

int main() {
    SetConsoleOutputCP(65001);

    test_array();


    return 0;
}
