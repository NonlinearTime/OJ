#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX_N 200000 * 2
#define MAX_M 50005 * 2
#define L(a) ((a) << (1))
#define R(a) ((a) << (1) | 1)

struct {int left, sum;} tree[MAX_N ];
struct rec {int index,left,right,k;};
rec Rec[MAX_M];
int S[MAX_N],T[MAX_N],ans[MAX_M];
int N,M;

bool compare(rec x, rec y) {return x.right < y.right;}

void push_up(int rt) {
    tree[rt].left = tree[L(rt)].sum;
    tree[rt].sum = tree[L(rt)].sum + tree[R(rt)].sum;
}

void build(int rt, int l, int r) {
    tree[rt].left = 0;
    tree[rt].sum = 0;
    if (l == r ) {return;}
    int m = (l + r) >> 1;
    build(rt << 1, l , m), build(rt << 1 | 1, m + 1, r);
    push_up(rt);
}

void update(int left, int right, int delta, int rt, int l, int r) {
    if (left <= l && right >= r) {
        tree[rt].sum += delta;
        return;
    }
    int m = (l + r) >> 1;
    if (left <= m) update(left, right, delta, rt << 1, l, m);
    if (right > m) update(left,right, delta, rt << 1 | 1, m + 1, r);
    push_up(rt);
}

int query(int k, int rt, int l, int r) {
    if (l == r) return l;
    int m = (l + r) >> 1;
    if (k <= tree[rt].left) return query(k,rt<<1,l,m);
    else  return query(k - tree[rt].left, rt << 1 | 1, m + 1, r);
}

int main() {
    int tot;
    scanf("%d %d",&N,&M);
    for (int i = 1 ; i <= N ; ++i) {
        scanf("%d",&S[i]);
        T[i] = S[i];
    }
    sort(S+1,S+N+1);
    tot = unique(S+1,S+N+1) - S - 1;
    build(1,1,tot);
    for (int i = 1 ; i <= N ; ++i) {
        T[i] = lower_bound(S+1,S+tot+1,T[i]) - S;
    }
    for (int i = 1 ; i <= M ; ++i) {
        scanf("%d %d %d",&Rec[i].left,&Rec[i].right,&Rec[i].k);
        Rec[i].index = i;
    }
    sort(Rec+1,Rec+M+1,compare);
    int preL = Rec[1].left, preR = Rec[1].right;
    for (int i = preL; i <= preR ; ++i) update(T[i],T[i],1,1,1,tot);
    for (int i = 1; i <= M ; ++i) {
        for (int j = preL; j < Rec[i].left; ++j)
            update(T[j],T[j],-1,1,1,tot);
        for (int j = preR + 1; j <= Rec[i].right; ++j)
            update(T[j],T[j],1,1,1,tot);
        preL = Rec[i].left, preR = Rec[i].right;
        ans[Rec[i].index] = S[query(Rec[i].k,1,1,tot)];
    }
    for (int i = 1 ; i <= M ;++i) printf("%d\n",ans[i]);
    return 0;
}