#include<bits/stdc++.h>
using namespace std;
#define limit 100000
bool pRIME[limit];
int Prime[limit];
void Prime_gen()
{
    int i,j,k;
    pRIME[0]=pRIME[1]=1;
    for (i=2;i<=limit;i+=2)
        pRIME[i]=1;
    k=0;
    Prime[k++]=2;
    for (i=3;i<=sqrt(limit);i+=2)
    {
        if (!pRIME[i])
        {
            Prime[k++]=i;
            for (j=i*i;j<=limit;j+=2*i)
                pRIME[j]=1;
        }
    }
}

int main ()
{
    Prime_gen();
    int T,t=1,n,c,i,j,temp;
    scanf("%d",&T);
    while(T--)
    {
        map<int,int>v;
        scanf("%d",&n);
        printf("Case %d: %d =",t++,n);
        for (i=n;i>=2;i--)
        {
            temp=i;
            for (j=0;Prime[j]<=temp;j++)
            {
                c=0;
                while(temp%Prime[j]==0&&Prime[j]<=temp)
                {
                    c++;
                    temp/=Prime[j];
                }
                if (c>0)
                {
                    v[Prime[j]]+=c;
                }
            }
        }
        map<int,int>::iterator it;
        c=v.size();
        for (it=v.begin(),i=0;it!=v.end();it++,i++)
        {
            printf(" %d (%d)",(*it).first,(*it).second);
            if (i<(c-1))
                printf(" *");
        }
        printf("\n");
    }
    return 0;
}
