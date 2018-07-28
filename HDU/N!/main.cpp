#include <iostream>
#include <cstring>

using namespace std;

#define MAX_SIZE 10050

int num[MAX_SIZE];
int places;

void multi(int n) {
    int t,i;
    int carry = 0 ;
    for (i = 0 ; i <= places ; ++i) {
        t = num[i] * n + carry;
        carry = t / 10000;
        num[i] = t % 10000;
    }
    if (carry > 0) {
        places++;
        num[places] = carry;
    }
}



int main() {
    int n;
    while (scanf("%d",&n) != EOF) {
        memset(num, 0, MAX_SIZE);
        num[0] = 1;
        places = 0;
        for (int i = 1; i <= n; ++i) {
            multi(i);
        }
        cout << num[places];
        for (int i = places - 1; i >= 0; --i) {
            printf("%04d",num[i]);
        }
        cout << endl;
    }

}