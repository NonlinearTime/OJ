#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> hash_table;
        vector<string> resA, resB, result;
        resA = split(A, " ");
        resB = split(B, " ");

        for (auto &item : resA) {
            if (hash_table.find(item) == hash_table.end()) {
                hash_table[item] = 1;
            } else hash_table[item] += 1;
        }
        for (auto &item : resB) {
            if (hash_table.find(item) == hash_table.end()) hash_table[item] = 1;
            else hash_table[item] += 1;
        }

        for (auto iter = hash_table.begin() ; iter != hash_table.end() ; ++iter) {
            if (iter->second == 1) result.push_back(iter->first);
        }
        return result;
    }

    vector<string> split(string s, string p) {
        string pre = s + p;
        vector<string> result;
        int size = pre.size();
        for (int i = 0 ; i < size ; ++i) {
            auto pos = pre.find(p, i);
            if (pos < size) {
                string str = pre.substr(i, pos - i);
                result.push_back(str);
                i = pos + p.size() - 1;
            }
        }
        return result;
    }
};

int main() {
    string A = "apple apple";
    string B = "banana";
    Solution s;
    vector<string> res = s.uncommonFromSentences(A, B);
    for (auto &item : res) {
        cout << item << " ";
    }
    return 0;
}