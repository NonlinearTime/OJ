#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAXN 13

char** res;
int rIndex, L;
char *raw_string;
int* to_capital;

struct letters {
    int len;
    int index[MAXN];
};

struct letters l;

int is_letter(char c) {
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

void backtracking(int index) {
    if (index == l.len) {
        res[rIndex] = (char *)malloc(L * sizeof(char));
        for (int i = 0 ; i < L ; ++i) res[rIndex][i] = raw_string[i];
        for (int i = 0 ; i < index ; ++i) {
            if (to_capital[i])
                res[rIndex][l.index[i]] |= 0x20;
            else
                res[rIndex][l.index[i]] &= 0xffffffdf;
        }
        rIndex++;
        return;
    }
    int t = to_capital[index];
    to_capital[index] = 0;
    backtracking(index + 1);
    to_capital[index] = 1;
    backtracking(index + 1);
    to_capital[index] = t;
}

char** letterCasePermutation(char* S, int* returnSize) {
    L = *returnSize;
    raw_string = S;
    to_capital = (int *)malloc(L * sizeof(int));
    memset(to_capital, 0, L * sizeof(int));

    l.len = 0;
    for (int i = 0 ; i < L ; ++i) if (is_letter(S[i])) l.index[l.len++] = i;
    res = (char **)malloc((int)pow(2, l.len) * sizeof(char *));
    rIndex = 0;

    backtracking(0);

    for (int i = 0 ; i < (int)pow(2, l.len) ; ++i) {
        printf("%s\n", res[i]);
    }

    return res;
}

int main() {
    int length = 5;
    char s[length] = "12345";
    letterCasePermutation(s, &length);
    return 0;
}