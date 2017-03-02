#include<bits/stdc++.h>
#define ll int
using namespace std;
vector<ll>graph[10005];
ll V,E,parent[10005],low[10005],dis[10005],Time;
bool visited[10005],points[10005];

void FindPoints(ll u)
{
    Time++;
    dis[u] = low[u] = Time;
    visited[u] = true;
    ll child = 0;
    for (ll i=0;i<graph[u].size();i++)
    {
        ll v = graph[u][i];
        if (v==parent[v])
            continue;
        if (visited[v])
            low[u] = min(low[u],dis[v]);
        else
        {
            parent[v] = u;
            FindPoints(v);
            low[u] = min(low[u],low[v]);
            if (dis[u]<=low[v]&&u!=1)
                points[u] = true;
            else
                child++;
        }
        if (u==1&&child>1)
            points[u] = true;
    }
}

void sett()
{
    for (ll i=1;i<=V+2;i++)
    {
        visited[i] = points[i] = false;
        dis[i] = low[i] = 0;
        parent[i] = -1;
    }
}

void CLEAR()
{
    for (ll i=1;i<=V;i++)
        graph[i].clear();
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,caseno=0,u,v,cnt;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%d",&V,&E);
        for (ll i=0;i<E;i++)
        {
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        sett();
        Time = 0;
        FindPoints(1);

        cnt = 0;
        for (ll i=1;i<=V;i++)
            if (points[i])
                cnt++;

        printf("Case %d: %d\n",++caseno,cnt);

        CLEAR();
    }
    return 0;
}
