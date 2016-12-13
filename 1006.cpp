#include<bits/stdc++.h>
using namespace std;

#define sl(n) scanf("%lld",&n)
#define si(n) scanf("%d",&n)
#define ll long long
#define mod 10000007
ll a,b,c,d,e,f,n;
ll d_hex[10009];

ll  Hexabonacci (ll n)
{
    if (n==0)return a;
    if (n==1)return b;
    if (n==2)return c;
    if (n==3)return d;
    if (n==4)return e;
    if (n==5)return f;
    if (d_hex[n]!=-1)return d_hex[n];
    else
    {
        d_hex[n]=Hexabonacci(n-1)%mod+Hexabonacci(n-2)%mod+Hexabonacci(n-3)%mod+Hexabonacci(n-4)%mod+Hexabonacci(n-5)%mod+Hexabonacci(n-6)%mod;
        return d_hex[n];
    }
}
int main ()
{
    int cases,caseno=0;
    si(cases);
    while(cases--)
    {
        sl(a);sl(b);sl(c);sl(d);sl(e);sl(f);sl(n);
        for (int i=0;i<=10005;i++){
            d_hex[i]=-1;
        }
        printf("Case %d: %lld\n",++caseno, Hexabonacci(n)%mod);
    }
    return 0;
}
