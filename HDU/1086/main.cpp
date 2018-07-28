#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX_N 105

struct point{
    double x,y;
    point(double x, double y) {
        this->x = x, this->y = y;
    }
};

struct segment {
    point str, end;
    segment(): str(0,0), end(0,0) {};
    segment(double x_str, double y_str, double x_end, double y_end) : str(x_str,y_str), end(x_end,y_end) {}
};
size_t N;
segment segments[MAX_N];

inline double calc_area(point a, point b, point c) {
    return a.x * b.y + c.x * a.y + b.x * c.y - c.x * b.y - a.x * c.y - b.x * a.y;
}

bool intersection(segment seg1, segment seg2) {
    return calc_area(seg1.str, seg1.end, seg2.str) * calc_area(seg1.str, seg1.end, seg2.end) <= 0
           && calc_area(seg2.str, seg2.end, seg1.str) * calc_area(seg2.str, seg2.end, seg1.end) <=0;
}

void init() {
}

int main() {
    segment x = segment(0, -1, 0, 1);
    segment y = segment(-1, 0, 1, 0);
    while(cin >> N && N != 0) {
        int count = 0;
        double x_str, y_str, x_end, y_end;
        for (size_t i = 0; i < N; ++i) {
            cin >> x_str >> y_str >> x_end >> y_end;
            segments[i] = segment(x_str, y_str, x_end, y_end);
        }
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = i + 1; j < N; ++j) {
                if (intersection(segments[i], segments[j])) count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}