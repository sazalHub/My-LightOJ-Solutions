#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll nextOnory(ll N)
{
    ll pos,i,t;
    char str[10005],ch;
    i=0;
    while(N!=0)
    {
        t=N%2;
        str[i]=t+48;
        i++;
        N/=2;
    }
    for (;i<70;i++)
        str[i]='0';
    str[i]='\0';
    for (ll j=1;j<strlen(str);j++)
    {
        if (str[j]=='0'&&str[j-1]=='1')
        {
            pos=j-2;
            swap(str[j],str[j-1]);
            break;
        }
    }
    ll j=0;
    for (i=pos;i>=0;i--)
    {
        if (str[i]=='1'&&i>j)
        {
            swap(str[i],str[j]);
            j++;
        }
    }
    ll l= strlen(str);
    reverse(str,str+l);
    ll ans=0,lenght=l;
    for (i=0;i<lenght;i++)
    {
        ans=ans+(str[i]-48)*pow(2,l-1);
        l--;
    }
    return ans;
}
int main ()
{
    ll cases,caseno=0,num;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld",&num);
        ll ans=nextOnory(num);
        printf("Case %lld: %lld\n",++caseno,ans);
    }
    return 0;
}
