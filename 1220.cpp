#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll N;

ll solve(ll n,ll d)
{
    ll cnt = 0;
    while(n!=1&&n%d==0)
    {
        cnt++;
        n/=d;
    }
    if (n==1) return cnt;
    return -1;
}

int main ()
{
    ll cases,caseno=0,lmt,cnt,ret;
    bool flag;
    scanf("%lld",&cases);
    while(cases--)
    {
        flag = false;
        scanf("%lld",&N);
        if (N<0)
            N=N*-1,flag = true;
        ll lmt = sqrt(N);
        cnt = 1;
        for (ll i=2;i<=lmt;i++)
        {
            if (N%i==0)
            {
                ret = solve(N,i);
                if (flag&&ret!=-1)
                {
                    if (ret%2==1)
                    {
                        cnt = max(cnt,ret);
                        break;
                    }
                }
                else if (ret!=-1)
                {
                    cnt = max(cnt,ret);
                    break;
                }
            }
        }
        printf("Case %lld: %lld\n",++caseno,cnt);
    }
    return 0;
}
