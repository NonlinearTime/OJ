#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

#define MAX_N 1005
#define inf 10000000

struct {int v, w, next;} edge[MAX_N];

int inq[MAX_N],dist[MAX_N],edgeHead[MAX_N],cnt[MAX_N];
int r[25],t[25];
int edgeNum = 1;
int N;

void add_edge(int u, int v, int w) {
    edge[edgeNum].v = v,edge[edgeNum].next = edgeHead[u];
    edge[edgeNum].w = w;edgeHead[u] = edgeNum++;//index用于记录哪次输入的该条边
}

int spfa(int s, int ans) {
    memset(inq,0, sizeof(inq));
    memset(dist,-inf, sizeof(dist));
    memset(cnt,0, sizeof(cnt));
    dist[s] = 0 , inq[s] = 1;
    stack<int > S;
    S.push(s);
    cnt[0]++;
    while (!S.empty()) {
        s = S.top();
        S.pop();
        inq[s] = 0;
        for (int i = edgeHead[s]; i ; i = edge[i].next) {
            int v = edge[i].v, w = edge[i].w;
            if (dist[v] < dist[s] + w) {
                dist[v] = dist[s] + w;
                if (!inq[v]){
                    inq[v] = 1;
                    S.push(v);
                    if (++cnt[v] > 24) return -1;
                }
            }
        }
    }
    if (dist[24] == ans ) return 1;
    else return 0;
}

int check(int ans) {
    memset(edgeHead,0, sizeof(edgeHead));
    edgeNum = 1;
    add_edge(0,24,ans);
    for (int i = 1 ; i <= 24 ; ++i) {
        add_edge(i-1,i,0);
        add_edge(i,i-1,-t[i]);
    }
    for (int i = 1 ; i <= 8 ; ++i) add_edge(i+16,i,r[i]-ans);
    for (int i = 9 ; i <= 24 ; ++i) add_edge(i - 8, i , r[i]);
    return spfa(0,ans);
}

int main() {
    scanf("%d",&N);
    int tmp,num;
    while (N--) {
        memset(t,0, sizeof(t));
        for (int i = 1 ; i <= 24 ; ++i) scanf("%d",&r[i]);
        scanf("%d",&tmp);
        for (int i = 0 ; i < tmp ; ++i) {
            scanf("%d",&num);
            t[num+1] += 1;
        }
        int i;
        for (i = 0; i <= tmp ; ++i) {
            if (check(i) == 1) {
                printf("%d\n",i);
                break;
            }
        }
        if (i > tmp) printf("No Solution\n");
    }
    return 0;
}