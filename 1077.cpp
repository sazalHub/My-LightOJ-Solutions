#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a,ll b)
{
    if (b==0)
        return a;
    return gcd(b,a%b);
}

ll ABS(ll N)
{
    return (N>=0)?N:-N;
}

int main ()
{
    ll cases,caseno=0;
    ll ax,ay,bx,by,ans1,ans2;
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld%lld%lld%lld",&ax,&ay,&bx,&by);
        ans1 = ABS(ax-bx);
        ans2 = ABS(ay-by);
        printf("Case %lld: %lld\n",++caseno,gcd(ans1,ans2)+1);
    }
    return 0;
}
