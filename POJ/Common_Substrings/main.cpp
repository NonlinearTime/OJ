#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN (100020 * 2)

struct node{
    int h,n;
} s[MAXN];

int K;
char A[MAXN],B[MAXN];
int raw[MAXN ];

//rnk从0开始
//sa从1开始,因为最后一个字符(最小的)排在第0位
//height从1开始,因为表示的是sa[i - 1]和sa[i]
//倍增算法 O(nlogn)
int wa[MAXN], wb[MAXN], wv[MAXN], ws_[MAXN];

int SA[MAXN];
int *Rank,*height;
//Suffix函数的参数m代表字符串中字符的取值范围,是基数排序的一个参数,如果原序列都是字母可以直接取128,如果原序列本身都是整数的话,则m可以取比最大的整数大1的值
//待排序的字符串放在r数组中,从r[0]到r[n-1]，长度为n
//为了方便比较大小,可以在字符串后面添加一个字符,这个字符没有在前面的字符中出现过,而且比前面的字符都要小
//同上,为了函数操作的方便,约定除r[n-1]外所有的r[i]都大于0,r[n-1]=0
//函数结束后,结果放在sa数组中,从sa[0]到sa[n-1]
void Suffix(int *r, int *sa, int n, int m)
{
    int i, j, k, *x = wa, *y = wb, *t;
    //对长度为1的字符串排序
    //一般来说,在字符串的题目中,r的最大值不会很大,所以这里使用了基数排序
    //如果r的最大值很大,那么把这段代码改成快速排序
    for(i = 0; i < m; ++i) ws_[i] = 0;
    for(i = 0; i < n; ++i) ws_[x[i] = r[i]]++;//统计字符的个数
    for(i = 1; i < m; ++i) ws_[i] += ws_[i - 1];//统计不大于字符i的字符个数
    for(i = n - 1; i >= 0; --i) sa[--ws_[x[i]]] = i;//计算字符排名
    //基数排序
    //x数组保存的值相当于是rank值
    for(j = 1, k = 1; k < n; j *= 2, m = k)
    {
        //j是当前字符串的长度,数组y保存的是对第二关键字排序的结果
        //第二关键字排序
        for(k = 0, i = n - j; i < n; ++i) y[k++] = i;//第二关键字为0的排在前面
        for(i = 0; i < n; ++i) if(sa[i] >= j) y[k++] = sa[i] - j;//长度为j的子串sa[i]应该是长度为2 * j的子串sa[i] - j的后缀（第二关键字）,对所有的长度为2 * j的子串根据第二关键字来排序
        for(i = 0; i < n; ++i) wv[i] = x[y[i]];//提取第一关键字
        //按第一关键字排序 (原理同对长度为1的字符串排序)
        for(i = 0; i < m; ++i) ws_[i] = 0;
        for(i = 0; i < n; ++i) ws_[wv[i]]++;
        for(i = 1; i < m; ++i) ws_[i] += ws_[i - 1];
        for(i = n - 1; i >= 0; --i) sa[--ws_[wv[i]]] = y[   i];//按第一关键字,计算出了长度为2 * j的子串排名情况
        //此时数组x是长度为j的子串的排名情况,数组y仍是根据第二关键字排序后的结果
        //计算长度为2 * j的子串的排名情况,保存到数组x
        t = x;
        x = y;
        y = t;
        for(x[sa[0]] = 0, i = k = 1; i < n; ++i)
            x[sa[i]] = (y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + j] == y[sa[i] + j]) ? k - 1 : k++;
        //若长度为2 * j的子串sa[i]与sa[i - 1]完全相同,则他们有相同的排名
    }
}

void calheight(int *r,int *sa,int n)        //计算height数组
{
    int i,j,k=0;
    Rank = wa;
    height = wb;
    for(i=1; i<=n; i++)Rank[sa[i]]=i;
    for(i=0; i<n; height[Rank[i++]]=k)
        for(k?k--:0,j=sa[Rank[i]-1]; r[i+k]==r[j+k]; k++);
}

int main() {
    while(scanf("%d",&K) && K ) {
        scanf("%s%s",A,B);
        long LA = 0,LB = 0;
        long n = 0;
        while ((raw[n++] = A[LA++])) ;
        raw[n - 1] = '$';
        while ((raw[n++] = B[LB++])) ;
        raw[n - 1] = 0;
        //printf("%s\n",raw);
        Suffix(raw,SA,n,130);//求出所有后缀
        calheight(raw,SA,n-1);//计算height数组，注意最后一个参数为n-1
        long long tot = 0 ,cnt = 0;//记录每个分组对答案的贡献以及有贡献的元素个数
        long top = 0;//单调栈的栈顶
        long long sum = 0;
        //第一次扫描找出A对B的大于K的子串个数
        for (int i = 1 ; i < n ; ++i ) {//开始分组
            if (height[i] < K) top = tot = 0;//不满足要求清零，重新分组
            else {
                cnt = 0;
                if(SA[i - 1] < LA - 1) cnt++,tot+=height[i] - K + 1;
                while (top > 0 && height[i] <= s[top - 1].h) {
                    top--;
                    tot -= s[top].n * (s[top].h - height[i]);//需要将之前多增加的清零
                    cnt += s[top].n;//累加，因为
                }
                s[top].h = height[i],s[top++].n = (int)cnt;
                if (SA[i] > LA - 1) sum += tot;
            }
        }
        //第二次扫描找出B对A的大于K的子串个数
        tot =  top = 0;
        for (int i = 1 ; i < n ; ++i ) {//开始分组
            if (height[i] < K) top = tot = 0;//不满足要求清零，重新分组
            else {
                cnt = 0;
                if(SA[i - 1] > LA - 1) cnt++,tot+=height[i] - K + 1;
                while (top > 0 && height[i] <= s[top - 1].h) {
                    top--;
                    tot -= s[top].n * (s[top].h - height[i]);//需要将之前多增加的清零
                    cnt += s[top].n;//累加，因为
                }
                s[top].h = height[i],s[top++].n = (int)cnt;
                if (SA[i] < LA - 1) sum += tot;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}

/*用未出现过的字符连接两个字符串
 * 求出height数组
 * 求出某个属于A的后缀与某个属于B的后缀的最长公共子串
 * 这个最长公共子串长度为L的话，那么可以增加L-K+1个符合要求的子串
 * 时间复杂度：
 * 先按K分组的话，需要找出每个组中的每一个A串后缀与B串后缀的匹配，
 * 求出最长匹配，时间复杂度为n^2
 */