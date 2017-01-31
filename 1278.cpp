#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>primes;
bool vis[10000052];
ll len,N;

void PrimeGenerator()
{
    ll lmt = sqrt(10000051);
    for (ll i=3;i<=lmt;i+=2)
    {
        if (!vis[i])
        {
            for (ll j=i*i;j<=10000051;j+=2*i)
                vis[j] = true;
        }
    }
    ///primes.push_back(2);
    for (ll i=3;i<=10000051;i+=2)
        if (!vis[i])
            primes.push_back(i);
    len = primes.size();
}

int main ()
{
    PrimeGenerator();
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,caseno=0,ans,tmp,cnt;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld",&N);
        ans = 1;
        tmp = N;
        while(tmp%2==0)
            tmp/=2;
        for (ll i=0;primes[i]*primes[i]<=tmp;i++)
        {
            cnt = 0;
            while(tmp%primes[i]==0)
                tmp/=primes[i],cnt++;
            ans = ans*(cnt+1);
        }
        if (tmp>1)
            ans*=2;
        printf("Case %lld: %lld\n",++caseno,ans-1);
    }
    return 0;
}
