#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    int n,k,tmp;

    int count = 0, weight = 0;
    queue<int> q;
    cin >> n >> k;
    int cakes[n+1];
    for (int i = 1 ; i < n +1 ; ++i) {
        q.push(i);
        cin >> cakes[i];
    }
    for (int i = 1 ; i < n + 1; ++i) {
        tmp = q.front();
        q.pop();
        weight += cakes[tmp];
        if (weight >= k) {
            weight = 0 ;
            count++;
        }
    }
    if (weight) count++;
    cout << count << endl;
    return 0;
}