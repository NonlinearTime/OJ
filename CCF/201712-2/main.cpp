#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;

int main() {
    cin >> n >> k;
    queue<int> q;
    int num = 0, tmp;
    for (int i = 1 ; i < n + 1 ; ++i) q.push(i);
    while (1) {
        if (q.size() == 1) break;
        num++;
        if (num % k == 0 || num % 10 == k) {
            q.pop();
            continue;
        }
        tmp = q.front();
        q.pop();
        q.push(tmp);
    }
    cout << q.front() << endl;
    return 0;
}