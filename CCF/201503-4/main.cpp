#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

#define MAXN 20005
#define INF 0x3ffffff

int n, m;

queue<int> q;
int dis[MAXN], vis[MAXN];
vector<int> graph[MAXN];

void spfa(int s) {
    memset(vis, 0 , sizeof(vis));
    for (int i = 0 ; i <= n + m ; ++i ) dis[i] = 0;
    q.push(s);
    vis[s] = true;
    dis[s] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0 ; i < graph[u].size(); ++i) {
            int v = graph[u][i];
            if (!vis[v]) {
                dis[v] = dis[u] + 1;
                q.push(v);
                vis[v] = true;
            }
        }
    }
}

void solver() {
    spfa(1);
    int m = -1, midx;
    for (int i = 1; i <= n + m ; ++i) if (dis[i] > m) m = dis[i], midx = i;
    spfa(midx);
    int t = -1;
    for (int i = 1; i <= n + m ; ++i) if (dis[i] > t) t = dis[i];
    cout << t << endl;
}

int main() {
    cin >> n >> m;
    int t = n + m, x;
    for (int i = 1; i < n; ++i) {
        cin >> x;
        graph[x].push_back(i + 1);
        graph[i + 1].push_back(x);
    }
    for (int i = n + 1; i <= t; ++i) {
        cin >> x;
        graph[x].push_back(i);
        graph[i].push_back(x);
    }
    solver();
    return 0;
}