#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll CoUnT(ll tmp)
{
    ll cnt = 0;
    while(tmp>=5)
    {
        cnt++;
        tmp/=5;
    }
    ///cout<<cnt<<endl;
    return cnt;
}

ll power(ll base,ll pwr)
{
    ll ret,y;
    if (pwr==1) return base;
    if (pwr%2==1)
    {
        y = power(base,pwr/2);
        ret = y * y * base;
    }
    else
    {
        y = power(base,pwr/2);
        ret = y * y;
    }
    return ret;
}

ll check(ll N)
{
    ll cnt = 0;
    while(N!=0)
    {
        N=N/5;
        cnt+=N;
    }
    return cnt;
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,caseno=0,Q,cnt,assume,ans,ret;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld",&Q);
        assume = 5*Q;
        cnt = CoUnT(assume);
        ///cout<<cnt<<endl;
        ret = power(5,cnt);
        ///cout<<ret<<endl;
        ans = (4.0*Q*ret)/(ret-1);
        if (ans%5!=0)
            ans = ((ll)(ans/5)+1)*5;
        printf("Case %lld: ",++caseno);
        bool flag = false;
        ll tmp = ans;
        while(!flag)
        {
            ret = check(tmp);
            if (ret==Q)
            {
                flag = true;
                break;
            }
            if (ret>Q)
                break;
            tmp+=5;
        }
        while(!flag)
        {
            ret = check(tmp);
            if (ret==Q)
            {
                flag = true;
                break;
            }
            if (ret<Q)
                break;
            tmp-=5;
        }
        if (flag)
            printf("%lld\n",tmp);
        else
            printf("impossible\n");
    }
    return 0;
}

