#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define L(a) ((a) << (1))
#define R(a) ((a) << (1) | (1))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

#define MAX_N 50005 * 3
#define MAX_M 50005

struct {int lv,rv,cv;} tree[MAX_N];

int lazy[MAX_N];
int N,M;

void push_down(int rt, int len) {
    tree[L(rt)].lv = tree[L(rt)].rv = tree[L(rt)].cv = lazy[rt] ? 0: len - (len >> 1);
    tree[R(rt)].lv = tree[R(rt)].rv = tree[R(rt)].cv = lazy[rt] ? 0: (len >> 1);
    lazy[L(rt)] = lazy[rt];
    lazy[R(rt)] = lazy[rt];
    lazy[rt] = -1;
}

void push_up(int rt, int len) {
    tree[rt].cv = tree[L(rt)].rv + tree[R(rt)].lv;
    tree[rt].lv = tree[L(rt)].lv, tree[rt].rv = tree[R(rt)].rv;
    if (tree[L(rt)].lv == len - (len >> 1)) tree[rt].lv += tree[R(rt)].lv;
    if (tree[R(rt)].rv == len >> 1) tree[rt].rv += tree[L(rt)].rv;
    tree[rt].cv = MAX(tree[rt].cv,MAX(tree[L(rt)].cv,tree[R(rt)].cv));
}

void build(int rt, int l, int r) {
    lazy[rt] = -1;
    if (l == r ) {tree[rt].lv = tree[rt].cv = tree[rt].rv = 1 ;return;}
    int m = (l + r) >> 1;
    build(rt << 1, l , m), build(rt << 1 | 1, m + 1, r);
    push_up(rt,r-l+1);
}

void update(int Left, int Right, int delta, int rt, int l, int r) {
    if (Left <= l && Right >= r) {
        tree[rt].cv = tree[rt].lv = tree[rt].rv = delta ? 0 : r - l + 1;
        lazy[rt] = delta;
        return;
    }
    if (lazy[rt] != -1) push_down(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (Left <= m) update(Left, Right, delta, rt << 1, l, m);
    if (Right > m) update(Left,Right, delta, rt << 1 | 1, m + 1 , r);
    push_up(rt,r - l + 1);
}

int query(int num, int rt, int l, int r) {
    if (l == r) return l;
    if (lazy[rt] != -1) push_down(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (tree[L(rt)].cv >= num) return query(num,rt<<1,l,m );
    else if (tree[L(rt)].rv + tree[R(rt)].lv >= num) return m - tree[L(rt)].rv + 1;
    return query(num,rt << 1 | 1, m + 1, r);
}

int main() {
    scanf("%d %d",&N,&M);
    build(1,1,N);
    int index,sum,left;
    for (int i = 0 ; i < M ; ++i) {
        scanf("%d",&index);
        if (index == 1) {
            scanf("%d",&sum);
            if (tree[1].cv < sum) printf("0\n");
            else {
                int l = query(sum,1,1,N);
                update(l,sum + l - 1,1,1,1,N);
                printf("%d\n",l);
            }
        } else {
            scanf("%d %d",&left,&sum);
            update(left,left + sum - 1,0,1,1,N);
        }
    }
    return 0;
}