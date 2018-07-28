#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> B (A.size(), vector<int> (A[0].size()));
        for (int i = 0 ; i < A.size() ; ++i) {
            B[i].clear();
            while (!A[i].empty()) {
                int tmp = A[i].back();
                A[i].pop_back();
                B[i].push_back(1 - tmp);
            }
        }
        return B;
    }
};

int main() {
    Solution s;
    vector<vector<int>> A (3, vector<int> (3));

    A[0][0] = 1;
    A[0][1] = 1;
    A[0][2] = 0;

    A[1][0] = 1;
    A[1][1] = 0;
    A[1][2] = 1;

    A[2][0] = 0;
    A[2][1] = 0;
    A[2][2] = 0;

    vector<vector<int>> sol = s.flipAndInvertImage(A);

    for (int i = 0 ; i < sol.size(); ++i) {
        for (auto &item : sol[i]){
            cout << item << " ";
        }
        cout << endl;
    }
    return 0;
}