#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

#define MAX_SIZE 10000
#define MAX_NUM 1005

struct point{
    double_t x,y;
};

struct segment {
    point str, end;
};

point polygon[MAX_SIZE];
point cutters[MAX_SIZE];
segment polygons[MAX_SIZE];
segment lines[MAX_NUM];
int32_t has_cutter[MAX_SIZE];
vector<point > points;

inline double_t calc_area(point a, point b, point c) {
    return a.x * b.y + c.x * a.y + b.x * c.y - c.x * b.y - a.x * c.y - b.x * a.y;
}

inline bool intersection(segment seg1, segment seg2, point * cutter) {
    double_t abc_area = calc_area(seg1.str, seg1.end, seg2.str);
    double_t abd_area = calc_area(seg1.str, seg1.end, seg2.end);
    double_t cda_area = calc_area(seg2.str, seg2.end, seg1.str);
    double_t cbd_area = cda_area + abc_area - abd_area;
    if (abd_area - abc_area == 0) return false;
    double_t t = cda_area / (abd_area - abc_area);
    double_t dx = t * (seg1.end.x - seg1.str.x);
    double_t dy = t * (seg1.end.y - seg1.str.y);
    if (abc_area * abd_area > 0) return false;
    if (cda_area * cbd_area > 0) return false;
    cutter->x = seg1.str.x + dx;
    cutter->y = seg1.str.y + dy;
    return true;
}

inline double_t dist(point a, point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y , 2));
}

int main() {
    size_t polygon_size = 0, line_num = 0, count, index;
    double_t tot_len = 0;
    cout.setf(ios::fixed);
    while (cin >> polygon_size >> line_num , polygon_size, line_num) {
        for (size_t i = 0 ; i < polygon_size ; ++i)
            cin >> polygon[i].x >> polygon[i].y;
        for (size_t i = 0 ; i < line_num ; ++i)
            cin >> lines[i].str.x >> lines[i].str.y >> lines[i].end.x >> lines[i].end.y;
        for (size_t i = 0 ; i < polygon_size; ++i) {
            if (i == polygon_size - 1) {
                polygons[i].str.x = polygon[i].x;
                polygons[i].str.y = polygon[i].y;
                polygons[i].end.x = polygon[0].x;
                polygons[i].end.y = polygon[0].y;
            } else {
                polygons[i].str.x = polygon[i].x;
                polygons[i].str.y = polygon[i].y;
                polygons[i].end.x = polygon[i + 1].x;
                polygons[i].end.y = polygon[i + 1].y;
            }
        }
        for (size_t j = 0 ; j < line_num ; ++j) {
            count = 0;
            memset(has_cutter, 0, sizeof(has_cutter));
            tot_len = 0;
            points.clear();
            for (size_t i = 0; i < polygon_size; ++i) {
                has_cutter[i] = intersection(polygons[i], lines[j], &cutters[i]);
            }
            for (size_t i = 0; i < polygon_size; ++i) {
                if (has_cutter[i]) {
                    points.push_back(cutters[i]);
//                    count++;
//                    if (count == 1) index = i;
//                    if (count == 2) {
//                        count = 0;
//                        tot_len += dist(cutters[index], cutters[i]);
//                    }
                }
            }
            sort(points.begin(), points.end(), [](point a, point b) {return a.x < b.x;});
            for (size_t i = 0 ; i < points.size() - 1 ; ++i) {
                if ((i + 1) % 2 == 1 && (points.size() - i - 1) % 2 == 1) tot_len += dist(points[i], points[i+1]);
            }
            cout << setprecision(3) << tot_len << endl;
        }
    }
    return 0;
}