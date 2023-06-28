#include <iostream>
#include "base64.h"

using namespace std;


/**
 * https://github.com/ReneNyffenegger/cpp-base64
 */
int main(){
    const string orig = "axsfdfxax1111gh";

    string encoded1 = base64_encode(reinterpret_cast<const unsigned char*>(orig.c_str()), orig.length());
    string encoded2 = base64_encode((const unsigned char*)(orig.c_str()), orig.length());
    string encoded3 = base64_encode(orig);
    string decoded1 = base64_decode(encoded1);
    string decoded2 = base64_decode(encoded2);
    string decoded3 = base64_decode(encoded3);

    cout << "encoded1:" << encoded1 << endl;
    cout << "encoded2:" << encoded2 << endl;
    cout << "encoded3:" << encoded3 << endl;

    cout << "decoded1:" << decoded1 << endl;
    cout << "decoded2:" << decoded2 << endl;
    cout << "decoded3:" << decoded3 << endl;

    return 0;
}