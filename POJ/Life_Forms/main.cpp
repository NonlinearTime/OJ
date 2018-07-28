#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 100000+1000

//rnk从0开始
//sa从1开始,因为最后一个字符(最小的)排在第0位
//height从1开始,因为表示的是sa[i - 1]和sa[i]
//倍增算法 O(nlogn)
int wa[MAXN], wb[MAXN], wv[MAXN], ws_[MAXN];
char raw[MAXN];
int r[MAXN];
int SA[MAXN];
int *Rank,*height,*pos,rec[MAXN];
int len[115];
int size;
bool visited[115];
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

/*思想:
 * 从前往后遍历height数组，如果存在连续的元素串，且其中每个元素都要大于给定的mid值
 * 那么这样一个串可以视为一个分组，这个分组里元素代表的所有后缀都有着一个公共的前缀
 * 所以只需要对其计数即可，若在遍历过程中有小于mid的情况，意味着此元素不属于分组，
 * 那么停止计数，重新开始分组操作。
*/
bool calculate(int mid, int n, int k) {
    int num = 0 , ans = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 1 ; i <= n ; ++i) {
        if (height[i] >= mid) {
            if (!visited[rec[SA[i]]] && rec[SA[i]]) ans++ , visited[rec[SA[i]]] = true;         //判断该后缀所在字符串是否已经计算过
            if (!visited[rec[SA[i - 1]]] && rec[SA[i - 1]]) ans++, visited[rec[SA[i - 1]]] = true;
        } else {
            if (ans > k / 2) pos[++num] = SA[i - 1];
            ans = 0;
            memset(visited, false, sizeof(visited));
        }
    }
    if (ans > k / 2) pos[++num] = SA[n];
    if (num) {
        pos[0] = num;
        return true;
    }
    return false;
}

int main() {
    int num,n = 0,line = 0;
    len[0] = - 1;
    while(scanf("%d",&num) && num) {
        size = 0;
        n = 0;
        memset(rec,0, sizeof(rec));     //每轮输入都要初始化！
        for (int i = 0 ; i != num ; ++i) {
            scanf("%s",raw+n);          //这个技巧很巧妙！
            for (;raw[n] != '\0';n++) r[n] = raw[n], rec[n] = size + 1;     //将所有的字符串链接在一起，用分隔符分割，并记录每个字符对应的字符串
            r[len[++size] = n++] = 150 + i;     //每个分隔符需要不同！
        }
        r[n - 1] = 0;
        Suffix(r,SA,n,250);             //创建后缀数组
        calheight(r,SA,n - 1);          //计算height数组，注意最后一个参数为n-1
        pos = wv;
        pos[0] = 0;
        int Left = 1,Right = n,Middle;  //二分法搜索全部长度子串，如果对于长度k，不存在符合题目要求的子串，那么将k缩小至一半。
        while (Left <= Right) {         //同理，如果存在的话，那么将k增大为左右坐标的均值
            Middle = Left + Right >> 1; //这样即可找到刚好满足题目要求的k的值
            if (calculate(Middle,n,num)) Left = Middle + 1;
            else Right = Middle - 1;
        }
        if (line++)printf("\n");
        if (Left - 1 == 0) printf("?\n");
        else {
            for (int i = 1 ; i <= pos[0] ; ++i) {
                for (int j = pos[i] ; j < pos[i] + Left - 1;++j) printf("%c",raw[j]);
                printf("\n");
            }
        }
    }
    return 0;
}