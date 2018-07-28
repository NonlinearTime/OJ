#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>

using namespace std;

int main() {
    double_t l,m,n,q,p,r;
    while(scanf("%lf%lf%lf%lf%lf%lf",&n,&m,&p,&l,&q,&r)!=EOF) {
        double_t pp = p * p, qq = q * q, rr = r * r, ll = l * l, mm = m * m, nn = n * n;
        double_t left = (pp + qq - nn) / 2, mid = (pp + rr - mm) / 2, right = (qq + rr - ll) / 2;
        double_t pre_v= pp * (qq * rr - right * right) - left * (left * rr - mid * right) + mid * (left * right - qq * mid);
        double_t v = (double_t)sqrt((double_t)(pre_v / 36.0));
        printf("%.4lf\n",v);
    }
    return 0;
}
