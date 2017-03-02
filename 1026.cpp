#include<bits/stdc++.h>
#define ii int
using namespace std;
vector<ii>graph[10005];
ii low[10005],dis[10005],Time,parent[10005];
bool visited[10005];

struct link{
    ii u,v;
    link(){}
    link(ii x,ii y){u = x,v = y;}
};
vector<link>bridge;
bool cmp(link a,link b)
{
    if (a.u==b.u)
        return (a.v<b.v);
    return (a.u<b.u);
}

void FindPaths(ii u)
{
    Time++;
    low[u] = dis[u] = Time;
    visited[u] = true;
    for (ii i=0;i<graph[u].size();i++)
    {
        ii v = graph[u][i];
        if (v==parent[u])
            continue;
        if (visited[v])
            low[u] = min(low[u],dis[v]);
        else
        {
            parent[v] = u;
            FindPaths(v);
            low[u] = min(low[u],low[v]);
            if (dis[u]<low[v])
                bridge.push_back(link(min(u,v),max(u,v)));
        }
    }
}

void sett(ii N)
{
    for (ii i=0;i<=N;i++)
    {
        visited[i] = false;
        low[i] = dis[i] = 0;
        parent[i] = -1;
    }
}

void CLEAR(ii N)
{
    for (ii i=0;i<=N;i++)
        graph[i].clear();
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ii cases,caseno=0,u,v,k,V;
    char ch[10];
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d",&V);

        for (ii i=0;i<V;i++)
        {
            scanf("%d",&u);
            scanf("%s",&ch);

            k = 0;
            for (ii i=1;i<strlen(ch)-1;i++)
                k = k*10 + (ch[i]-48);

            for (ii i=0;i<k;i++)
            {
                scanf("%d",&v);
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }

        sett(V);
        Time = 0;

        for (ii i=0;i<V;i++)
            if (!visited[i])
                FindPaths(i);

        printf("Case %d:\n",++caseno);
        k = bridge.size();
        printf("%d critical links\n",k);
        sort(bridge.begin(),bridge.end(),cmp);
        for (ii i=0;i<k;i++)
            printf("%d - %d\n",bridge[i].u,bridge[i].v);
        CLEAR(V);
        bridge.clear();
    }
    return 0;
}
