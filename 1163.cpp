#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,caseno=0,N,ans;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld",&N);
        printf("Case %lld: ",++caseno);
        ans = N + N/9;
        if (N%9==0)
            printf("%lld %lld\n",ans-1,ans);
        else
            printf("%lld\n",ans);
    }
    return 0;
}
