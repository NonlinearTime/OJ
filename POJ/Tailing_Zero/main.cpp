#include <iostream>

using namespace std;

struct rec {
    long long zeroNum;
    long long twoNum;
    long long fiveNum;
};

int getNum(int n, int k) {
    if (n < 10) {
        if (n >= k) return 1;
        else return 0;
    }
    int t = n ;
    int count;
    for ( count = 1 ; ; count++) {
        if ((t /= 10) < 10) break;
    }
    int tmp = count;
    int t1 = t;
    int t2 = 1;

    for (int i = 0 ; i < count - 1; ++i) {
        tmp *= 10;
        t1 *= 10;
        t2 *= 10;
    }
    t1 *= 10;
    t2 *= 10;

    tmp *= t;

    if (t == k) tmp += n - t1 + 1;
    else if (k != 0 && k < t) tmp += t2;


    return tmp + getNum(n-t1,k);
}

int main() {
    long long n = 10 , k = 2;

    cout << getNum(n,k);

    return 0;
}



