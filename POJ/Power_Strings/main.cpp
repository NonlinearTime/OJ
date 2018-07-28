#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 1000005

char pattern[MAX];
int NEXT[MAX+1];
int len;

void get_next() {
    NEXT[0] = -1;
    len = (int)strlen(pattern);
    int j = 0, k = -1;
    while(j < len) {
        if (k == - 1 || pattern[j] == pattern[k]) {
            j++,k++;
            NEXT[j] = k;
        } else k = NEXT[k];
    }
}

int main() {
    while(scanf("%s",pattern) && pattern[0] != '.') {//使用next数组，，简单粗暴
        get_next();                                  //如何证明？？？
        int ans = 1;
        if (len % (len - NEXT[len]) == 0) {
            ans = len / (len - NEXT[len]);
        }
        printf("%d\n",ans);
    }
    return 0;
}