#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a,ll b)
{
	return (a%b)?gcd(b,a%b):b;
}

int main(int argc, char const *argv[])
{
	ll cases,caseno = 0,n,num,cnt,p,q,g;

	freopen("in.txt","r",stdin);

	scanf("%lld",&cases);
	while(cases--)
	{
		scanf("%lld",&n);

		cnt = p = q = 0;

		for (ll i=0;i<n;i++)
		{
			scanf("%lld",&num);
			if (num<0) cnt++,num*=-1;
			else q++;

			p+=num;
		}

		printf("Case %lld: ", ++caseno);


		if (cnt==n)
		{
			printf("inf\n");
			continue;
		}
		
		g = gcd(p,q);
		p/=g,q/=g;

		printf("%lld/%lld\n", p, q);

	}
	return 0;
}