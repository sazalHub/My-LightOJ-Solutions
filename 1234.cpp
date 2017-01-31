#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MX=1e8+10;
double save[MX/100+10];

void solve()
{
    save[0] = 0.0;
    save[1] = 1.0;
    double sum = 1.00;
    for(ll i=2;i<=MX;i++)
    {
        sum+=1.0/i;
        if (i%100==0)
            save[i/100] = sum;
    }
}

int main ()
{
    solve();
    ll N,cases,caseno=0;
    double ans = 0.00;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld",&N);
        ans = save[(ll)(N/100)];
        for (ll i=(ll)(N/100)*100+1;i<=N;i++)
            ans+=1.0/i;
        printf("Case %lld: %0.10lf\n",++caseno,ans);
    }
    return 0;
}
