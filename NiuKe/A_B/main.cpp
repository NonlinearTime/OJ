#include <stdio.h>
#include <stdlib.h>

int main() {
    char b1[1005], b2[1005];
    scanf("%s %s", b1, b2);
    int idx1 = 0, idx2 = 0;
    while(1) if(b1[++idx1] == '\0') break;
    while(1) if(b2[++idx2] == '\0') break;
    idx1--;
    idx2--;
    int is_1_larger = idx1 > idx2;
    int idx = idx1 < idx2 ? idx1 : idx2;
    int c = 0;
    while(1) {
        int bit1 = b1[idx1] - '0';
        int bit2 = b2[idx2] - '0';
        int t = bit1 + bit2 + c;
        if (t >= 10) {
            t = t - 10;
            c = 1;
        } else c = 0;
        if (is_1_larger) b1[idx1] = t + '0';
        else b2[idx2] = t + '0';
        idx1--;
        idx2--;
        idx--;
        if(idx == -1) break;
    }
    while(1) {
        int b = is_1_larger ? b1[idx1] - '0' : b2[idx2] - '0';
        int t = b + c;
        if (t >= 10) {
            t = t - 10;
            c = 1;
        } else c = 0;
        if (is_1_larger) b1[idx1] = '0' + t;
        else b2[idx2] = '0' + t;
        idx1--;
        idx2--;
        if (is_1_larger && idx1 == -1) break;
        else if (!is_1_larger && idx2 == -1) break;
    }
    if (c == 1) printf("%c", '1');
    if (is_1_larger) printf("%s",b1);
    else printf("%s",b2);
    return 0;
}