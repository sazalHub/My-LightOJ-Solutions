#include<bits/stdc++.h>
#define in int
using namespace std;

int main ()
{
    in cases,caseno=0,a,b;
    char ch,c1,c2;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%c%c%c%d",&a,&c1,&ch,&c2,&b);
        double angle = atan((b*1.00)/a);
        double len = (200.00*a)/(a*1.0+sqrt(a*a+b*b)*angle);
        double wide = (b*1.00/a)*len;
        printf("Case %d: %0.10lf %0.10lf\n",++caseno,len,wide);
    }
    return 0;
}

