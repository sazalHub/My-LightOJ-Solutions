#include<bits/stdc++.h>
using namespace std;
int arr[105];
int pos(int i,int N)
{
    int posi=i,M=arr[i];
    for (int j=i+1;j<N;j++)
        if (M>arr[j])
        {
            M=arr[j];
            posi=j;
        }
    return posi;
}

int main ()
{
    int cases,caseno=0,i,j,n;
    ///freopen("test.txt","r",stdin);
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d",&n);
        for (i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        int c=0;
        for (i=0;i<n;i++)
        {
            int loc=pos(i,n);
            ///cout<<loc<<endl;
            if (i!=loc)
            {
                swap(arr[i],arr[loc]);
                c++;
            }
        }
        printf("Case %d: %d\n",++caseno,c);
    }
    return 0;
}
