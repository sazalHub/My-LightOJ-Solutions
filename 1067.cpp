#include<bits/stdc++.h>
#define ll long long
#define mod 1000003
using namespace std;
ll arr [mod];
void fact()
{
    arr[0]=1;
    arr[1]=1;
    for (ll i=2;i<=1000000;i++)
    {
        arr[i]=((arr[i-1]%mod)*(i%mod))%mod;
    }
}
ll x,y;
void ExtendedEuclid(ll a,ll b)
{
     if( b == 0){
        x = a;
        y = 0;
        return;
    }
    ExtendedEuclid(b, a % b);
    ll tx, ty;
    tx = y;
    ty = x - a/b*y;
    x = tx;
    y = ty;
}
int main ()
{
    ll n,k,cases,caseno=0,d,m;
    fact();
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld%lld",&n,&k);
        if (n<k)
        {
            printf("Case %lld: %lld\n",++caseno,0);
            continue;
        }
        d=(arr[k]*arr[n-k])%mod;
        ExtendedEuclid(d,mod);
        d=x;
        while(d<0)
            d+=mod;
        d=d%mod;
        printf("Case %lld: %lld\n",++caseno,(arr[n]*d)%mod);
    }
    return 0;
}
