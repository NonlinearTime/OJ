#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define MAX_N 100500

struct point{
    double x,y;
};

struct segment {
    point str, end;
};

inline double calc_area(point a, point b, point c) {
    return a.x * b.y + c.x * a.y + b.x * c.y - c.x * b.y - a.x * c.y - b.x * a.y;
}

inline bool intersection(segment seg1, segment seg2) {
    if (calc_area(seg1.str, seg1.end, seg2.str) * calc_area(seg1.str, seg1.end, seg2.end) > 0) return false;
    return calc_area(seg2.str, seg2.end, seg1.str) * calc_area(seg2.str, seg2.end, seg1.end) <= 0;
}

segment segments[MAX_N];
int is_covered[MAX_N];

int main() {
    int n, count;
    while ( ~scanf("%d",&n)) {
        if (n == 0) break;
        memset(is_covered, 0, sizeof(is_covered));
        count = n;
        for (size_t i = 0 ; i  < n ; ++i)
            scanf("%lf %lf %lf %lf", &segments[i].str.x, &segments[i].str.y, &segments[i].end.x, &segments[i].end.y);
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = i + 1 ; j < n ; ++j) {
                if (!is_covered[i]) {
                    if (intersection(segments[i],segments[j])) {
                        is_covered[i] = 1;
                        count--;
                        break;
                    }
                }
            }
        }
        cout << "Top sticks: ";
        for (size_t i = 0 ; i < n - 1; ++i) {
            if (!is_covered[i]) cout << i + 1 << ", ";
        }
        cout << n << "." << endl;
    }
    return 0;
}