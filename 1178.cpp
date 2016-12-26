#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main ()
{
    ll cases,caseno=0;
    double a,b,c,d,h,x,ans;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        x = (b*b-d*d+(a-c)*(a-c))/(2.0*(a-c));
        h = sqrt(b*b-x*x);
        ans = 0.5*(a+c)*h;
        printf("Case %lld: %0.10lf\n",++caseno,ans);
    }
    return 0;
}
