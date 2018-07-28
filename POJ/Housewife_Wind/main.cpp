#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;

#define MAX_N 100050
#define lowbit(a) ((a) & (-a))

typedef long long LL;

struct edge {int v,next,index,w;};

struct node {
    int head,tail,weight;
}rec[MAX_N];

int n,q,s,edgeNum ,dep , cnt;

LL in[MAX_N],out[MAX_N],C[MAX_N * 2];
int head[MAX_N * 2];
int Rank[MAX_N * 2],first[MAX_N];
int edgeHead[MAX_N];
int M[MAX_N * 2][20];
int deep[MAX_N];
bool visited[MAX_N];
edge edges[MAX_N * 2];

LL getSum(LL x) {
    LL ans = 0 ;
    for (LL i = x ; i > 0 ; i -= lowbit(i)) ans += C[i];
    return ans;
}

void add(LL x, LL y) {
    for (LL i = x ; i <= 2 * n ; i += lowbit(i)) C[i] += y;
}

void add_edge(int u, int v, int w, int index) {
    edges[edgeNum].v = v,edges[edgeNum].next = edgeHead[u];
    edges[edgeNum].w = w,edges[edgeNum].index = index;//index用于记录哪次输入的该条边
    edgeHead[u] = edgeNum++;
}

void dfs(int root, int depth) {
    in[root] = ++cnt;//第一次访问时间戳
    first[root] = ++dep;//每个节点第一次访问的时间戳
    deep[dep] = depth;//计算每次访问到的节点深度
    Rank[dep] = root;//计算每个时间戳访问的节点
    visited[root] = true;//已经访问节点
    for (int i = edgeHead[root] ; i ; i = edges[i].next)
        if (!visited[edges[i].v]) {
            dfs(edges[i].v,depth + 1);
            head[edges[i].index] = edges[i].v;//记录某次输入的边是从哪个点走到哪个点
            Rank[++dep] = root;//欧拉环游路径记录，非DFS序
            deep[dep] = depth;
        }
    out[root] = ++cnt;//第二次访问时间戳
}

void pre_RMQ(int nv) {
    int i,j;
    for (i = 0; i < nv ; ++i) M[i][0] = i;
    for (j = 1 ; 1 << j <= nv ; ++j)
        for (i = 0 ;i + (1 << j) - 1 < nv; ++i)
            if (deep[M[i][j - 1]] < deep[M[i + (1 << (j - 1))][j - 1]])
                M[i][j] = M[i][j - 1];
            else
                M[i][j] = M[i + (1 << (j - 1))][j - 1];
}

int RMQ(int left , int right) {
    int k=(int)(log((right-left+1)*1.0)/log(2.0));
    if (deep[M[left][k]] < deep[M[right-(1<<k)+1][k]])//注意是根据深度数组找出最小值
        return M[left][k] ;
    else
        return M[right-(1<<k)+1][k] ;   //注意是预处理的逆过程
}

int LCA(int s, int t) {
    int i = first[s], j = first[t];
    if (i <= j) return Rank[RMQ(i,j)];
    else return Rank[RMQ(j,i)];
}

void init() {
    memset(visited, false, sizeof(visited));
    memset(edgeHead,0, sizeof(edgeHead));
    memset(C,0, sizeof(C));
    edgeNum = 1,dep = -1,cnt = -1;
}

int main() {
    while (scanf("%d%d%d",&n,&q,&s) != EOF) {
        init();
        int u,v,w;
        for (int i = 1 ; i < n ; ++i) {
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,w,i) , add_edge(v,u,w,i);
            rec[i].head = u,rec[i].tail = v,rec[i].weight = w;
        }
        dfs(1,0);
        pre_RMQ(2 * n - 1);
        for (int i = 1 ; i < n ; ++i) {
            add(in[head[i]],rec[i].weight);
            add(out[head[i]],-rec[i].weight);       //根据进入节点、退出节点时间计算距离根节点的距离
        }
        for (int i = 0 ; i < q ; ++i) {
            scanf("%d",&u);
            if (!u) {
                scanf("%d",&v);
                LL dis = getSum(in[s]) + getSum(in[v]) - 2 * getSum(in[LCA(s,v)]);//计算距离
                printf("%d\n",dis);
                s = v;//根改当前位置
            } else {
                scanf("%d%d",&v,&w);
                int delta = w - rec[v].weight;
                add(in[head[v]],delta);
                add(out[head[v]],-delta);
                rec[v].weight = w;
            }
        }
    }
    return 0;
}