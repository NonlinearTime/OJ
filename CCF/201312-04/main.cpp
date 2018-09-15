#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

typedef long long LL;

#define mod 1000000007

LL dp[1001][6];

void solver(int n) {
    memset(dp, 0, sizeof(dp));
    dp[1][0] = 1;
    for (int i =2 ; i <= n ; ++i) {
        dp[i][0] = 1;
        dp[i][1] = (2 * dp[i-1][1])% mod + dp[i-1][0] % mod;
        dp[i][2] = dp[i-1][2] % mod + dp[i-1][0] % mod;
        dp[i][3] = (2 * dp[i-1][3]) % mod + dp[i-1][1] % mod;
        dp[i][4] = (2 * dp[i-1][4]) % mod + dp[i-1][1] % mod + dp[i-1][2] % mod;
        dp[i][5] = (2 * dp[i-1][5]) % mod + dp[i-1][3] % mod + dp[i-1][4] % mod;
    }
}


int main() {
    int n;
    cin >> n;
    solver(n);
    cout << dp[n][5] % mod << endl;
    return 0;
}