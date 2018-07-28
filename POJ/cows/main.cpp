#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX_NUM 100010
#define lowbit(a) ((a)&(-a))

struct Node {
    int s,e,index;
};

bool compare(Node &x, Node &y) {
    if (x.e > y.e) return true;
    else if (x.e < y.e) return false;
    else {
        return x.s < y.s;
    }
}

int C[MAX_NUM];

int num,MAX;

Node rec[MAX_NUM];
int indexs[MAX_NUM];

void add (int x , int y) {
    for (int i = x; i <= MAX ;  i+= lowbit(i)) C[i] += y;
}

int getSum(int x) {
    int sum = 0;
    for (int i = x; i > 0 ; i-=lowbit(i)) sum+=C[i];
    return sum;
}


int main() {
    int s,e;
    while(true) {
        scanf("%d",&num);
        MAX = 0;
        memset(C,0, sizeof(C));
        if (!num) break;
        for (int i = 0 ; i != num ; ++i) {
            scanf("%d %d",&s,&e);
            rec[i].s = s + 1;
            rec[i].e = e + 1;
            rec[i].index = i;
            int m = rec[i].s > rec[i].e ? rec[i].s : rec[i].e;
            MAX = m > MAX ? m : MAX;
         }
        sort(rec,rec+num,compare);
        s = e = -1;
        int cnt = 0;
        for (int i = 0 ; i != num ; ++i) {
            int ans;
            add(rec[i].s, 1);
            if (rec[i].s != s || rec[i].e != e) {
                s = rec[i].s;
                e = rec[i].e;
                cnt = 0;
            } else if (rec[i].s == s && rec[i].e == e){
                cnt++;
            }
            ans = getSum(rec[i].s) - cnt - 1;
            indexs[rec[i].index] = ans;
        }
        int i;
        for (i = 0 ; i != num - 1 ; ++i) printf("%d ",indexs[i]);
        printf("%d\n",indexs[i]);
    }
    return 0;
}