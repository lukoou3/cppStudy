#include <iostream>
#include<regex>

using namespace std;

void regex_match(){
    // regex_match 完全匹配才返回true，和python一样
    regex num_r("[0-9]+");
    string str1 = "aa123bb";
    string str2 = "123";

    cout << str1  << ":" << regex_match(str1, num_r) << endl;
    cout << str2  << ":" << regex_match(str2, num_r) << endl;
    cout << true << endl;
}

void regex_search(){
    // regex_search 匹配就返回true，和python一样
    regex num_r("[0-9]+");
    string str1 = "aa123bb";
    string str2 = "123";

    cout << str1  << ":" << regex_search(str1, num_r) << endl;
    cout << str2  << ":" << regex_search(str2, num_r) << endl;

    num_r = regex("([0-9]*)[a-z]+([0-9]+)");
    string str = "123abc345";
    smatch matchs;
    cout << str  << ":" << regex_search(str, num_r) << endl;
    if(regex_search(str, matchs, num_r)){
        cout << matchs.str()<< endl;
        cout << matchs.str(1)<< endl;
        cout << matchs.str(2)<< endl;
        cout << matchs[0]<< endl;
        cout << matchs[1]<< endl;
        cout << matchs[2]<< endl;
    }
}

void regex_replace(){
    cout << regex_replace("aa123bb", regex("[0-9]+"), "xxx") << endl;
    cout << regex_replace("aa123bb", regex("([0-9]+)[a-z]+"), "xxx\1") << endl;
    cout << regex_replace("aa123bb", regex("([0-9]+)[a-z]+"), "xxx\\1") << endl;
    cout << regex_replace("aa123bb", regex("([0-9]+)[a-z]+"), "xxx$1") << endl;
    cout << string(20, '#') << endl;
    cout << regex_replace("aa123bb", regex("[a-z]+"), "xxx") << endl;
}

int main(){
    //regex_match();
    //regex_search();
    regex_replace();
}