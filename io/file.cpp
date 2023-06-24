#include <iostream> // not needed for many systems
#include <fstream>
#include <string>
#include "windows.h"

using namespace std;

void test_fileio(){
    /**
     * 要让程序写入文件，必须这样做：
     *   （1）创建一个ofstream对象来管理输出流；
     *   （2）将该对象与特定的文件关联起来；
     *   （3）以使用cout的方式使用该对象，唯一的区别是输出将进入文件，而不是屏幕。
     */
    string filename = "D:\\files\\txt_write.txt";

    // create output stream object for new file and call it fout
    ofstream fout(filename.c_str());

    fout << "For your eyes only!\n";        // write to file
    //cout << "Enter your secret number: ";   // write to screen
    //float secret;
    //cin >> secret;
    float secret = 10.8;
    fout << "Your secret number is " << secret << endl;
    fout.close();           // close file

    cout << "-----------------" << endl;

    // create input stream object for new file and call it fin
    ifstream fin(filename.c_str());
    cout << "Here are the contents of " << filename << ":\n";
    char ch;
    while (fin.get(ch))     // read character from file and
        cout << ch;         // write it to screen
    cout << "Done\n";
    fin.close();
}

void test_fileio2(){
    string filename = "D:\\files\\txt_write2.txt";

    ofstream fout(filename.c_str());

    fout << "测试中文\n";        // write to file
    fout << "测试汉语" << endl;
    fout.close();           // close file

    cout << "-----------------" << endl;
    ifstream fin(filename.c_str());
    cout << "Here are the contents of " << filename << ":\n";
    char ch;
    while (fin.get(ch))     // read character from file and
        cout << ch;         // write it to screen
    cout << "Done\n";
    fin.close();

    cout << "-----------------" << endl;
    ifstream fin2(filename.c_str());
    cout << "Here are the contents of " << filename << ":\n";
    char line[256];
    while (fin2.getline(line, 256) && line[0] != '\0'){
        cout << line << endl;
    }
    cout << "Done\n";
    fin.close();
}


int main() {
    //SetConsoleOutputCP(65001);
    //test_fileio();
    test_fileio2();

    return 0;
}