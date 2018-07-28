#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <exception>
#include <vector>

using namespace std;

#define MAX_N 1005

struct point {
    double_t x, y;
    point() :x (0), y(0) {}
    point(double_t x, double_t y) {
        this->x = x, this->y = y;
    }
};

using vect = point;

struct segment {
    point str, end;
};

point points[MAX_N];
double_t cos_val[MAX_N];
vector<point> convexHull;
size_t indexs[MAX_N];
size_t is_valid[MAX_N];
point p_ahead, p_cur, p_prev;
vect cur_vect, pre_vect;

double_t dist (point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double_t product_calc(vect a, vect b) {
    return a.x * b.x + a.y * b.y;
}


double_t calc_cos(vect a, vect b) {
    point zero;
    double_t a_len = dist(a, zero);
    double_t b_len = dist(b, zero);
    double_t p_product = product_calc(a, b);
    return p_product / ( a_len * b_len );
}

bool is_declock(vect a, vect b) {
    return a.x * b.y - a.y * b.x > 0;
}

void convex_hull(size_t p_size) {
    double_t tmp = -1000;
    memset(is_valid,0, sizeof(is_valid));
    sort(points, points + p_size, [](point a, point b) {
        if (a.y < b.y) return true;
        else if (a.y == b.y) return a.x < b.x;
        else return false;
    });
    point P0 = points[0];
    vect X0(1,0);
    for (size_t i = 1; i < p_size ; ++i) {
        cos_val[i] = calc_cos(X0, vect(points[i].x - P0.x, points[i].y - P0.y));
        indexs[i] = i;
    }
    sort(indexs + 1, indexs + p_size, [](size_t a, size_t b) {
        if (cos_val[a] > cos_val[b]) return true;
        else if (cos_val[a] == cos_val[b]) return points[a].x > points[b].x;
        else return false;
    });
    for (size_t i = 1; i < p_size ; ++i) {
        if(cos_val[i] != tmp) {
            is_valid[i] = 1;
            tmp = cos_val[i];
        }
    }
    convexHull.push_back(P0);
    convexHull.push_back(points[indexs[1]]);
    convexHull.push_back(points[indexs[2]]);
    for (size_t i = 3; i < p_size ; ++i) {
        p_ahead = points[indexs[i]];
        if (!is_valid[i]) continue;
        while (1) {
            p_cur = convexHull.back();
            p_prev = convexHull[convexHull.size() - 2];
            cur_vect = vect(p_ahead.x - p_cur.x, p_ahead.y - p_cur.y);
            pre_vect = vect(p_cur.x - p_prev.x, p_cur.y - p_prev.y);
            if (is_declock(pre_vect, cur_vect)) {
                convexHull.push_back(p_ahead);
                break;
            } else {
                convexHull.pop_back();
            }
        }
    }

}

int main() {
    size_t n, v_n, dis;
    double_t tot_len = 0;
    scanf("%ld",&n);
    while (n--) {
        tot_len = 0;
        convexHull.clear();
        scanf("%ld %ld", &v_n, &dis);
        for (size_t i = 0 ; i < v_n; ++i)
            scanf("%lf %lf", &points[i].x ,&points[i].y);
        convex_hull(v_n);
        for (size_t i = 0 ; i < convexHull.size() ; ++i) {
            if (i == convexHull.size() - 1) tot_len += dist(convexHull[i],convexHull[0]);
            else tot_len += dist(convexHull[i], convexHull[i+1]);
        }
        tot_len += 3.141592653 * dis * 2;
        printf("%.0f\n",tot_len);
        if (n) printf("\n");
    }
    return 0;
}