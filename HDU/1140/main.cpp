#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define MAX_N 105

struct pos {
    double_t  x, y, z;
};

double_t dist(pos a, pos b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
}

pos sat_pos[MAX_N];
pos tar_pos[MAX_N];
int32_t is_attacked[MAX_N];

int main() {
    size_t k,m,count;
    pos center;
    center.x = center.y = center.z = 0;
    double_t r = 20000 / acos(-1);

    while (1) {
        cin >> k >> m;
        count = 0;
        for (int &i : is_attacked) i = 0;
        double_t dist_s_o, dist_s_f;
        if (k == 0 && m == 0) break;
        for (size_t i = 0 ; i < k ; ++i)
            cin >> sat_pos[i].x >> sat_pos[i].y >> sat_pos[i].z;
        for (size_t i = 0 ; i < m ; ++i)
            cin >> tar_pos[i].x >> tar_pos[i].y >> tar_pos[i].z;
        for (size_t i = 0 ; i < k ; ++i) {
            dist_s_o = dist(sat_pos[i], center);
            dist_s_f = dist_s_o - r * r;
            for (size_t j = 0 ; j < m; ++j) {
                if (!is_attacked[j]) {
                    double_t dist_s_t = dist(sat_pos[i], tar_pos[j]);
                    if (dist_s_t < dist_s_f) {
                        is_attacked[j] = 1;
                        count++;
                    }
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}