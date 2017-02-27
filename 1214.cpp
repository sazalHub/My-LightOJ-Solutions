#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
    ll cases,caseno=0,B,rem;
    char A[205];

    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%s%lld",&A,&B);
        ///cout<<B<<endl;
        rem = 0;
        int i = 0;
        if (A[i]=='-')
            i++;
        for (;A[i];i++)
            rem = (rem*10+(A[i]-48))%B;
        printf("Case %lld: ",++caseno);
        if (rem==0)
            printf("divisible\n");
        else
            printf("not divisible\n");
    }
    return 0;
}
