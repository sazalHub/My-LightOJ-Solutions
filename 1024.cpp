#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll primes[11111],len = 0,ln;

void solve()
{
    primes[len++] = 2;
    bool vis[11111];
    for (ll i=3;i<=10005;i+=2)
    {
        if (!vis[i])
        {
            primes[len++] = i;
            for (ll j=i*i;j<=10005;j+=2*i)
                vis[j] = true;
        }
    }
}

string multiply(string a, ll b)
{
    ll carry = 0,la = a.size();
    for (ll i=0;i<la;i++)
    {
        carry+=(a[i]-48)*b;
        a[i] = (carry%10+48);
        carry/=10;
    }
    while(carry!=0)
    {
        a+=(carry%10+48);
        carry/=10;
    }
    return a;
}

int main ()
{
    solve();
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,caseno=0,N,num;

    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld",&N);
        vector<ll>present;
        map<ll,ll>CNT;
        bool vis[10005] = {false};

        for (ll i=0;i<N;i++)
        {
            scanf("%lld",&num);
            for (ll j=0;j<len&&primes[j]*primes[j]<=num;j++)
            {
                if (num%primes[j]==0)
                {
                    ll cnt = 1;
                    while(num%primes[j]==0)
                        cnt*=primes[j],num/=primes[j];
                    if (!vis[primes[j]])
                    {
                        present.push_back(primes[j]);
                        CNT[primes[j]] = cnt;
                        vis[primes[j]] = true;
                    }
                    else
                        CNT[primes[j]] = max(CNT[primes[j]],cnt);
                }
            }
            if (num>1)
            {
                if (!vis[num])
                {
                    present.push_back(num);
                    CNT[num] = num;
                    vis[num] = true;
                }
                else
                    CNT[num] = max(CNT[num],num);
            }
        }

        string lcm = "1";
        ln = present.size();
        for (ll i=0;i<ln;i++)
            lcm = multiply(lcm,CNT[present[i]]);

        printf("Case %lld: ",++caseno);
        ln = lcm.size();
        for (ll i=ln-1;i>=0;i--)
            printf("%c",lcm[i]);
        printf("\n");
        ///cout<<ret<<endl;
    }
    return 0;
}
