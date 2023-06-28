#include <iostream>
#include "nlohmann/json.hpp"

void test_json(){
    using namespace std;
    using json = nlohmann::json;
    json j = {{"name", "John"}, {"age", 25}};
    cout << j.dump() << endl;

    //解析
    string s = R"(
    {
        "name": "Judd Trump",
        "credits": 1754500,
        "ranking": 1
    }
    )";
    json js = json::parse(s);

    //序列化
    string str = js.dump();
    cout << str << endl;
}

void test_json_update(){
    using namespace std;
    using json = nlohmann::json;
    json j{
            { "name", "Judd Trump"},
            { "credits", 1754500 },
            {"ranking", 1}
    };

    cout << j << endl;

    //j.at("name") = "Wang Daniu";
    j["name"] = "Wang Daniu";
    std::cout << j << endl;
}

void test_json_find(){
    using namespace std;
    using json = nlohmann::json;
    json j = {{"name", "John"}, {"age", 25}};
    if (j.find("name") != j.end()) {
        string name = j["name"];
        cout << "Name: " << name << endl;
    }
}


int main(){
    //test_json();
    test_json_update();
    //test_json_find();

    return 0;
}