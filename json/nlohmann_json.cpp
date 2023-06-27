#include <iostream>
#include "nlohmann/json.hpp"

void test_json1(){
    using namespace std;
    using json = nlohmann::json;
    json j = {{"name", "John"}, {"age", 25}};
    cout << j.dump() << endl;
}


void test_json2(){
    using namespace std;
    using json = nlohmann::json;
    json j = {{"name", "John"}, {"age", 25}};
    if (j.find("name") != j.end()) {
        string name = j["name"];
        cout << "Name: " << name << endl;
    }
}


int main(){
    test_json1();
    test_json2();

    return 0;
}