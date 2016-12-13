#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main ()
{
    ll T,S,t=1,k,x,y,temp;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&S);
        printf("Case %lld: ",t++);
        k=sqrt(S);
        if ((k*k)==S)
        {
            if (S%2==0)
                cout<<k<<' '<<1<<endl;
            else
                cout<<1<<' '<<k<<endl;
            continue;
        }
        temp=(k*(k+1))+1;
        k=k+1;
        if (k%2==0)
        {
            if (S<=temp)
            {
                x=k-(temp-S);
                y=k;
            }
            else
            {
                x=k;
                y=k-(S-temp);
            }
        }
        else
        {
            if (S>=temp)
            {
                x=k-(S-temp);
                y=k;
            }
            else
            {
                x=k;
                y=k-(temp-S);
            }
        }
        printf("%lld %lld\n",x,y);
    }
    return 0;
}
