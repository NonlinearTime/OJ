#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef vector<int> edges;

#define MAX_V 40010
#define MAX_Q 200000

struct node{
    int head;
    bool visited;
} UF[MAX_V];

struct query{
    int head,tail,lca;
};

int nv,nq,ne;
bool isRoot[MAX_V];
bool visited[MAX_V];
int Dis[MAX_V];
query rec[MAX_Q];
edges Tree[MAX_V];
edges Query[MAX_V];
edges Index[MAX_V];
edges Length[MAX_V];

int Find(int x) {
    if (x == UF[x].head) return x;
    return UF[x].head = Find(UF[x].head);
}

void init(int n) {
    memset(isRoot, true, sizeof(isRoot));
    memset(Dis,0, sizeof(Dis));
    memset(visited, false, sizeof(visited));
    for (int i = 0 ; i <= n ; ++i) {
        UF[i].head = i,UF[i].visited = false;
        Tree[i].clear();Query[i].clear();
        Length[i].clear();Index[i].clear();
    }
}

void LCA(int root) {
    visited[root] = true;
    for (int i = 0 ; i < Tree[root].size() ; ++i) {
        int v = Tree[root][i];
        if (!visited[v]) {
            LCA(Tree[root][i]);
            UF[Tree[root][i]].head = root;
        }
    }
    UF[root].visited = true;
    for (int i = 0 ; i < Query[root].size() ; ++i) {
        int v = Query[root][i],lca = Find(v),index = Index[root][i];
        if (UF[v].visited) {
            rec[index].lca = lca;
        }
    }
}

void dfs(int root , int length){
    if (UF[root].visited) return;
    UF[root].visited = true;
    for (int i = 0 ; i < Tree[root].size() ; ++i)
        dfs(Tree[root][i] , length + Length[root][i]);
    Dis[root] = length;
}

int main() {
    while (scanf("%d %d",&nv,&ne) != EOF) {
        init(nv);
        int u,v,w,root,lca;
        char t[5];
        for (int i = 0; i < ne; ++i) {
            scanf("%d%d%d%s",&u,&v,&w,t);
            Tree[u].push_back(v);
            Tree[v].push_back(u);
            Length[u].push_back(w);
            Length[v].push_back(w);
        }
        root = 1;
        scanf("%d", &nq);
        getchar();
        for (int i = 0; i < nq; ++i) {
            scanf("%d %d",&u,&v);
            Query[u].push_back(v);
            Query[v].push_back(u);
            Index[u].push_back(i),Index[v].push_back(i);
            rec[i].head = u,rec[i].tail = v;
        }
        dfs(root,0);
        LCA(root);
        for (int i = 0 ; i < nq ; ++i) {
            u = rec[i].head, v = rec[i].tail,lca = rec[i].lca;
            int d = Dis[u] + Dis[v] - 2 * Dis[lca];
            printf("%d\n",d);
        }
    }
    return 0;
}
