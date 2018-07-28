#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

#define MAX_V 30050
#define MAX_E 150050
#define inf 1000000

struct {int v,next,index,w; }edge[MAX_E * 2];

int edgeHead[MAX_E],inq[MAX_V],dist[MAX_V];
int edgeNum = 1, V, E;

void add_edge(int u, int v, int w) {
    edge[edgeNum].v = v,edge[edgeNum].next = edgeHead[u];
    edge[edgeNum].w = w;edgeHead[u] = edgeNum++;//index用于记录哪次输入的该条边
}

void spfa(int s) {
    memset(inq,0, sizeof(inq));
    memset(dist,inf, sizeof(dist));
    dist[s] = 0 , inq[s] = 1;
    stack<int > S;
    S.push(s);
    while (!S.empty()) {
        s = S.top();
        S.pop();
        inq[s] = 0;
        for (int i = edgeHead[s]; i ; i = edge[i].next) {
            int v = edge[i].v, w = edge[i].w;
            if (dist[v] > dist[s] + w) {
                dist[v] = dist[s] + w;
                if (!inq[v]){
                    inq[v] = 1;
                    S.push(v);
                }
            }
        }
    }
    printf("%d\n",dist[V]);
}

int main() {
    scanf("%d %d",&V,&E);
    int u,v,w;
    edgeNum = 1;
    for (int i = 1 ; i <= E ;++i) {
        scanf("%d %d %d",&u,&v,&w);
        add_edge(u,v,w);
    }
    spfa(1);
    return 0;
}