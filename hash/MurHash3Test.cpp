#include <iostream>
#include "MurmurHash3.h"
#include "windows.h"

using namespace std;

static const uint64_t DEFAULT_SEED = 9001;

void test_hash_long(){
    // 和java的计算结果一样
    for (int i = 0; i < 10; ++i) {
        int64_t val = static_cast<int64_t>(i);
        HashState hashResult;
        MurmurHash3_x64_128(&val, sizeof(int64_t), DEFAULT_SEED, hashResult);
        printf("%d:%lld,%lld\n", i, hashResult.h1, hashResult.h2);
        //printf("%d:%llu,%llu\n", i, hashResult.h1, hashResult.h2);
        //cout << i << ":" << hashResult.h1 << "," << hashResult.h2 << endl;
        cout << i << ":" << static_cast<int64_t>(hashResult.h1) << "," << static_cast<int64_t>(hashResult.h2) << endl;
    }

    cout << "####################" << endl;

    for (int64_t i = 400000000000LL; i < 400000000000LL + 10; ++i) {
        int64_t val = static_cast<int64_t>(i);
        HashState hashResult;
        MurmurHash3_x64_128(&val, sizeof(int64_t), DEFAULT_SEED, hashResult);
        printf("%lld:%lld,%lld\n", i, hashResult.h1, hashResult.h2);
        cout << i << ":" << static_cast<int64_t>(hashResult.h1) << "," << static_cast<int64_t>(hashResult.h2) << endl;
    }
}

void test_hash_str(){
    string strs[] = {"aa", "bb", "11", "java", "搜索", "指鼠为鸭"};
    for (auto &item: strs){
        HashState hashResult;
        MurmurHash3_x64_128(item.c_str(), item.length(), DEFAULT_SEED, hashResult);
        printf("%s:%lld,%lld\n", item.c_str(), hashResult.h1, hashResult.h2);
    }
}

int main() {
    SetConsoleOutputCP(65001);
    test_hash_long();
    //test_hash_str();
}