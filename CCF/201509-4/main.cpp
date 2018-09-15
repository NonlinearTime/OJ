#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

#define MAXN 100005
#define MIN(x,y) ((x) < (y) ? (x) : (y))

int n, m;
vector<int> graph[MAXN];
bool in_stack[MAXN] = {false};
int dfn[MAXN] = {0};
int low[MAXN] = {0};
int Dindex, answer;
stack<int> st;

void tarjan(int s) {
    dfn[s] = low[s] = ++Dindex;
    st.push(s);
    in_stack[s] = true;
    for (int i = 0 ; i < graph[s].size(); ++i) {
        int v = graph[s][i];
        if (!dfn[v]) {
            tarjan(v);
            low[s] = MIN(low[s], low[v]);
        } else if (in_stack[v])
            low[s] = MIN(low[s], dfn[v]);
    }
    if (dfn[s] == low[s]) {
        int t = 0;
        while (true) {
            int tp = st.top();
            st.pop();
            t++;
            if (tp == s) break;
        }
        if (t > 1) answer += t * (t - 1) / 2;
    }
}

int main() {
    cin >> n >> m;
    int u, v;
    for (int i = 0 ; i <  m ; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    Dindex = answer = 0;
    for (int i = 1; i <=n ; ++i) {
        if (!dfn[i]) tarjan(i);
    }
    cout << answer << endl;
    return 0;
}