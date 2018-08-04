#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0 , hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int mval = nums[mid];
            if (target > mval) lo = mid + 1;
            else if (target < mval) hi = mid - 1;
            else return mid;
        }
        return -1;
    }
};

int main() {
    vector<int> t = {-1,0,3,5,9,12};
    int target = 9;
    Solution s;
    cout << s.search(t,target) << endl;
    return 0;
}