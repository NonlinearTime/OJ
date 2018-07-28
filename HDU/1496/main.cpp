#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <unordered_map>

using namespace std;

#define MAX_N 1000005

int32_t hash_table[2 * MAX_N + 100];

int main() {
    int32_t a, b, c, d, cnt;
    while (cin >> a >> b >> c >> d) {
        cnt = 0;
        memset(hash_table, 0, sizeof(hash_table));
        if (a > 0 && b > 0 && c > 0 && d > 0 || a < 0 && b < 0 && c < 0 && d < 0) {
            cout << cnt << endl;
            continue ;
        }
        for (int32_t i = 1 ; i <= 100 ; ++i) {
            for (int32_t j = 1 ; j <= 100 ; ++j) {
                hash_table[MAX_N + a * i * i + b * j * j] += 1;
            }
        }
        for (int32_t i = 1 ; i <= 100 ; ++i) {
            for (int32_t j = 1 ; j <= 100 ; ++j) {
                cnt += hash_table[MAX_N - c * i * i - d *j *j];
            }
        }
        cout << cnt * 16 << endl;
    }
    return 0;
}