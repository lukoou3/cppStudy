#include <iostream>
#include "windows.h"
#include <string>
#include <vector>

using namespace std;

void test_vector1() {
    const int NUM = 5;
    vector<int> ratings(NUM); // 初始化size
    vector<string> titles(NUM);
    cout << ratings.size() << endl;
    cout << titles.size() << endl;
    cout << "-----------------" << endl;
    for (int i = 0; i < NUM; i++) {
        cout << ratings[i] << ":" << titles[i] << "." << endl;
    }
    cout << "-----------------" << endl;
    char text[20];
    for (int i = 0; i < NUM; i++) {
        ratings[i] = i + 100;
        sprintf(text, "text%d", i + 1);
        titles[i] = text;
    }
    cout << "-----------------" << endl;
    for (int i = 0; i < NUM; i++) {
        cout << ratings[i] << ":" << titles[i] << "." << endl;
    }
}

struct Review {
    std::string title;
    int rating;
};

void ShowReview(const Review &rr) {
    std::cout << rr.rating << "\t" << rr.title << std::endl;
}

void test_vector2() {
    vector<Review> books;
    Review temp;

    // 复制元素添加，想要储存原始元素可以使用指针
    temp.rating = 3;
    temp.title = "333";
    books.push_back(temp);
    temp.rating = 1;
    temp.title = "111";
    books.push_back(temp);
    temp.rating = 5;
    temp.title = "555";
    books.push_back(temp);
    temp.rating = 6;
    temp.title = "666";
    books.push_back(temp);

    int num = books.size();
    if (num > 0) {
        cout << "Thank you. You entered the following:\n" << "Rating\tBook\n";
        for (int i = 0; i < num; i++)
            ShowReview(books[i]);
        cout << "Reprising:\n" << "Rating\tBook\n";
        vector<Review>::iterator pr;
        for (pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);
        // 复制函数
        vector<Review> oldlist(books);     // copy constructor used
        if (num > 3) {
            // 删除指定区间的元素[1, 3]
            // remove 2 items
            books.erase(books.begin() + 1, books.begin() + 3);
            cout << "After erasure:\n";
            for (pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);
            // 插入元素
            // insert 1 item
            books.insert(books.begin(), oldlist.begin() + 1,
                         oldlist.begin() + 2);
            cout << "After insertion:\n";
            for (pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);
        }
        books.swap(oldlist);
        cout << "Swapping oldlist with books:\n";
        for (pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);
    } else
        cout << "Nothing entered, nothing gained.\n";
}

void test_vector3(){
    // 迭代删除元素
    vector<int> list;
    for (int i = 0; i < 10; ++i) {
        list.push_back(i);
    }
    cout << list.size() << endl;
    for (auto it = list.begin(); it != list.end();) {
        cout << *it << endl;
        if(*it % 2 == 1){
            // 删除当前元素，返回下个迭代器
            it = list.erase(it);
        }else{
            it++;
        }
    }
    cout << "-----------------" << endl;
    cout << list.size() << endl;
    for (const auto &item: list){
        cout << item << endl;
    }
}


int main() {
    //test_vector1();
    //test_vector2();
    test_vector3();
}