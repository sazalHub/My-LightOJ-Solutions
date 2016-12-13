#include<bits/stdc++.h>
using namespace std;
#define limit 65500
#define ll long long
#define mod 1000000007
ll y,ret,last;
bool a[limit+100];
ll Prime[limit+100];
void Prime_gen()
{
    a[0]=a[1]=true;
    ll k=0;
    for (ll i=2;i<=limit;i++)
    {
        if (a[i]==false)
        {
            Prime[k++]=i;
            for (ll j=i*i;j<=limit;j+=i)
                a[j]=true;
        }
    }
    last=k;
}

ll po(ll base,ll pow,ll m)
{
    if (pow==0)
        return 1;
    else if (pow%2==0)
    {
        y=po(base,pow/2,mod);
        ret=((y%mod)*(y%mod))%mod;
    }
    else
    {
        y=po(base,pow/2,mod);
        ret=((((y%mod)*(y%mod))%mod)*(base%mod))%mod;
    }
    return ret;
}

int main ()
{
    Prime_gen();
    ll cases,caseno=0,i,j,k,n,m,c,total;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld%lld",&n,&m);
        total=1;
        for (i=0;i<last;i++)
        {
            if (Prime[i]>n)
                break;
            if (n%Prime[i]==0)
            {
                c=0;
                while(n%Prime[i]==0)
                {
                    n/=Prime[i];
                    c++;
                }
                total=((total%mod)*(((po(Prime[i],(c*m)+1,mod)-1)+mod)%mod))%mod;
                total=((total%mod)*((po(Prime[i]-1,mod-2,mod)+mod)%mod))%mod;
            }
        }
        if (n>1)
        {
            total=((total%mod)*(((po(n,m+1,mod)-1)+mod)%mod))%mod;
            total=((total%mod)*(((po(n-1,mod-2,mod)+mod))%mod))%mod;
        }
        printf("Case %lld: %lld\n",++caseno,total);
    }
    return 0;
}
