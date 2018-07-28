#include <iostream>
#include <cstring>
#include <string>

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

int compare(int a, string b) {
    if (places[a] + 1 < b.length()) return 1;
    if (places[a] + 1 > b.length()) return 2;
    for (int i = places[a] , j = 0; i >= 0, j < b.length() ; --i, ++j ) {
        if (record[a][i] > b[j] - '0') return 2;
        if (record[a][i] < b[j] - '0') return 1;
    }
    return 3;
}

int main() {
    int count = 0;
    string a,b;
    memset(isCal,0, sizeof(isCal));
    memset(record,0,sizeof(record));
    memset(places,0, sizeof(places));
    record[0][0] = 1;
    record[1][0] = 2;
    places[0] = 0;
    places[1] = 0;
    isCal[0] = 1;
    isCal[1] = 1;
    calc(600);
    while ((cin >> a >> b) && (a !="0" || b !="0")) {
        count = 0;
        for (int i = 0 ; i < 700 ; ++i) {
            if (compare(i,b) == 2) break;
            if (compare(i,a) == 2 || compare(i,a) == 3) count++;
        }
        cout << count << endl;
    }

    return 0;
}