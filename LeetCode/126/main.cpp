#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <time.h>

using namespace std;

class Solution {
public:
    vector<string> word_list;
    vector<vector<string>> sol;
    vector<vector<int>> graph, parent, ss;
    vector<int> path, visit, depth;
    queue<int> q, qd;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        clock_t begin, end;

        wordList.push_back(beginWord);
        word_list.assign(wordList.begin(), wordList.end());
        begin = clock();
        make_graph();
        end = clock();
        cout << "total time(Graph): " << double(end-begin)/CLOCKS_PER_SEC << endl;
        visit.resize(wordList.size(), 0);
        parent.resize(wordList.size());
        depth.resize(wordList.size(), 0x7fffffff);
        bool have_begin = false, have_end = false;
        int src, dst;
        for (int i = 0 ; i < wordList.size() ; ++i) {
            if (wordList[i] == beginWord) have_begin = true, src = i;
            if (wordList[i] == endWord) have_end = true, dst = i;
        }
        if (!have_begin || !have_end) return sol;
        begin = clock();
        int len = BFS(src, dst);
        end = clock();
        cout << "total time(BFS): " << double(end-begin)/CLOCKS_PER_SEC << endl;
        if (!len) return sol;
        begin = clock();
        DFS(dst, src, path);
        end = clock();
        cout << "total time(DFS): " << double(end-begin)/CLOCKS_PER_SEC << endl;
        begin = clock();
        Transfer();
        end = clock();
        cout << "total time(Transfer): " << double(end-begin)/CLOCKS_PER_SEC << endl;
        return sol;
    }

    void make_graph() {
        for (int i = 0 ; i < word_list.size() ; ++i) {
            vector<int> edges;
            for (int j = 0 ; j < word_list.size() ; ++j) {
                if (i != j && is_neighbor(word_list[i], word_list[j])) {
                    edges.push_back(j);
                }
            }
            graph.push_back(edges);
        }
    }

    bool is_neighbor(string a, string b) {
        int cnt = 0;
        for (auto i = a.begin(), j = b.begin(); i != a.end(), j != b.end() ; ++i, ++j) {
            if (*i != *j) cnt++;
            if (cnt > 1) return false;
        }
        return cnt == 1;
    }

    int BFS (int src, int dst) {
        int d = 0, last_d;
        q.push(src);
        visit[src] = 1;
        depth[src] = d;
        bool reachable = false;
        int min_len = 0;
        while (!q.empty()) {
            int n = q.size();

            for (int i = 0 ; i < n ; ++i) {
                int head = q.front();
                q.pop();
                for (int i = 0; i < graph[head].size(); ++i) {
                    int next = graph[head][i];
                    if (next == dst) reachable = true, min_len = d + 1;
                    if (depth[next] > depth[head]) {
                        parent[next].push_back(head);
                        depth[next] = d + 1;
                    }

                    if (!visit[next]) {
                        visit[next] = 1;
                        q.push(next);
                    }
                }
            }
            d++;


        }
        return reachable ? min_len : 0;
    }

    void DFS(int src, int dst, vector<int> &path) {
        vector<int> local_path(path);
        local_path.push_back(src);
        if (src == dst) {
            ss.push_back(local_path);
            return;
        }

        for (int i = 0 ; i < parent[src].size() ; ++i) {
            DFS(parent[src][i], dst, local_path);
        }
    }

    void Transfer() {
        for (int i = 0 ; i < ss.size() ; ++i) {
            vector<string> path;
            while(!ss[i].empty()) {
                path.push_back(word_list[ss[i].back()]);
                ss[i].pop_back();
            }
            sol.push_back(path);
        }
    }
};

int main() {
    Solution s;
    vector<string> t = {"hot","dot","dog","lot","log","cog"};
    string beginWord = "hit";
    string endWord = "cog";
    vector<vector<string>> res = s.findLadders(beginWord, endWord, t);
    for (int i = 0 ; i < res.size() ; ++i) {
        for (int j = 0 ; j < res[i].size() ; ++j)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}