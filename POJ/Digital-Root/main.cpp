#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;


int main() {
    int a;

    string b;

    while (cin >> b && b != "0") {
        a = 0;
        for (int i = 0 ; i < b.size() ; ++i) {
            a += b[i] - '0';
            if ( a >= 10) a = a / 10 + a %10;
        }
        cout << a << endl;
    }

    return 0;
}