#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        auto n = static_cast<int>(nums.size());
        sort(nums.begin(), nums.end());
        vector<vector<int>> sol;

        for (int i = 0 ; i < n - 2; ++i) {
            if (i == 0 || nums[i] > nums[i - 1]) {
                int j = i + 1;
                int k = n - 1;
                while (j < k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> tri;
                        tri.clear();
                        tri.emplace_back(nums[i]);
                        tri.emplace_back(nums[j]);
                        tri.emplace_back(nums[k]);
                        sol.emplace_back(tri);
                        j++;
                        k--;
                        while (j < k && nums[j] == nums[j - 1]) j++;
                        while (j < k && nums[k] == nums[k + 1]) k--;
                    } else if (nums[i] + nums[j] + nums[k] < 0) j++;
                    else k--;
                }
            }
        }
        return sol;
    }
};

int main() {
    Solution s;
    vector<int> t = {-1, 0, 1, 2, -1, -4};
    auto sol = s.threeSum(t);
    for (int i = 0 ; i < sol.size(); ++i) {
        for (int j = 0 ; j < sol[i].size() ; ++j) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}