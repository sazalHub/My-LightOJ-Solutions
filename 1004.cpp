#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll N;
ll dp[200][105];
ll arr[200][105];

ll sett(ll i,ll j)
{
    if (i>=0 && i<2*N-1)
    {
        ll rg;
        if (i<N-1)
        {
            rg = i+1;
            if (j>=0 && j<rg)
            {
                if (dp[i][j]!=-1)
                    return dp[i][j];
                ll ret1 = sett(i+1,j)+arr[i][j];
                ll ret2 = sett(i+1,j+1)+arr[i][j];
                return dp[i][j] = max(ret1,ret2);
            }
            else
                return 0;
        }
        else if (i<2*N-1)
        {
            rg = 2*N - i - 1;
            if (j>=0 && j<rg)
            {
                if (dp[i][j]!=-1)
                    return dp[i][j];
                if (j==0)
                {
                    ll ret = sett(i+1,j)+arr[i][j];
                    return dp[i][j] = ret;
                }
                else if (j==rg-1)
                {
                    ll ret = sett(i+1,j-1)+arr[i][j];
                    return dp[i][j] = ret;
                }
                else
                {
                    ll ret1 = sett(i+1,j-1)+arr[i][j];
                    ll ret2 = sett(i+1,j)+arr[i][j];
                    return dp[i][j] = max(ret1,ret2);
                }
            }
        }
        else
            return 0;
    }
    else
        return 0;
}

int main ()
{
    ll cases,caseno=0;
    freopen("out.txt","r",stdin);
    freopen("res.txt","w",stdout);
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld",&N);

        for (ll i=0;i<N;i++)
            for (ll j=0;j<=i;j++)
                scanf("%lld",&arr[i][j]);

        ll k=N-1;
        for (ll i=N;i<2*N-1;i++,k--)
            for (ll j=0;j<k;j++)
                scanf("%lld",&arr[i][j]);

        memset(dp,-1,sizeof(dp));
        ll ret = sett(0,0);
        printf("Case %lld: %lld\n",++caseno,ret);
    }
    return 0;
}
