#include <iostream>
#include "windows.h"
#include <string>
#include <unordered_map>

using namespace std;

void test_map() {
    unordered_map<string, int> mp;
    mp["bb"] = 22;
    mp["aa"] = 66;
    mp["cc"] = 33;
    mp["ff"] = 33;
    mp["dd"] = 44;
    mp["dd"] = 100;
    cout << "size:" << mp.size() << endl;
    for (const auto &item: mp){
        cout << "key:" << item.first << ", value:" << item.second << endl;
    }
    cout << "-----------------" << endl;
    mp.erase("aa");
    cout << "size:" << mp.size() << endl;
    for(auto it = mp.begin(); it!=mp.end(); it++){
        cout << "key:" << it->first << ", value:" << it->second << endl;
    }
    cout << "-----------------" << endl;
    auto it = mp.find("dd");
    if(it != mp.end()){
        cout << "find:" << it->second << endl;
        mp.erase(it); // 删除
    }
    cout << "size:" << mp.size() << endl;
    for(auto it = mp.begin(); it!=mp.end(); it++){
        cout << "key:" << it->first << ", value:" << it->second << endl;
    }
    cout << "-----------------" << endl;
    it = mp.find("gg");
    if(it == mp.end()){
        cout << "not find:" << "key gg" << endl;
    }
}

int main() {
    test_map();
}