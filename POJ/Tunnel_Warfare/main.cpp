#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#include <list>
#include <cstdio>
#include <set>

using namespace std;

#define lowbit(a) ((a) & (-a))
#define MAX_NUM 50010

int n,m,C[MAX_NUM];
stack<int> s;
set<int > rec;

void add(int x, int y) {
    for (int i = x ; i <= n ; i += lowbit(i)) C[i] += y;
}

int getSum(int x) {
    int sum = 0;
    for (int i = x ; i > 0 ; i -= lowbit(i)) sum += C[i];
    return sum;
}

void init() {
    rec.clear();
    for (int i = 1 ; i != n + 1 ; ++i) add(i,1);
}

int main() {
    scanf("%d %d",&n,&m);
    char tmp[5];
    int index,ans;
    init();
    rec.insert(0);
    rec.insert(n+1);
    for (int i = 0 ; i != m; ++i) {
        scanf("%s",tmp);
        if (tmp[0] == 'D') {
            scanf("%d",&index);
            s.push(index);
            rec.insert(index);
            add(index,-1);
        } else if (tmp[0] == 'Q') {
            scanf("%d",&index);
            int low,high;
            set<int>::iterator it;
            it = rec.lower_bound(index);
            high = *it;
            low = *--it;
            if(high == index) ans = 0;
            else if (low == 0) {
                ans = getSum(high) ;
            } else if (high == n + 1) {
                ans = getSum(n) - getSum(low);
            } else {
                ans = getSum(high) - getSum(low);
            }
            printf("%d\n",ans);
        } else {
            int t = s.top();
            s.pop();
            add(t, 1);
            rec.erase(t);
        }
    }
    return 0;
}


