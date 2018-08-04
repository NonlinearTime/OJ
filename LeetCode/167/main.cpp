#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0, hi = numbers.size() - 1;
        vector<int> sol ;
//        while (lo < hi) {
//            int mid = lo + (hi - lo) / 2;
//            int lval = numbers[lo];
//            int hval = numbers[hi];
//            int mval = numbers[mid];
//            if (target < lval + mval) hi = mid;
//            if (target > mval + hval) lo = mid;
//            if (target < lval + hval) hi--;
//            else if (target > lval + hval) lo++;
//            else {
//                sol.push_back(lo + 1);
//                sol.push_back(hi + 1);
//                break;
//            }
//        }
//        return sol;
        while (true) {
            int lval = numbers[lo];
            int hval = numbers[hi];
            if (target > lval + hval) lo++;
            else if (target < lval + hval) hi--;
            else break;
        }
        sol.push_back(lo + 1);
        sol.push_back(hi + 1);
        return  sol;
    }
};

int main() {
    Solution s;
    vector<int> t = {3,24,50,79,88,150,345};
    int target = 200;
    vector<int> sol = s.twoSum(t, target);
    for (auto &item :sol) {
        cout << item << " ";
    }
    return 0;
}