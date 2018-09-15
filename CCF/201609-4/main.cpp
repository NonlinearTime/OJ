#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

#define MAXN 10005
#define MAXM 100005
#define INF 0x3fffffff

struct edge {
    int v;
    int w;
    edge(int v, int w): v(v), w(w) {}
};

vector<edge > graph[MAXN];
int pre[MAXN], dis[MAXN];
bool vis[MAXN];

queue<int> q;

void spfa(int s) {
    memset(vis, 0, sizeof(vis));
    for (int i = 0 ; i < MAXN ; ++i) pre[i] = INF, dis[i] = INF;
    q.push(s);
    dis[s] = 0;
    vis[s] = true;
    while (!q.empty()) {
        int u = q.front();
        vis[u] = false;
        q.pop();
        for (int i = 0 ; i < graph[u].size() ; ++i) {
            int v = graph[u][i].v;
            int w = graph[u][i].w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pre[v] = w;
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
            if (dis[v] == dis[u] + w) pre[v] = pre[v] < w ? pre[v] : w;
        }
    }
}

int main() {
    int n, m, u, v, w;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        graph[u].push_back(edge(v,w));
        graph[v].push_back(edge(u,w));
    }
    spfa(1);
    int ans = 0;
    for (int i = 2; i <= n ; ++i) ans += pre[i];
    cout << ans << endl;
    return 0;

}