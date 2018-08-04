#include <iostream>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1 , hi = n;
        if (n == 1) return n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid == 1 && isBadVersion(mid)) return mid;
            if (!isBadVersion(mid - 1) && isBadVersion(mid)) return mid;
            else if (isBadVersion(mid - 1) && isBadVersion(mid)) hi = mid - 1;
            else lo = mid + 1;
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

