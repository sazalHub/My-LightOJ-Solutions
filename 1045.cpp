#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main ()
{
    double digit[1000001];
    for (ll i=1;i<=1000001;i++)
        digit[i]=log(i*1.00)+digit[i-1];

    ll cases,caseno=0,num,base;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld%lld",&num,&base);
        double ans=digit[num]/(log(base*1.0));
        ll x=floor(ans)+1;
        printf("Case %lld: %lld\n",++caseno,x);
    }
    return 0;
}
