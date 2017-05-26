#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool visited[1000005];
ll primes[1000005],len,present[1000005],ln;

void PrimeGenerator()
{
    len = 0;
    primes[len++] = 2;
    for (ll i=3;i<=1000003;i+=2)
    {
        if (!visited[i])
        {
            primes[len++] = i;
            for (ll j=i*i;j<=1000003;j+=2*i)
                visited[j] = true;
        }
    }
    ///cout<<len<<endl;
}

ll BigMod(ll base,ll power)
{
    if (power==0) return 1;
    if (power==1) return base;
    ll y,ret;
    y = BigMod(base,power/2);
    ret = y*y;
    if (power%2)
        ret = ret*base;
    return ret;
}

map<ll,ll> FACT(ll A,map<ll,ll>val)
{
    ll cnt = 0;
    for (ll i=0;primes[i]*primes[i]<=A;i++)
    {
        if (A%primes[i]==0)
        {
            cnt = 0;
            while(A%primes[i]==0)
                cnt++,A/=primes[i];
            ///if (!visited[primes[i]])
                ///present[ln++]=primes[i],visited[primes[i]] = true;
            if (val[primes[i]]==0)
                present[ln++]=primes[i];///visited[primes[i]] = true;
            val[primes[i]] = max(cnt,val[primes[i]]);
        }
    }
    if (A>1)
    {
        ///if (!visited[A])
            ///present[ln++]=A,visited[A] = true;
        if (val[A]==0)
            present[ln++]=A;///visited[primes[i]] = true;
        val[A] = max(1ll,val[A]);
    }
    return val;
}

ll solve(ll N,map<ll,ll> val)
{
    ll ret = 1,cnt = 0;

    for (ll i=0;i<ln;i++)
    {
        if (N>1&&N%present[i]) return -1;
        cnt = 0;
        while(N%present[i]==0)
            cnt++,N/=present[i];
        if (cnt==val[present[i]]) continue;
        if (cnt<val[present[i]]) return -1;
        ret = ret*BigMod(present[i],max(val[present[i]],cnt));
    }
    ret*=N;
    return ret;
}

int main ()
{
    PrimeGenerator();
    ll cases,caseno=0,A,B,L,ans;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld%lld%lld",&A,&B,&L);

        ///for (ll i=0;i<len;i++) visited[primes[i]] = false,val[primes[i]] = -1;
        map<ll,ll>val;
        ln = 0;

        val = FACT(A,val);
        val = FACT(B,val);
        ans = solve(L,val);

        printf("Case %lld: ",++caseno);
        if (ans==-1) printf("impossible\n");
        else printf("%lld\n",ans);
    }
    return 0;
}
