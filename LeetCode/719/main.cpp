#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
//        vector<int> hashtable(1000000, 0);
//        vector<int> dis;
//        vector<int> in_sol(1000000, 0);


//        int max_elem = INT32_MIN;
//        int min_elem = INT32_MAX;
//        for (auto &item: nums) {
//            max_elem = item > max_elem ? item : max_elem;
//            min_elem = item < min_elem ? item : min_elem;
//            hashtable[item] += 1;
//        }
//
//        int first_element = min_elem;
//        int last_element = INT32_MIN;
//        int present_element = min_elem;
//        int gap = INT32_MAX;
//
//        for (int i = min_elem ; i < max_elem ; ++i) {
//            if (hashtable[i] > 1 && !in_sol[0]) {
//                dis.emplace_back(0);
//                in_sol[0] = 1;
//            }
//            if (!hashtable[i]) continue;
//            if (hashtable[i] == 1) {
//                if (i != first_element) {
//                    last_element = present_element;
//                    present_element = i;
//                    int local_gap = (present_element - last_element);
//                    if (!in_sol[local_gap]) {
//                        in_sol.emplace_back(local_gap);
//
//                    }
//                    gap = local_gap < gap ? local_gap : gap;
//                }
//            }
//        }

//        /* hashtable:
//         * 失败，不符合题意
//         * 题目为找出所有配对，不进行去重！！！
//         * 在这样的(n * (n - 1)) / 2个元素对中找第k小
//        */
//        map<int, int> hash_table;
//        map<int, int> sol_hash;
//        for (auto &item : nums) {
//            if (hash_table.find(item) == hash_table.end()) hash_table[item] = 1;
//            else hash_table[item] += 1;
//        }
//
//        for (auto iter = hash_table.begin() ; iter != hash_table.end() ; ++iter) {
//            if (iter->second > 1 && sol_hash.find(0) == sol_hash.end()) {
//                sol_hash[0] = 1;
//            }
//
//            if (iter != hash_table.begin()) {
//                int local_gap = iter->first - (--iter)->first;
//                if (sol_hash.find(local_gap) == sol_hash.end()) {
//                    sol_hash[local_gap] = 1;
//                }
//                iter++;
//            }
//        }
//
//        auto iter = sol_hash.begin();
//        while(--k) iter++;
//        return iter->first;

        /*思路
         * 1. 对数组排序
         * 2. 对数对的距离进行二分
         * 3. 统计距离比中点小的数对数
         * */
        sort(nums.begin(), nums.end());
        int lo = 0;
        int hi = nums[nums.size() - 1] - nums[0];
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int left = 0, count = 0 ;
            for (int right = 0 ; right < nums.size(); ++right ) {
                while(nums[right] - nums[left] > mid) left++;
                count += right - left;
            }
            if (count >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};

int main() {
    Solution s;
    vector<int> t = {1,1,1};
    cout << s.smallestDistancePair(t, 2) << endl;
    return 0;
}