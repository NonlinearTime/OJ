#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0 ; i < nums.size() - 1 ; ++i) {
            if (nums[i] > nums[i + 1]) {
                cnt++;
                if (cnt > 1) return false;
                if(i < nums.size() - 2 && i > 0 && nums[i - 1] > nums[i + 1] && nums[i] > nums[i + 2]) return false;
            }
        }
        return cnt <= 1;
    }
};

int main() {
    Solution s;
    vector<int> t = {1,2,4,5,3};
    cout << s.checkPossibility(t);
    return 0;
}