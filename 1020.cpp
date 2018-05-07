#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long N,T,t;
    char s[10];
    scanf("%lld",&T);
    for (t=1;t<=T;t++)
    {
        scanf("%lld",&N);
        scanf("%s",s);
        printf("Case %lld: ",t);
        if (strcmp(s,"Alice")==0)
        {
            if (N%3==1)
                printf("Bob\n");
            else
                printf("Alice\n");
        }
        else if (strcmp(s,"Bob")==0)
        {
            if (N%3==0)
                printf("Alice\n");
            else
                printf("Bob\n");
        }
    }
    return 0;
}
