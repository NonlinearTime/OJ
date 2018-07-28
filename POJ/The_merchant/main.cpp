#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define MAX_N 50050
#define Max(a,b) ((a) > (b) ? (a) : (b))
#define Min(a,b) ((a) < (b) ? (a) : (b))

struct {int v,next,index,w; }edge[MAX_N * 2];
struct {int head;bool visited; } UF[MAX_N];
struct {int head,tail,lca; }rec[MAX_N];
struct {int v,next,index,id;}Query[MAX_N * 2];
struct {int index,next;}Ans[MAX_N * 2];

int n,q,edgeNum = 1,queryNum = 1,ansNum = 1;
int edgeHead[MAX_N],queryHead[MAX_N],ansHead[MAX_N];
int in[MAX_N],out[MAX_N],to_anc[MAX_N],anc_to[MAX_N],price[MAX_N];
bool visited[MAX_N];

void add_edge(int u, int v, int index) {
    edge[edgeNum].v = v,edge[edgeNum].next = edgeHead[u];
    edge[edgeNum].index = index;edgeHead[u] = edgeNum++;//index用于记录哪次输入的该条边
}

void add_query(int u, int v, int index, int id) {
    Query[queryNum].v = v,Query[queryNum].next = queryHead[u];
    Query[queryNum].index = index;Query[queryNum].id = id;
    queryHead[u] = queryNum++;
}

void add_ans(int u,int index) {
    Ans[ansNum].index = index,Ans[ansNum].next = ansHead[u];
    ansHead[u] = ansNum++;
}

int Find(int x) {
    if (x == UF[x].head) return x;
    int x_head = UF[x].head;
    UF[x].head = Find(UF[x].head);
    to_anc[x] = Max(to_anc[x],Max(out[x_head] - in[x],to_anc[x_head]));
    anc_to[x] = Max(anc_to[x],Max(out[x] - in[x_head],anc_to[x_head]));
    in[x] = Min(in[x],in[x_head]);
    out[x] = Max(out[x],out[x_head]);
    return UF[x].head;
}

void LCA(int root) {
    visited[root] = true;
    for (int i = queryHead[root] ; i ; i = Query[i].next) {
        int v = Query[i].v,index = Query[i].index;
        if (visited[v]) {
            int lca = Find(v);
            add_ans(lca,index);
        }
    }
    for (int i = edgeHead[root] ; i ; i = edge[i].next) {
        if (!visited[edge[i].v]) {
            LCA(edge[i].v);
            UF[edge[i].v].head = root;
        }
    }
    for (int i = ansHead[root] ; i ; i = Ans[i].next) {
        int index = Ans[i].index;
        int u = rec[index].head,v = rec[index].tail;
        Find(u),Find(v);
        rec[index].lca = Max(to_anc[u],Max(anc_to[v],out[v]-in[u]));
    }
}

int main() {
    scanf("%d",&n);
    int p,u,v;
    for (int i = 1 ; i <= n ; ++i) {
        scanf("%d",&p);
        price[i] = in[i] = out[i] = p;
        UF[i].head = i,UF[i].visited = false;
    }
    for (int i = 1 ; i < n ; ++i) {
        scanf("%d%d",&u,&v);
        add_edge(u,v,i),add_edge(v,u,i);
    }
    scanf("%d",&q);
    for (int i = 1 ; i <= q ; ++i) {
        scanf("%d%d",&u,&v);
        add_query(u,v,i,1),add_query(v,u,i,0);
        rec[i].head = u,rec[i].tail = v ;
    }
    LCA(1);
    for (int i = 1; i <= q ; ++i) printf("%d\n",rec[i].lca);
    return 0;
}