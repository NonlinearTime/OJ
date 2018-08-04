#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash_table;
        vector<int> sol;
        for (auto &item : nums1) {
            if (hash_table.find(item) == hash_table.end()) hash_table[item] = 1;
            else hash_table[item]++;
        }

        for (auto &item: nums2) {
            if (hash_table.find(item) == hash_table.end() || hash_table[item] == 0) continue;
            sol.push_back(item);
            hash_table[item]--;
        }

        return sol;
    }
};

int main() {
    Solution s;
    vector<int> t1 = {1, 2, 2, 1};
    vector<int> t2 = {2, 2};
    vector<int> sol = s.intersect(t1, t2);
    for (auto &item: sol) cout << item << " ";
    return 0;
}