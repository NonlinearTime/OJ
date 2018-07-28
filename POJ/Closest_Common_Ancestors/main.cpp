#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef vector<int> edges;

#define MAX_V 905

struct node{
    int head;
    bool visited;
} UF[MAX_V];

int nv,nq;
int set_v[MAX_V];
bool isRoot[MAX_V];
edges Tree[MAX_V];
edges Query[MAX_V];

int Find(int x) {
    if (x == UF[x].head) return x;
    return UF[x].head = Find(UF[x].head);
}
void init() {
    memset(set_v,0, sizeof(set_v));
    memset(isRoot, true, sizeof(isRoot));
    for (int i = 0 ; i < MAX_V ; ++i) {
        UF[i].head = i,UF[i].visited = false;
        Tree[i].clear();Query[i].clear();
    }
}

/*
 * Procedure dfs（u）；
	begin
		设置u号节点的祖先为u
		若u的左子树不为空，dfs（u - 左子树）；
		若u的右子树不为空，dfs（u - 右子树）；
		访问每一条与u相关的询问u、v
			-若v已经被访问过，则输出v当前的祖先t（t即u,v的LCA）
		标记u为已经访问，将所有u的孩子包括u本身的祖先改为u的父亲
	end
*/
void dfs(int root) {
    for (int i = 0 ; i < Tree[root].size() ; ++i) {
        dfs(Tree[root][i]);
        UF[Tree[root][i]].head = root;
    }
    UF[root].visited = true;
    for (int i = 0 ; i < Query[root].size() ; ++i) {
        if (UF[Query[root][i]].visited) set_v[Find(Query[root][i])]++;
    }
}

int main() {
    while (scanf("%d",&nv) != EOF) {
        init();
        int c_v, n_child, c_child, root;
        for (int i = 0; i < nv; ++i) {
            scanf("%d:(%d)", &c_v, &n_child);
            for (int j = 0; j < n_child; ++j) {
                scanf("%d", &c_child);
                Tree[c_v].push_back(c_child);
                isRoot[c_child] = false;
            }
        }
        for (int i = 1; i <= nv; ++i)
            if (isRoot[i]) {
                root = i;
                break;
            }
        scanf("%d", &nq);
        getchar();
        int u, v;
        for (int i = 0; i < nq; ++i) {
            while(getchar()!='(');//输入格式记号，别被坑
            scanf("%d%d", &u, &v);
            if (u == v) {
                ++set_v[u];
                continue;
            }
            Query[u].push_back(v);
            Query[v].push_back(u);
        }
        while(getchar()!=')');
        dfs(root);
        for (int i = 1; i <= nv; ++i) if (set_v[i]) printf("%d:%d\n", i, set_v[i]);
    }
    return 0;
}
