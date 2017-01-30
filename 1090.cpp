#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll N,R,P,Q,cnt;

ll NCR(ll n,ll r)
{
    cnt = 0;
    while(n!=0)
        n/=r,cnt+=n;
    return cnt;
}

ll PWR(ll p,ll r)
{
    cnt = 0;
    while(p%r==0)
        p/=r,cnt++;
    return cnt;
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,caseno=0,cnt2,cnt5;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld%lld%lld%lld",&N,&R,&P,&Q);
        cnt2 = NCR(N,2) - NCR(R,2) - NCR(N-R,2);
        cnt5 = NCR(N,5) - NCR(R,5) - NCR(N-R,5);
        cnt2 = cnt2 + PWR(P,2)*Q;
        cnt5 = cnt5 + PWR(P,5)*Q;
        printf("Case %lld: %lld\n",++caseno,min(cnt2,cnt5));
    }
    return 0;
}
