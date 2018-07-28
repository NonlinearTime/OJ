#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0 ; i < nums.size(); i += 2) sum += nums[i];
        return sum;
    }
};

int main() {
    vector<int> t = {1,2,3,4,2,1,-1000,2,4,0,10,1000,1001};
    Solution s;
    cout << s.arrayPairSum(t) << endl;
    return 0;
}