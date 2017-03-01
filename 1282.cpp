#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll power(ll base,ll pwr)
{
    if (pwr==0) return 1;
    else if (pwr%2==1)
    {
        ll y = power(base,pwr/2);
        return ((y%1000*y%1000)%1000*base%1000)%1000;
    }
    else
    {
        ll y = power(base,pwr/2);
        return (y%1000*y%1000)%1000;
    }
}

int main ()
{
    ll N,K,cases,caseno=0,Front,Rare;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld%lld",&N,&K);
        Rare = power(N,K);
        double pwr = K*log10(N);
        Front = pow(10,pwr-(ll)pwr)*100;
        printf("Case %lld: %lld %03lld\n",++caseno,Front,Rare);
    }
    return 0;
}
