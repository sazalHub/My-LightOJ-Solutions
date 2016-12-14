#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main ()
{
    ll fact[25];
    fact[0]=1;
    for (ll i=1;i<=20;i++)
        fact[i]=fact[i-1]*i;
    ll cases,caseno=0,i,j;
    scanf("%lld",&cases);
    while(cases--)
    {
        ll n,temp;
        scanf("%lld",&n);
        for (i=0;;i++)
        {
            if (fact[i]>n)
                break;
        }
        temp=i-1;
        ll num=n,c=0;
        ll a[25];
        i=0;
        for (j=temp;j>=0;j--)
        {
            if (num==0)
                break;
            if (num>=fact[j])
            {
                num-=fact[j];
                c++;
                a[i++]=j;
            }
        }
        if (c==0||num!=0)
            printf("Case %lld: impossible\n",++caseno);
        else
        {
            printf("Case %lld: ",++caseno);
            for (j=i-1;j>=0;j--)
            {
                printf("%lld!",a[j]);
                if (j>0)
                    printf("+");
            }
            printf("\n");
        }
    }
    return 0;
}
