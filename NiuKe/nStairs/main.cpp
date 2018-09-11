#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    long rec[N+1];
    memset(rec, 0, sizeof(long) * N);
    rec[0] = 0;
    rec[1] = 1;
    rec[2] = 2;
    for (int i = 3; i < N+1; ++i) {
        rec[i] = rec[i - 1] + rec[i - 2];
    }
    printf("%ld", rec[N]);
    return 0;
}