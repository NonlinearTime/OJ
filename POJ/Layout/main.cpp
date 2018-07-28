#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

#define MAX_V 2000
#define MAX_E 50050
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

const int inf=0x3f3f3f3f;

struct {int v,next,index,w; }edge[MAX_E ];

int edgeHead[MAX_E],inq[MAX_V],dist[MAX_V],cnt[MAX_V];
int edgeNum = 1, N, ML, MD;

void add_edge(int u, int v, int w) {
    edge[edgeNum].v = v,edge[edgeNum].next = edgeHead[u];
    edge[edgeNum].w = w;edgeHead[u] = edgeNum++;
}

int spfa(int s) {
    memset(inq,0, sizeof(inq));
    memset(dist,inf, sizeof(dist));
    memset(cnt,0, sizeof(cnt));
    dist[s] = 0 , inq[s] = 1;
    queue<int > S;
    S.push(s);
    cnt[s]++;
    while (!S.empty()) {
        s = S.front();
        S.pop();
        inq[s] = 0;
        for (int i = edgeHead[s]; i ; i = edge[i].next) {
            int v = edge[i].v, w = edge[i].w;
            if (dist[v] > dist[s] + w) {
                dist[v] = dist[s] + w;
                if (!inq[v]){
                    inq[v] = 1;
                    S.push(v);
                    if (++cnt[v] > N) return 0;
                }
            }
        }
    }
    return 1;
}

int main() {
    scanf("%d %d %d",&N,&ML,&MD);
    int u,v,w;
    edgeNum = 1;
    memset(edgeHead,0, sizeof(edgeHead));
    for (int i = 1 ; i <= ML ;++i) {
        scanf("%d %d %d",&u,&v,&w);
        add_edge(u,v,w);
    }
    for (int i = 0 ; i < MD ; ++i) {
        scanf("%d %d %d",&u,&v,&w);
        add_edge(v,u,-w);
    }
    if (spfa(1)) {
        if (dist[N] == inf) printf("-2\n");
        else printf("%d\n",dist[N]);
    } else printf("-1\n");
    return 0;
}