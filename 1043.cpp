#include<bits/stdc++.h>
#define in int
using namespace std;

int main ()
{
    in cases,caseno=0;
    double A,B,C,d;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%lf%lf%lf%lf",&A,&B,&C,&d);
        double ans = sqrt(d/(1.0+d))*A;
        printf("Case %d: %0.10lf\n",++caseno,ans);
    }
    return 0;
}
