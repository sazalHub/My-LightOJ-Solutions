#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll solution(ll num)
{
    ll sum=0,i,j,k;
    for (i=2;i*i<=num;i++)
    {
        j=num/i;
        sum+=((i+j)*(j-i+1))/2;
        sum+=i*(j-i);
    }
    return sum;
}

int main ()
{
    ll cases,caseno=0,num;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld",&num);
        printf("Case %lld: %lld\n",++caseno,solution(num));
    }
}
