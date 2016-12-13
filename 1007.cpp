#include<bits/stdc++.h>
using namespace std;

#define limit 5000005
unsigned long phi[limit];
int mark[limit];

void phi_n()
{
    int i,j;
    for (i=1;i<=limit;i++)
        phi[i]=i;
    phi[1]=1;
    mark[1]=1;
    for (i=2;i<=limit;i+=2)
    {
        if (i!=2)
            mark[i]=1;
        phi[i]/=2;
    }
    for (i=3;i<=limit;i+=2)
    {
        if (!mark[i])
        {
            phi[i]=phi[i]-1;
            for (j=2*i;j<=limit;j+=i)
            {
                mark[j]=1;
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
    for (i=2;i<=limit;i++)
        phi[i]=phi[i-1]+phi[i]*phi[i];
}

int main ()
{
    phi_n();
    int T,t=1;
    int a,b;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&a,&b);
        printf("Case %d: %lu\n",t++,phi[b]-phi[a-1]);
    }
    return 0;
}
