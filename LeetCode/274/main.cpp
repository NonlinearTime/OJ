#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int i = 0;
        for (i = 0 ; i < citations.size() ; ++i) {
            if (citations[i] >= citations.size() - i) break;
        }
        return static_cast<int>(citations.size() - i);
    }
};

int main() {
    Solution s;
    vector<int> t = {3,0,6,1,5};
    cout << s.hIndex(t) << endl;
    return 0;
}