#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        if (A.empty()) return A;
        vector<vector<int>> B (A[0].size(), vector<int> (A.size()));
        for (int i = 0 ; i < A.size() ; ++i) {
            for (int j = 0 ; j < A[i].size() ; ++j)
                B[j][i] = A[i][j];
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

    vector<vector<int>> sol = s.transpose(A);

    for (int i = 0 ; i < sol.size(); ++i) {
        for (auto &item : sol[i]){
            cout << item << " ";
        }
        cout << endl;
    }
    return 0;
}