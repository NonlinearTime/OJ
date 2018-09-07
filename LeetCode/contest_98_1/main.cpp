#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum_a = cal_candy_sum(A);
        int sum_b = cal_candy_sum(B);
        vector<int > ret;
        for (int i = A.size() - 1;i >= 0;i--) {
            for (int j = 0; j < B.size(); j++) {
                if (sum_a - A[i] + B[j] == sum_b - B[j] + A[i]) {
                    ret.push_back(A[i]);
                    ret.push_back(B[j]);
                    return ret;
                }
            }
        }
    }

    int cal_candy_sum(vector<int> & A) {
        int sum = 0;
        for (auto &item: A) {
            sum += item;
        }
        return sum;
    }
};

int main() {
    Solution s;

    return 0;
}