#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

#define MAXN 1005

int record[MAXN][MAXN];
int min_height[MAXN][MAXN];
int height[MAXN];
int L[MAXN], R[MAXN];
int N;

void init() {
    memset(record, -1, sizeof(int) * MAXN * MAXN);
    memset(min_height, 20000, sizeof(int) * MAXN * MAXN);
    memset(height, 0 , sizeof(int) * MAXN);
    memset(L, 0, sizeof(int) * MAXN);
    memset(R, 0, sizeof(int) * MAXN);

    cin >> N;
    for (int i = 0 ; i < N; ++i) {
        cin >> height[i];
        record[i][i] = height[i];
        min_height[i][i] = i;
    }
    for (int i = 1; i < N; ++i) L[i] = height[i] <= height[i-1] ? L[i] + 1 : 0;
    for (int i = N - 2; i >= 0; --i) R[i] = height[i] <= height[i+1] ? R[i] + 1: 0;
}

static int getMaxNum(int a, int b, int c) {
    return (a < b ? (b < c ? c : b) : (a < c ? c : a));
}

int get_max_area(int left, int right) {
    int max_area = -1;
    if (record[left][right] > 0) return record[left][right];
    int midx = min_height[left][right];
    int left_area = midx == left ? 0 : get_max_area(left, midx - 1);
    int right_area = midx == right ? 0 : get_max_area(midx + 1, right);
    int across_area = (right - left + 1) * height[midx];
    int t = getMaxNum(left_area, right_area, across_area);
    if(t > max_area) max_area = t;
    record[left][right] = max_area;
    return max_area;
}

void cal_min_height() {
    for (int i = 0 ; i < N - 1 ; ++i) {
        for (int j = i + 1; j < N ; ++j) {
            min_height[i][j] = height[min_height[i][j - 1]] < height[j] ? min_height[i][j-1] : j;
        }
    }
}

int main() {
    init();
    cal_min_height();
    int res = -1;
    for (int i = 0 ; i < N; ++i) {
        int s = height[i] * (L[i] + R[i] + 1);
        if (res < s) res = s;
    }
    cout << get_max_area(0, N-1) << endl;
    return 0;
}