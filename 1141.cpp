#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool visited[1005];
vector<ll>primes;
map<ll,vector<ll> >graph;
ll len,S,T,level[1005];

void PrimeGenerator()
{
    primes.push_back(2);
    for (ll i=3;i<=1001;i+=2)
    {
        if (!visited[i])
        {
            ///cout<<i<<endl;
            primes.push_back(i);
            for (ll j=i*i;j<=1001;j+=2*i)
                visited[j] = true;
        }
    }
    len = primes.size();
}

void Factorise()
{
    for (ll i=1;i<=1001;i++)
    {
        ll temp = i;
        for (ll j=0;primes[j]*primes[j]<=temp;j++)
        {
            ll cnt = 0;
            while(temp%primes[j]==0)
            {
                temp/=primes[j];
                cnt++;
            }
            if (cnt>0&&primes[j]!=i)
                graph[i].push_back(primes[j]);
        }
        if (temp>1&&temp!=i)
            graph[i].push_back(temp);
    }
}

void BFS(ll st)
{
    memset(visited,false,sizeof(visited));
    memset(level,0,sizeof(level));
    queue<ll>Q;
    level[st]=0;
    visited[st] = true;
    Q.push(st);
    while(!Q.empty())
    {
        ll u = Q.front();
        Q.pop();
        ///cout<<"U = "<<u<<endl;;
        len = graph[u].size();
        ///cout<<len<<endl;
        for (ll i=0;i<len;i++)
        {
            ///cout<<graph[u][i]<<" ";
            ll v = u + graph[u][i];
            if (!visited[v]&&v<=T)
            {
                ///cout<<v<<endl;
                visited[v] = true;
                level[v] = level[u] + 1;
                Q.push(v);
            }
        }
    }
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    PrimeGenerator();
    Factorise();
    ll cases,caseno=0;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld%lld",&S,&T);
        BFS(S);
        printf("Case %lld:",++caseno);
        if (!visited[T])
            printf(" -1\n");
        else
            printf(" %lld\n",level[T]);
    }
    return 0;
}
