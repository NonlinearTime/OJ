#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    int n , t, ans = -1;
    vector<int > record;
    cin >> n;
    while (n--) {
        cin >>t;
        record.push_back(t);
    }
    for (int i = 0 ; i < record.size() - 1 ; ++i) {
        t = abs(record[i] - record[i + 1]);
        if (t > ans) ans = t;
    }
    cout << ans << endl;
    return 0;
}