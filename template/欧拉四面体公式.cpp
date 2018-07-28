#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    double l,n,a,m,b,c;
    while(scanf("%lf%lf%lf%lf%lf%lf",&l,&n,&a,&m,&b,&c)!=EOF){
        double x,y;
        x=4*a*a*b*b*c*c-a*a*(b*b+c*c-m*m)*(b*b+c*c-m*m)-b*b*(c*c+a*a-n*n)*(c*c+a*a-n*n);
        y=c*c*(a*a+b*b-l*l)*(a*a+b*b-l*l)-(a*a+b*b-l*l)*(b*b+c*c-m*m)*(c*c+a*a-n*n);
        double num=(sqrt(x-y)/12);
        printf("%.4lf\n",num);
    }
    return 0;
}