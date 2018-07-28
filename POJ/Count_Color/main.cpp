#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_L 150005 * 2
#define L(a) ((a) << (1))
#define R(a) ((a) << (1) | (1))

int lazy[MAX_L];
int tree[MAX_L];
int colors[32];
int L,T,O;

void init() {
    for (int i = 1 ; i < 32 ; ++i) colors[i] = 1 << i;
}

void push_down(int rt) {
    tree[L(rt)] = lazy[rt];
    tree[R(rt)] = lazy[rt];
    lazy[L(rt)] = lazy[rt];
    lazy[R(rt)] = lazy[rt];
    lazy[rt] = 0;
}

void push_up(int rt) {
    tree[rt] = tree[L(rt)] | tree[R(rt)];
}

void build(int rt, int l, int r) {
    if (l == r ) {tree[rt] = 2;return;}
    int m = (l + r) >> 1;
    build(rt << 1, l , m), build(rt << 1 | 1, m + 1, r);
    push_up(rt);
}

void update(int left, int right, int delta, int rt, int l, int r) {
    if (left <= l && right >= r) {
        tree[rt] = delta;
        lazy[rt] = delta;
        return;
    }
    if (lazy[rt]) push_down(rt);
    int m = (l + r) >> 1;
    if (left <= m) update(left, right, delta, rt << 1, l, m);
    if (right > m) update(left,right, delta, rt << 1 | 1, m + 1, r);
    push_up(rt);
}

int query(int left, int right, int rt, int l, int r) {
    if (left <= l && right >= r) return tree[rt];
    if (lazy[rt]) push_down(rt);
    int m = (l + r) >> 1, ret = 0;
    if (left <=m) ret |= query(left,right,rt<<1,l,m);
    if (right > m) ret |= query(left,right,rt << 1 | 1, m + 1, r);
    return ret;
}

int main() {
    while (scanf("%d %d %d",&L,&T,&O) != EOF) {
        char t[2];
        int l,r,color,res,cnt = 0;
        init();
        build(1,1,L);
        while (O--) {
            scanf("%1s",t);
            if (t[0] == 'C') {
                scanf("%d %d %d",&l,&r,&color);
                if (l < r) update(l,r,colors[color],1,1,L);
                else update(r,l,colors[color],1,1,L);
            } else {
                scanf("%d %d",&l,&r);
                res = l < r ? query(l,r,1,1,L) : query(r,l,1,1,L);
                cnt = 0;
                while (res) {
                    if (res & 1 == 1) cnt++;
                    res >>= 1;
                }
                printf("%d\n",cnt);
            }
        }
    }
    return 0;
}