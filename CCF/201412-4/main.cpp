#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

#define MAXN 1005
#define MAXM 100005

struct edge {
    int u, v, w;
    edge(int u, int v, int w): u(u), v(v), w(w) {}
} ;

int n, m, res;
int parent[MAXN];
vector<edge> E;

int cmp (edge e1, edge e2) {
    return e1.w < e2.w;
}

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py) return;
    parent[py] = px;
}

int main() {
    cin >> n >> m;
    int u, v, w;
    for (int i = 0 ; i < m ; ++i) {
        cin >> u >> v >> w;
        E.push_back(edge(u, v, w));
    }
    sort(E.begin(), E.end(), cmp);
    res = 0;
    for (int i = 0 ; i < n + 1 ; ++i) parent[i] = i;
    for (int i = 0 ; i < m; ++i) {
        u = E[i].u, v = E[i].v, w = E[i].w;
        int pu = find(u), pv = find(v);
        if (pu != pv) {
            res += w;
            parent[pv] = pu;
        }
    }
    cout << res << endl;
    return 0;

}