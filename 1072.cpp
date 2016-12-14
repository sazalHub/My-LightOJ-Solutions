#include<bits/stdc++.h>
#define ll long long
double PI=acos(-1.00);
using namespace std;
int main ()
{
    ll cases,caseno=0,n;
    double radius,R,temp;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lf%lld",&R,&n);
        temp=PI/n;
        radius=(R*sin(temp))/(sin(temp)+1.0);
        printf("Case %lld: %0.10lf\n",++caseno,radius);
    }
}
