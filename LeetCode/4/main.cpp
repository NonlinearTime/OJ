#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();

        if (!N1) return static_cast<double >(nums2[(N2 - 1) / 2] + nums2[N2 / 2]) / 2;
        if (!N2) return static_cast<double >(nums1[(N1 - 1) / 2] + nums1[N1 / 2]) / 2;

        if (N1 < N2) return findMedianSortedArrays(nums2, nums1);

        int lo = 0 , hi = N2 * 2;
        while (lo <= hi) {
            int mid2 = lo + (hi - lo) / 2;
            int mid1 = N1 + N2 - mid2;

            double l1 = mid1 == 0 ? INT32_MIN : nums1[(mid1 - 1) / 2];
            double l2 = mid2 == 0 ? INT32_MIN : nums2[(mid2 - 1) / 2];
            double r1 = mid1 == N1 * 2 ? INT32_MAX : nums1[mid1 / 2];
            double r2 = mid2 == N2 * 2 ? INT32_MAX : nums2[mid2 / 2];

            if (l1 > r2) lo = mid2 + 1;
            else if (l2 > r1) hi = mid2 - 1;
            else return (max(l1,l2) + min(r1, r2)) / 2;
        }
    return -1;
    }

};

int main() {
    Solution s ;
    vector<int> t1 = {1,3};
    vector<int> t2 = {2};
    cout << s.findMedianSortedArrays(t1,t2);
    return 0;
}