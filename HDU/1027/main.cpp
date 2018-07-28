#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int periods[9] = {0,1,2,6,24,120,720,5040,40320};
int record[1001];
int base, M, N;

void swap(int a, int b) {
    int t = record[a];
    record[a] = record[b];
    record[b] = t;
}

void calc(int ll) {
    int loc_l, t;
    if (ll == 0) return;
    for (int i = 0 ; i < 8 ; ++i) {
        if (ll >= periods[i] && ll < periods[i+1]) {
            base = M - i ;
            loc_l = periods[i];
            t = ll / loc_l;
            swap(base,base + t);
            base++;
            sort(record+base,record + M + 1);
            calc(ll % loc_l);
            break;
        }
    }
}

int main() {
    while (scanf("%d %d",&M,&N) != EOF) {
        for (int i = 1 ; i <= 1000 ; ++i) record[i] = i;
        calc(N-1);
        for (int i = 1 ; i < M ; ++i) cout << record[i] << " ";
        cout << record[M] << endl;
    }
    return 0;
}