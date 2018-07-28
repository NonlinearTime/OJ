#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <unordered_map>
#include <vector>

using namespace std;

#define MAX_LEN 505

int32_t a[MAX_LEN];
int32_t b[MAX_LEN];
int32_t dp[MAX_LEN][MAX_LEN];

unordered_map<string , size_t > a_rec, b_rec;


int main() {
    size_t n, a_len, b_len;
    size_t pre;
    string k_w;
    cin >> n;
    while (n--) {
        cin >> a_len;
        for (size_t i = 0 ; i < a_len ; ++i) cin >> a[i];
        cin >> b_len;
        for (size_t i = 0 ; i < b_len ; ++i) cin >> b[i];

        memset(dp, 0, sizeof(dp));
        for (size_t i = 0 ; i < a_len ; ++i) {
            int max_v = 0;
            for (size_t j = 0 ; j < b_len ; ++j) {
                dp[i][j] = dp[i-1][j];
                if (a[i] > b[j] && dp[i][j] > max_v) max_v = dp[i][j];
                else if (a[i] == b[j]) dp[i][j] = max_v + 1;
            }
        }
        int ans = 0;
        for (size_t i = 0 ; i < b_len ; ++i) ans = ans > dp[a_len - 1][i] ? ans : dp[a_len - 1][i];
        cout << ans << endl;

        if (n) cout << endl;
    }
    return 0;
}