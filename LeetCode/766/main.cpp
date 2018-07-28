#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        bool ret = true;
        if (matrix.empty()) return true;
        for (int i = 0 ; i < matrix[0].size() - 1 ; ++i) {
            int row = 1;
            for (int j = i + 1 ; j < matrix[0].size() && row < matrix.size(); ++j, ++row) {
                if (matrix[row][j] != matrix[row - 1][j - 1]) return false;
            }
        }

        for (int i = 1; i < matrix.size() ; ++i) {
            int col = 1;
            for (int j = i + 1; j < matrix.size() && col < matrix[0].size() ; ++j, ++col) {
                if (matrix[j][col] != matrix[j - 1][col - 1]) return false;
            }
        }
        return ret;
    }
};

int main() {
    vector<vector<int>> A = {
            {1, 2, 3, 4},
            {5, 1, 2, 3},
            {9, 5, 1, 2}
    };
    Solution s;
    cout << s.isToeplitzMatrix(A);
    return 0;
}