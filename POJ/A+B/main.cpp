#include <iostream>

using namespace std;

int main() {
    int a = 5, b = 8;
    int carry,res,A,B;
    res = carry = 0;
    for (int i = 0 ; i < 32 ; ++i) {
        A = (a >> i) & 1;
        B = (b >> i) & 1;


        cout << A << " " << B  << " " << res << " " << a << " " << b << endl;

        if (A && B) {
            if (carry) {
                res |= 1 << i;
                carry = 1;
            } else {
                res |= 0;
                carry = 1;
            }
        } else if (A | B) {
            if (carry) {
                carry = 1;
                res |= 0;
            } else {
                carry = 0;
                res |= 1 << i;
            }
        } else if (A == 0 && B == 0) {

            if (carry) {
                res |= 1 << i;
            } else {
                res |= 0;
            }
            carry = 0;
        }
//        cout << res << " ";
    }
    cout << res << endl;
    return res;
}