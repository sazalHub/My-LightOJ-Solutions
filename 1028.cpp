#include<bits/stdc++.h>
using namespace std;
#define Max 1000100
long long num[78600];
static bool a[Max+10];
void seive()
{
    long long i,j,k=0;
    for (i=2;i<Max;i++)
    {
        if (a[i]==false)
        {
            num[k++]=i;
            for (j=i;j<Max;j+=i)
                a[j]=true;
        }
    }
}
long long factor (long long n)
{
    long long i,c,sum;
    sum=1;
    for (i=0;num[i]*num[i]<=n;i++)
    {
        c=0;
        while(n%num[i]==0)
        {
            c++;
            n/=num[i];
        }
        sum*=(c+1);
    }
    if (n>1)
        sum*=2;
    return sum;
}
int main ()
{
    long long n,T,t,c,m;
    seive();
    scanf("%lld",&T);
    for (t=1;t<=T;t++)
    {
        scanf("%lld",&n);
        c=factor(n);
        printf("Case %lld: %lld\n",t,c-1);
    }
    return 0;
}
