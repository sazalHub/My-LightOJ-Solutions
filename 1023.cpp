#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll N,K,cnt;

void dp(ll srt,string x)
{
    ///cout<<srt<<" "<<x<<endl;
    if (K<=cnt)
        return;
    if (x.size()==N)
    {
        cout<<x<<"\n";
        x.erase(x.size()-1);
        cnt++;
        return;
    }
    for (ll i=0;i<N;i++)
    {
        bool fl = true;
        char ch = i+65;
        for (ll j=0;j<x.size() && fl;j++)
            if (x[j]==ch)
                fl = false;
        if(fl)
            dp(i,x+ch);
    }
}

int main ()
{
    ll cases,caseno=0;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld%lld",&N,&K);
        if (N==4 && K>24)
            K=24;
        if (N==3 && K>6)
            K=6;
        if (N==2 && K>2)
            K=2;
        if (N==1 && K>1)
            K=1;
        cnt=0;
        printf("Case %lld:\n",++caseno);
        dp(0,"");
    }
    return 0;
}
