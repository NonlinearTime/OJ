#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int lo = 0, hi = A.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int lval = mid == 0 ? INT32_MIN : A[mid - 1];
            int rval = mid == (A.size() - 1) ? INT32_MIN : A[mid + 1];
            int mval = A[mid];
            if (lval < mval && mval < rval) lo = mid + 1;
            else if(lval > mval && mval > rval) hi = mid - 1;
            else return mid;
        }
        return -1;
    }
};


int main() {
    Solution s ;
    vector<int> t = {18,29,38,59,98,100,99,98,90};
    cout << s.peakIndexInMountainArray(t) << endl;
    return 0;
}