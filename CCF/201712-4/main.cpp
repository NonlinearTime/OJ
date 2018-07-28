#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

#define NUM_V 600
#define NUM_E 210000
#define inf 0x0fffffffffffffff
typedef long long  ll;

struct {int v, next, t; ll w; } edge[NUM_E];

ll dist[NUM_V], dist1[NUM_V], dist2[NUM_V],path[NUM_V],path1[NUM_V];
int edgeNum, edgeHead[NUM_E];
int inq[NUM_V];

int N,M;

void init() {
    edgeNum = 1;
    memset(edgeHead,0,NUM_E);
    memset(inq,0,NUM_V);
    for (int i = 0 ; i < NUM_V ; ++i) dist[i] = dist1[i] = inf, dist2[i] = inf, path[i] = 0, path1[i] = 0;
}

void add_edge(int u, int v, ll w, int t) {
    edge[edgeNum].v = v; edge[edgeNum].w = w; edge[edgeNum].t = t;
    edge[edgeNum].next = edgeHead[u]; edgeHead[u] = edgeNum++;
}

void spfa(int source) {
    int t;
    queue<int> s;
    s.push(source);
    inq[source] = 1;
    dist[source] = 0;
    dist1[source] = 0;
    dist2[source] = 0;
    while (!s.empty()) {
        t = s.front();
        s.pop();
        inq[t] = 0;
        ll road_val = inf , path_val = inf, rp_val = inf;
        for (int i = edgeHead[t]; i ; i = edge[i].next) {
            int v = edge[i].v; ll w = edge[i].w; int tp = edge[i].t;
            if (!tp) {
                if (dist[v] > dist[t] + w) {
                    dist[v] = dist[t] + w;
                    dist1[v] = dist[t] + w;
                    path[v] = 0;
                    if (!inq[v]) {
                        inq[v] = 1;
                        s.push(v);
                    }
                }
                if (dist1[v] > dist[t] + w) {
                    dist1[v] = dist[t] + w;
                    if (!inq[v]) {
                        inq[v] = 1;
                        s.push(v);
                    }
                }
            } else {
                if (dist2[v] > dist1[t] + w * w && dist1[t] != 0) {
                    dist2[v] = dist1[t] + w * w;
                    path1[v] = w;
                    if (!inq[v]) {
                        inq[v] = 1;
                        s.push(v);
                    }
                }
                path_val = dist[t] + (w + path[t]) * (w + path[t]) - path[t] * path[t];
                road_val = dist1[t] + w * w;
                rp_val = dist2[t] + (w + path1[t]) * (w + path1[t]) - path1[t] * path1[t];
                if (path_val < dist[v] && path_val < road_val && path_val < rp_val) {
                    dist[v] = path_val;
                    path[v] = w + path[t];
                    if (!inq[v]) {
                        inq[v] = 1;
                        s.push(v);
                    }
                } else if (road_val < dist[v] && road_val <= path_val && road_val <= rp_val) {
                    dist[v] = road_val;
                    path[v] = w;
                    if (!inq[v]) {
                        inq[v] = 1;
                        s.push(v);
                    }
                } else if (rp_val < dist[v] && rp_val < path_val && rp_val < road_val) {
                    dist[v] = rp_val;
                    path[v] = w + path1[t];
                    if (!inq[v]) {
                        inq[v] = 1;
                        s.push(v);
                    }
                }
            }
        }
    }
}

int main() {
    init();
    cin >> N >> M;
    int t,a,b,c;
    while (M--) {
        cin >> t >> a >> b >>c;
        add_edge(a,b,c,t);
        add_edge(b,a,c,t);
    }
    spfa(1);
    cout << dist[N] << endl;
    return 0;
}
