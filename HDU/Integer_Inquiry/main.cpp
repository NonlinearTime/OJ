#include <iostream>
#include <cstring>

using namespace std;

#define LEN 1000

int record[LEN][LEN];
bool isCal[LEN];
int places[LEN];

void add_num(int a, int b, int dest) {
    int t = places[a] > places[b] ? a : b;
    int carry = 0;
    for (int i = 0 ; i <= places[t]; ++i) {
        record[dest][i] += record[a][i] + record[b][i] + carry;
        carry = record[dest][i] / 10;
        record[dest][i] = record[dest][i] % 10;
    }
    if (carry > 0) {
        places[dest] = places[t] + 1;
        record[dest][places[dest]] = carry;
    } else places[dest] = places[t];
    isCal[dest] = 1;
}

void calc(int a) {
    if (a <= 1) return;
    if (isCal[a]) return;
    if (!isCal[a-1]) calc(a-1);
    if (!isCal[a-2]) calc(a-2);
    add_num(a-2,a-1,a);
}

void printN(int a) {
    for (int i = places[a] ; i >= 0 ; --i) {
        printf("%d",record[a][i]);
    }
    printf("\n");
}

int main() {
    int n,a;
    memset(isCal,0, sizeof(isCal));
    memset(record,0,sizeof(record));
    memset(places,0, sizeof(places));
    cin >> n;
    record[0][0] = 1;
    record[1][0] = 1;
    places[0] = 0;
    places[1] = 0;
    isCal[0] = 1;
    isCal[1] = 1;
    while (n--) {
        cin >> a;
//        add_num(0,1,2);
        calc(a-1);
        printN(a-1);
    }
    return 0;
}