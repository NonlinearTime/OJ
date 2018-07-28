#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX_N 1000005

struct point{
    double x,y;
    point() {this->x = 0, this->y = 0;}
    point(double x, double y) {
        this->x = x, this->y = y;
    }
};

struct segment {
    point str, end;
    segment(): str(), end() {};
    segment(double x_str, double y_str, double x_end, double y_end) : str(x_str,y_str), end(x_end,y_end) {}
};
size_t N;
//segment segments[MAX_N];
point points[MAX_N];

bool point_cmp(point a, point b) {
    return a.x < b.x;
}

inline double calc_area(point a, point b, point c) {
    return a.x * b.y + c.x * a.y + b.x * c.y - c.x * b.y - a.x * c.y - b.x * a.y;
}

int main() {
    int polygon_num, index_num;
    double x,y,g_x,g_y;
    double tot_area, x_area, y_area;
    cin >> polygon_num;
    while (polygon_num--) {
        cin >> index_num;
        tot_area = 0;
        x_area = y_area = 0;
        for (size_t i = 0 ; i < index_num; ++i) {
            cin >> x >> y;
            points[i] = point(x,y);
        }
//        sort(points, points + index_num, [](point a, point b) {return a.y > b.y ;});
//        sort(points + 1, points + index_num, [](point a, point b) {return a.x < b.x ;});
        for (size_t i = 1; i < index_num - 1; ++i) {
            double area = (calc_area(points[0], points[i], points[i+1]));
            tot_area += area;
            cout << area << " " << tot_area << endl;

            x_area += area * (points[0].x + points[i].x + points[i+1].x);
            y_area += area * (points[0].y + points[i].y + points[i+1].y);
        }
        g_x = x_area / (3 * tot_area);
        g_y = y_area / (3 * tot_area);
        cout << g_x << " " << g_y << endl;
    }
    return 0;
}