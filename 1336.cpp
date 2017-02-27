#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
    ll cases,caseno=0,N,ans;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld",&N);
        ans = (ll)sqrt(N) + (ll)sqrt(N/2);
        printf("Case %lld: %lld\n",++caseno,N-ans);
    }
    return 0;
}
