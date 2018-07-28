#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int p1 = nums[0] * nums[1] * nums[nums.size() - 1];
        int p2 = nums[nums.size() - 3] * nums[nums.size() - 1] * nums[nums.size() - 2];
        return p1 > p2 ? p1 : p2;
    }
};

int main() {
    Solution s;
    vector<int > t = {-12,-24,1,2,3,4};
    cout << s.maximumProduct(t);
    return 0;
}