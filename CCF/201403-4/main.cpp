#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

#define MAXN (110 * 2)
#define INF 0x3f3f3f3f

struct point {
    int x, y;
};


struct edge {
    int to;
    int weight;
    edge(int to, int weight): to(to), weight(weight) {}
};

vector<edge> edges[MAXN];
int n, m, k, r;
int is_visited[MAXN][MAXN];
int dis[MAXN][MAXN];


point nodes[MAXN];

static int is_valid(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) <= r;
}

void init() {
    memset(is_visited, 0, sizeof(is_visited));
    memset(dis, INF, sizeof(dis));
    cin >> n >> m >> k >> r;
    for (int i = 0 ; i < n + m ; ++i) cin >> nodes[i].x >> nodes[i].y;
    for (int i = 0 ; i < n + m - 1 ; ++i)
        for (int j = i + 1 ; j < n + m ; ++j) {
        if (is_valid(nodes[i], nodes[j])) {

            edges[i].emplace_back(j, 1);
            edges[j].emplace_back(i, 1);

        }
    }
}

void dijkstra(int s) {
    queue<point > q;
    dis[s][0] = 0;
    is_visited[s][0] = 1;
    point src, tmp;
    src.x = s; src.y = 0;
    q.push(src);
    while (!q.empty()) {
        point tp = q.front(); q.pop();
        int u = tp.x;
        int n_num = tp.y;
        is_visited[u][n_num] = 0;
        for (int i = 0; i < edges[u].size(); ++i) {
            int to = edges[u][i].to;
            int weight = edges[u][i].weight;
            int t_n_num = n_num;
            if (to >= n) t_n_num++;
            if (t_n_num <= k && dis[to][t_n_num] > dis[u][n_num] + weight) {
                dis[to][t_n_num] = dis[u][n_num] + weight;
                if (!is_visited[to][t_n_num]) {
                    is_visited[to][t_n_num] = 0;
                    tmp.x = to;
                    tmp.y = t_n_num;
                    q.push(tmp);
                }
            }
        }
    }
    int res = INF;
    for (int i = 0 ; i <= k; ++i) if (dis[1][i] < res) res = dis[1][i];
    cout << res - 1<< endl;
}


int main() {
    init();
    dijkstra(0);
    return 0;
}