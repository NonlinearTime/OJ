#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

#define Max_Nodes 1000

struct Edge {
    int start;
    int end;

    Edge(int s,int e):start(s),end(e) {}
};

vector<int> G[Max_Nodes];
vector<Edge> edges;

int num_nodes;
int num_left;
int num_right;
int num_edges;

int matching[Max_Nodes]; /* 存储求解结果 */
int check[Max_Nodes];

bool dfs(int u)
{
    for (auto i = G[u].begin(); i != G[u].end(); ++i) { // 对 u 的每个邻接点
        int v = edges[*i].end;
        //printf("(%d,%d)",edges[*i].start,edges[*i].end);
        if (!check[v]) {     // 要求不在交替路中
            check[v] = true; // 放入交替路
            if (matching[v] == -1 || dfs(matching[v])) {
                // 如果是未盖点，说明交替路为增广路，则交换路径，并返回成功
                matching[v] = u;
                matching[u] = v;
                return true;
            }
        }
    }
    return false; // 不存在增广路，返回失败
}

int hungarian()
{
    int ans = 0;
    memset(matching, -1, sizeof(matching));
    for (int u=0; u < num_left; ++u) {
        if (matching[u] == -1) {
            memset(check, 0, sizeof(check));
            if (dfs(u))
                ++ans;
        }
    }
    return ans;
}

int readGraph() {
    int row,col;
    while(cin >> row >> col) {
        int left=0,right=0;
        char oringinalGraph[row][col];
        for (int i = 0 ; i!= row ; i++) {
            //scanf("%s",oringinalGraph[i]);
            cin >> oringinalGraph[i];
        }
        int binGraph[row][col];
        for (int i = 0 ; i!=row ; ++i) {
            for (int j = 0 ; j != col ; ++j) {
                if (oringinalGraph[i][j] != '#') {
                    if (i % 2 == 0) {                             //偶数排第奇数个为黑
                        if (j % 2 == 1) left++; else right++;
                        binGraph[i][j] = j % 2;
                    } else {                                      //奇数排第奇数个为白
                        if (j % 2 == 1) right++; else left++;
                        binGraph[i][j] = 1 - j % 2;
                    }
                }
                if (oringinalGraph[i][j] == '#') binGraph[i][j] = -1;
            }
        }
        int leftcount=0,rightcount=0;
        int digiGraoh[row][col];
        for (int i = 0 ; i!=row ; ++i) {
            for (int j = 0 ; j != col ; ++j) {
                if (binGraph[i][j] == 1) digiGraoh[i][j]=leftcount++;
                else if(binGraph[i][j] ==0) digiGraoh[i][j]=left+rightcount++;
                else digiGraoh[i][j] = -1;
            }
        }
        for (int i = 0 ; i!=row ; ++i) {
            for (int j = 0 ; j != col ; ++j) {
                cout <<  digiGraoh[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0 ; i!=row ; ++i) {
            for (int j = 0 ; j != col ; ++j) {
                if(digiGraoh[i][j]!=-1) {
                    if(i-1 > 0) {
                        Edge e(digiGraoh[i][j],digiGraoh[i-1][j]);
                        if(e.end!=-1) {
                            edges.push_back(e);
                            G[digiGraoh[i][j]].push_back(edges.size()-1);
                        }
                    }
                    if(i+1 < row) {
                        Edge e(digiGraoh[i][j],digiGraoh[i+1][j]);
                        if(e.end!=-1) {
                            edges.push_back(e);
                            G[digiGraoh[i][j]].push_back(edges.size()-1);
                        }
                    }
                    if(j-1 > 0) {
                        Edge e(digiGraoh[i][j],digiGraoh[i][j-1]);
                        if(e.end!=-1) {
                            edges.push_back(e);
                            G[digiGraoh[i][j]].push_back(edges.size()-1);
                        }
                    }
                    if(j+1 < col) {
                        Edge e(digiGraoh[i][j],digiGraoh[i][j+1]);
                        if(e.end!=-1) {
                            edges.push_back(e);
                            G[digiGraoh[i][j]].push_back(edges.size()-1);
                        }
                    }
                 }
            }
        }
        num_left = left;
        num_right = right;
        num_nodes = left + right;
        num_edges = edges.size();
        int ans = hungarian();
        cout << ans  <<" "<< num_nodes << " ";
        if (ans < num_nodes / 2 ) cout << "no" << endl;
        else cout << "yes" << endl;
    }
}

int main() {
    readGraph();

    return 0;
}