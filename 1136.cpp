#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main ()
{
    ll L,U,i,j,k,c;
    ll cases,caseno=0;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld%lld",&L,&U);
        c=0;
        if (L%3==0)
        {
            c++;
            L+=3;
        }
        else if ((L+2)%3==0)
        {
            L+=2;
        }
        else if ((L+1)%3==0)
        {
            L+=1;
        }
        if ((U-2)%3==0)
        {
            c++;
            U-=2;
        }
        else if ((U-1)%3==0)
        {
            U-=1;
        }
        ll t=(U-L)/3;
        t=t+1;
        c+=t*2;
        printf("Case %lld: %lld\n",++caseno,c);
    }
    return 0;
}
