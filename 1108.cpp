#include<bits/stdc++.h>
#define ll int
int MAX = 1000000000;
using namespace std;
bool visited[1010];
ll N,M,u,v,w,dist[1005],V,len;

struct EDGE{
    ll from,to,cost;
}edge,edges[2005];

map<ll,vector<ll> >graph;

void DFS(ll st)
{
    ///cout<<st<<endl;
    if (visited[st]) return;
    visited[st] = true;
    for (ll i=0;i<graph[st].size();i++)
        DFS(graph[st][i]);
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,caseno=0;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%d",&N,&M);

        graph.clear();
        for (ll i=0;i<M;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            graph[v].push_back(u);
            edges[i].from = v,edges[i].to = u,edges[i].cost = w;
        }

        for (ll i=0;i<=N;i++)
            visited[i] = false,dist[i] = MAX;

        for (ll i=0;i<N;i++)
        {
            graph[N].push_back(i);
            edges[M].from = N,edges[M].to = i,edges[M].cost = 1;
        }

        dist[N] = 0;
        for (ll i=0;i<N;i++)
        {
            for (ll j=0;j<M+1;j++)
            {
                edge = edges[j];
                if (dist[edge.from]+edge.cost<dist[edge.to])
                    dist[edge.to] = dist[edge.from] + edge.cost;
            }
        }
        ///cout<<"#1"<<endl;

        for (ll i=0;i<N;i++)
        {
            for (ll j=0;j<M+1;j++)
            {
                edge = edges[j];
                if (dist[edge.from]+edge.cost<dist[edge.to])
                    DFS(edge.to);
            }
        }
        ///cout<<"#2"<<endl;

        printf("Case %d:",++caseno);

        bool flag = true;
        for (ll i=0;i<N;i++)
        {
            if (visited[i])
                printf(" %d",i),flag = false;
        }
        if (flag)
            printf(" impossible");
        printf("\n");
    }
    return 0;
}
