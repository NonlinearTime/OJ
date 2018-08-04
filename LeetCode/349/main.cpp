#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hash_table;
        vector<int> sol;
        for (auto &item : nums1)
            if (hash_table.find(item) == hash_table.end()) hash_table[item] = 1;
        for (auto &item : nums2) {
            if (hash_table.find(item) == hash_table.end() || hash_table[item] == 0) continue;
            hash_table[item] = 0;
            sol.emplace_back(item);
        }
        return sol;
    }
};

int main() {
    Solution s;
    vector<int> t1 = {1, 2, 2, 1};
    vector<int> t2 = {2, 2};
    vector<int> sol = s.intersection(t1, t2);
    for (auto &item: sol) cout << item << " ";
    return 0;
}