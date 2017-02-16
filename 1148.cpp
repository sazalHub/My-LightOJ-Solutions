#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,caseno=0,N,arr[55];
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld",&N);
        vector<ll>present;
        map<ll,ll>cnt;
        bool vis[1000001] = {false};
        ll ans = 0;
        for (ll i=0;i<N;i++)
        {
            scanf("%lld",&arr[i]);
            if (!vis[arr[i]])
            {
                vis[arr[i]] = true;
                present.push_back(arr[i]);
                cnt[arr[i]] = 1;
            }
            else
                cnt[arr[i]]++;
        }

        ll len = present.size();
        for (ll i=0;i<len;i++)
        {
            ans+=(ll)(cnt[present[i]]/(present[i]+1))*(present[i]+1);
            if (cnt[present[i]]%(present[i]+1)!=0)
                ans+=(present[i]+1);
        }

        printf("Case %lld: %lld\n",++caseno,ans);

    }
    return 0;
}
