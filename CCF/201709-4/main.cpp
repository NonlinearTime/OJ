#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stack>
#include <math.h>

using namespace std;

#define MAXN 1005
#define MIN(x,y) ((x) < (y) ? (x) : (y))

using Graph = vector<int>[MAXN];

int n,m;
Graph graphs[2];
bool in_stack[MAXN] = {false};
int dfn[MAXN], low[MAXN];
int Dindex, answer;
stack<int> s;

void tarjan(int u, Graph g) {
    dfn[u] = low[u] = ++Dindex;
    s.push(u);
    in_stack[u] = true;
    for (int i = 0 ; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (!dfn[v]) {
            tarjan(v,g);
            low[u] = MIN(low[u], low[v]);
        } else if (in_stack[v])
            low[u] = MIN(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        while (true) {
            int tp = s.top();
            s.pop();
            if (tp == u) break;
        }
    }
}

void make_graph() {
    cin >> n >> m;
    int u, v;
    for (int i = 0 ; i < m ; ++i) {
        cin >> u >> v;
        graphs[0][u].push_back(v);
        graphs[1][v].push_back(u);
    }
}

void step(int u, int gindex) {
    Dindex = 0;
    memset(in_stack, 0, sizeof(in_stack));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    while (!s.empty()) s.pop();
    tarjan(u, graphs[gindex]);
    int  t = 0;
    for (int i = 1; i <= n ; ++i) if (dfn[i]) t++;
    if (t == n) answer++;
}

void solve() {
    answer = 0;
    for (int i = 1; i <= n ; ++i) {
        step(i, 0);
        step(i, 1);
    }
    cout << answer << endl;
}

int main() {
    make_graph();
    solve();
    return 0;
}