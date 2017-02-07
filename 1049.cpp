#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool visited[101];
ll V,x,y,c,ans;
map<ll,vector<ll> >graph;
map<ll,map<ll,ll> >cost;
map<ll,map<ll,bool> >link;
map<ll,ll>parent;

void DFS(ll st,ll &ans)
{
    if (visited[st]) return;
    visited[st] = true;
    ll len = graph[st].size();
    for (ll i=0;i<len;i++)
    {
        ll v = graph[st][i];
        ///cout<<v<<endl;
        if (!visited[v]&&v!=parent[st])
        {
            parent[v] = st;
            ///cout<<st<<" "<<v<<endl;
            if (link[st][v])
            {
                ///cout<<1<<endl;
                DFS(v,ans);
            }
            else
            {
                ///cout<<2<<endl;
                ans = ans + max(cost[v][st],cost[v][st]);
                DFS(v,ans);
            }
            ///cout<<ans<<endl;
        }
    }
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,caseno=0,ans,temp;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld",&V);
        link.clear();
        cost.clear();
        graph.clear();
        parent.clear();
        for (ll i=0;i<V;i++)
        {
            scanf("%lld%lld%lld",&x,&y,&c);
            graph[x].push_back(y);
            graph[y].push_back(x);
            cost[x][y] = c;
            link[x][y] = true;
        }
        ans = 99999999999999;
        for (ll i=0;i<2;i++)
        {
            ll v = graph[1][i];
            ///cout<<v<<endl;
            memset(visited,false,sizeof(visited));
            ///visited[1] = true;
            parent[v] = 1;
            if (link[1][v])
            {
                temp = 0;
                DFS(v,temp);
                ans = min(ans,temp);
            }
            else
            {
                temp = max(cost[1][v],cost[v][1]);
                DFS(v,temp);
                ans = min(ans,temp);
            }
            ///cout<<endl;
        }
        printf("Case %lld: %lld\n",++caseno,ans);
    }
    return 0;
}
