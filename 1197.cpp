#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll primes[101000],pr[101000],cnt;

void prime()
{
    ll i=0,j=0;
    cnt=0;
    pr[1]=1;
    for(i=2;i<=100000;i++)
    {
        if(!pr[i])
        {
            primes[cnt++]=i;
            for(j=i*2;j<=100000;j=j+i)
            {
                pr[j]=1;
            }
        }
    }
}

int main()
{
    prime();
    ll cases,caseno=0;
    scanf("%lld",&cases);
    ll N,M;
    while(cases--)
    {
        scanf("%lld %lld",&M,&N);
        memset(pr,0,sizeof(pr));
        for(ll i=0;i<cnt;i++)
        {
            ll p=(M/primes[i])*primes[i];
            if (p<M)
                p+=primes[i];
            if (p<(primes[i]*primes[i]))
                p=primes[i]*primes[i];
            for(ll j=p;j<=N;j+=primes[i])
            {
                pr[j-M]=1;
            }
        }
        if (M==1)
            pr[0]=1;
        ll c=0;
        for(ll i=0;i<=N-M;++i)
        {
            if(pr[i])
                c++;
        }
        ///cout<<c<<endl;
        printf("Case %lld: %lld\n",++caseno,N-M+1-c);
    }
    return 0;
}

