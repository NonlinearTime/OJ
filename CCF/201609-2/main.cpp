#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define COL 5
#define ROW 20
#define MAXN 105

int main() {
    vector<int> record[MAXN];
    int N[ROW] = {0};
    int n;
    cin >> n;
    for (int k = 0 ; k < n ; ++k) {
        int i, t;
        cin >> t;
        for (i = 0 ; i < ROW ; ++i)
            if (COL - N[i] >= t)
                break;
        if (i != ROW) {
            for (int j = N[i] + 1; j < N[i] + t + 1 ; ++j) record[k].push_back(i * COL + j);
            N[i] += t;
            continue;
        }
        for (i = 0 ; i < ROW; ++i) {
            int l = COL - N[i];
            if (l != 0 && t > 0) {
                for (int j = N[i] + 1; j < N[i] + l + 1 ; ++j) record[k].push_back(i * COL + j);
                t -= l;
            }
        }
    }
    for (int i = 0 ; i < n ; ++i) {
        for (int j = 0 ; j < record[i].size(); ++j)
            cout << record[i][j] << " ";
        cout << endl;
    }
    return 0;
}