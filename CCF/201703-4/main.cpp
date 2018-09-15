#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <string>

using namespace std;

#define MAXN 100005

struct Edge {
    int u, v;
    int w;
    Edge(int u, int v, int w): u(u), v(v), w(w) {}
};

vector<Edge> graph[MAXN];

int parent[MAXN];
int n, m;
vector<Edge> edges;

bool cmp(Edge e1, Edge e2) {
    return e1.w < e2.w;
}

int find_parent(int s) {
    if (parent[s] == s) return s;
    parent[s] = find_parent(parent[s]);
    return parent[s];
}

int main() {
    cin >> n >> m;
    int u, v, w;
    int ans = 0x7fffffff;
    for (int i = 0 ; i <= n; ++i) parent[i] = i;
    while (m--) {
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    sort(edges.begin(), edges.end(), cmp);
    for (int i = 0 ; i < edges.size() ; ++i) {
        u = edges[i].u, v = edges[i].v, w = edges[i].w;
        int pu = find_parent(u);
        int pv = find_parent(v);
        if (pu == pv) continue;
        parent[pv] = pu;
        if (find_parent(1) == find_parent(n)) {
            ans = w;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}