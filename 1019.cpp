#include<bits/stdc++.h>
#define ll int
#define MAX 1000000000
using namespace std;

struct EDGE{
    ll next,cost;
    EDGE(){}
    EDGE(ll n,ll c)
    {
        next = n,cost = c;
    }
}U,V;

bool operator<(EDGE a,EDGE b)
{
    return (a.cost>b.cost);
}
ll dist[101],len;

void Dijkstra(vector<EDGE>graph[101],ll n)
{
    for (ll i=1;i<=n;i++) dist[i] = MAX;
    priority_queue<EDGE>Q;
    dist[1] = 0;
    Q.push(EDGE(1,0));
    while(!Q.empty())
    {
        U = Q.top();
        Q.pop();
        len = graph[U.next].size();
        for (ll i=0;i<len;i++)
        {
            V = graph[U.next][i];
            if (dist[U.next]+V.cost<dist[V.next])
            {
                dist[V.next] = dist[U.next] + V.cost;
                Q.push(EDGE(V.next,dist[V.next]));
            }
        }
    }
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ll cases,caseno=0,N,M,u,v,w;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%d",&N,&M);
        vector<EDGE>graph[101];
        for (ll i=0;i<M;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            graph[u].push_back(EDGE(v,w));
            graph[v].push_back(EDGE(u,w));
        }

        Dijkstra(graph,N);

        printf("Case %d: ",++caseno);
        if (dist[N]==MAX)
            printf("Impossible\n");
        else
            printf("%d\n",dist[N]);
    }
    return 0;
}
