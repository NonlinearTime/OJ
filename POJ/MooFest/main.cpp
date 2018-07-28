#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define lowbit(a) ((a) & (-a))
#define MAX_NUM 20010

struct Item {
    int index,volume;
    bool operator<(const Item& s) const {
        return volume < s.volume;
    }
};

int n;
int C[MAX_NUM];
int X[MAX_NUM];
Item rec[MAX_NUM];
long long M;

void add (int x, int y , int *tree) {
    for (int i = x ; i <= M ; i += lowbit(i)) tree[i] +=y;
}

long long getSum(int x, int *tree) {
    long long ans = 0;
    for (int i = x ; i > 0 ; i -= lowbit(i)) ans += tree[i];
    return ans;
}

void init() {
    memset(C,0,sizeof(C));
    memset(X,0,sizeof(X));
    scanf("%d",&n);
    int volume,index;
    M = 0;
    for (int i = 0 ; i!= n ; ++i) {
        scanf("%d%d",&volume,&index);
        rec[i].volume = volume;
        rec[i].index = index;
        M = index > M ? index : M;
    }
    sort(rec , rec+n);
}

void getAns() {
    long long ans = 0, total_sum = 0,total_num = 0;
    long long left_num, left_sum,left_ans,right_ans;
    for (int i = 0 ; i != n ; ++i) {
        add(rec[i].index,1,X);
        add(rec[i].index,rec[i].index,C);
        total_num += 1;
        total_sum += rec[i].index;
        left_num = getSum(rec[i].index - 1,X);
        left_sum = getSum(rec[i].index - 1,C);
        left_ans = (left_num * rec[i].index - left_sum) * rec[i].volume;
        right_ans = (total_sum - left_sum - rec[i].index - rec[i].index * (total_num - left_num - 1)) * rec[i].volume;
        ans += left_ans + right_ans;
    }
    printf("%lld\n",ans);
}

int main() {
    init();
    getAns();
    return 0;
}