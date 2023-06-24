#include <iostream>
#include "windows.h"
#include <string>
#include <map>

using namespace std;

void test_map() {
    // 排序的map
    // 插入使用mp["bb"] = 22好点，会覆盖之前的值。
    map<string,int> mp;
    cout << "-----------------" << endl;
    cout << "size:" << mp.size() << endl;
    mp.insert(pair<string,int>("bb", 22));
    mp.insert(pair<string,int>("aa", 66));
    mp.insert(pair<string,int>("cc", 33));
    mp.insert(pair<string,int>("ff", 33));
    mp.insert(pair<string,int>("dd", 44));
    mp.insert(pair<string,int>("dd", 100)); // 无效
    cout << "size:" << mp.size() << endl;
    for (const auto &item: mp){
        cout << "key:" << item.first << ", value:" << item.second << endl;
    }
    cout << "-----------------" << endl;
    mp.clear();
    cout << "size:" << mp.size() << endl;
    mp["bb"] = 22;
    mp["aa"] = 66;
    mp["cc"] = 33;
    mp["ff"] = 33;
    mp["dd"] = 44;
    mp["dd"] = 100; // 替换之前的值
    cout << "size:" << mp.size() << endl;
    for(auto it = mp.begin(); it!=mp.end(); it++){
        cout << "key:" << it->first << ", value:" << it->second << endl;
    }
    cout << "-----------------" << endl;
    // 通过key删除元素
    mp.erase("cc");
    cout << "size:" << mp.size() << endl;
    for(auto it = mp.begin(); it!=mp.end(); it++){
        cout << "key:" << it->first << ", value:" << it->second << endl;
    }
    cout << "-----------------" << endl;
    map<string,int>::iterator it = mp.find("dd");
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