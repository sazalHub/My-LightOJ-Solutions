#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX 100000100
ll a[MAX/64+100];
unsigned primes[5761558];
unsigned int save[5761558];
int len;

void Bit_Seive()
{
    ll lmt = sqrt(MAX);
	for (ll i=3;i<=lmt;i+= 2)
    {
		if(!(a[i/64]&(1LL<<(i%64))))
		{
			for(ll j=i*i;j<MAX;j+=2*i)
				a[j/64] |= (1LL<<(j%64));
		}
	}

	primes[(len=0)++] = 2;
	for (ll i = 3; i <= MAX; i += 2)
		if(!(a[i/64] & (1LL<<(i%64))))
			primes[len++] = i;
}

ll solve(ll N)
{
    unsigned ans=1,n;
    for (ll i=0;primes[i]*primes[i]<=N;i++)
    {
        n=N/primes[i];
        while(n>=primes[i])
        {
            ans*=primes[i];
            n/=primes[i];
        }
    }

    ll upper = upper_bound(primes,primes+len,N)-primes;
    ans*=save[upper-1];

    return ans;
}

int main ()
{
    Bit_Seive();
    save[0]=2;
    for (ll i=1;i<len;i++)
        save[i] = save[i-1]*primes[i];

    int cases,caseno=0;
    ll N;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%lld",&N);
        printf("Case %d: %u\n",++caseno,solve(N));
    }
    return 0;
}
