#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct detail{
    ll pos,man;
};

vector<ll> FindMinSub (ll Arr[],ll n,ll M)
{
    deque<detail>DQ;
    detail dt;
    vector<ll>res;
    for (ll i=0;i<n;i++)
    {
        ll val = Arr[i];
        while(true)
        {
            if (DQ.empty())
                break;
            dt = DQ.front();
            if (dt.man>=val)
                DQ.pop_front();
            else
                break;
        }
        dt.man = val;
        dt.pos = i;
        DQ.push_front(dt);
        while(true)
        {
            if (DQ.empty())
                break;
            dt = DQ.back();
            if (dt.pos<=i-M)
                DQ.pop_back();
            else
                break;
        }
        if (i>=M-1)
        {
            dt = DQ.back();
            res.push_back(dt.man);
        }
    }
    return res;
}

vector<ll> FindMAxSub (ll Arr[],ll n,ll M)
{
    deque<detail>DQ;
    detail dt;
    vector<ll>res;
    for (ll i=0;i<n;i++)
    {
        ll val = Arr[i];
        while(true)
        {
            if (DQ.empty())
                break;
            dt = DQ.front();
            if (dt.man<=val)
                DQ.pop_front();
            else
                break;
        }
        dt.man = val;
        dt.pos = i;
        DQ.push_front(dt);
        while(true)
        {
            if (DQ.empty())
                break;
            dt = DQ.back();
            if (dt.pos<=i-M)
                DQ.pop_back();
            else
                break;
        }
        if (i>=M-1)
        {
            dt = DQ.back();
            res.push_back(dt.man);
        }
    }
    return res;
}

int main ()
{
    ll cases,caseno=0,N,d;
    ll arr[100005];
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld%lld",&N,&d);
        for (ll i=0;i<N;i++)
            scanf("%lld",&arr[i]);
        vector<ll>MIn,MAx;
        MIn = FindMinSub(arr,N,d);
        MAx = FindMAxSub(arr,N,d);
        ll ans = 0;
        ll len = MIn.size();
        for (ll i=0;i<len;i++)
            ans = max(ans,abs(MIn[i]-MAx[i]));
        printf("Case %lld: %lld\n",++caseno,ans);
    }
    return 0;
}
