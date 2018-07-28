#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX_N 200000
#define L(a) ((a) << (1))
#define R(a) ((a) << (1) | (1))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

typedef long long ll;

int N,tot = 0;
int tree[MAX_N*4],lazy[MAX_N*4],subs[MAX_N*4],Left[MAX_N*4],Right[MAX_N*4],height[MAX_N*4];

void push_down(int rt) {
    tree[L(rt)] = MAX(tree[L(rt)], lazy[rt]);
    tree[R(rt)] = MAX(tree[R(rt)], lazy[rt]);
    lazy[L(rt)] = MAX(lazy[L(rt)], lazy[rt]);
    lazy[R(rt)] = MAX(lazy[R(rt)], lazy[rt]);
    lazy[rt] = 0;
}

void push_up(int rt) {
    tree[rt] = MAX(tree[L(rt)] , tree[R(rt)]);
}

void build(int rt, int l, int r) {
    if (l == r ) {tree[rt] = 0;return;}
    int m = (l + r) >> 1;
    build(rt << 1, l , m), build(rt << 1 | 1, m + 1, r);
//    push_up(rt);
}

void update(int Left, int Right, int delta, int rt, int l, int r) {
    if (Left <= l && Right >= r) {
        tree[rt] = MAX(tree[rt],delta);
        lazy[rt] = MAX(lazy[rt],delta);
        return;
    }
    if (lazy[rt]) push_down(rt);
    int m = (l + r) >> 1;
    if (Left < m) update(Left, Right, delta, rt << 1, l, m);
    if (Right > m) update(Left,Right, delta, rt << 1 | 1, m , r);
//    push_up(rt);
}

int query(int Left, int Right, int rt, int l, int r) {
    if (Left <= l && Right >= r) return tree[rt];
    if (lazy[rt]) push_down(rt);
    int m = (l + r) >> 1;
    if (Left < m) return query(Left,Right,rt<<1,l,m );
    else if (Right > m) return query(Left,Right,rt << 1 | 1, m, r);
}

int main() {
    scanf("%d",&N);
    int l,r,h;
    for (int i = 1 ; i <= N ; ++i) {
        scanf("%d %d %d",&l,&r,&h);
        Left[i] = l, Right[i] = r ; height[i] = h;
        subs[tot++] = l;
        subs[tot++] = r;
    }
    sort(subs,subs + tot);
    tot = unique(subs,subs+tot) - subs;
//    build(1,1,tot);
    for (int i = 1 ; i <= N ; ++i) {
        Left[i] = lower_bound(subs,subs + tot,Left[i]) - subs + 1;
        Right[i] = lower_bound(subs,subs + tot,Right[i]) - subs + 1;
        update(Left[i],Right[i],height[i],1,1,tot);
    }
    ll ans = 0;
    for (int i = 0 ; i < tot -1; ++i) {
        ll heig = query(i+1,i+2,1,1,tot);
        ll len = subs[i+1] - subs[i];
        ans += len * heig;
    }
    printf("%lld\n",ans);
    return 0;
}