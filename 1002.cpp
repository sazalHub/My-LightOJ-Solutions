#include<bits/stdc++.h>
#define ll int
#define MAX 22222
using namespace std;
ll V,E,u,v,w,T,len,dist[505];
map<ll,map<ll,ll> >track;

struct NODE{
    ll node,cost;
    NODE(){}
    NODE(ll n,ll c)
    {
        node = n,cost = c;
    }
}nodes,Nodes;

bool operator<(NODE a,NODE b)
{
    return (a.cost>b.cost);
}

map<ll,vector<NODE> >graph;

void Dijkstra(ll st)
{
    priority_queue<NODE>Q;
    Q.push(NODE(st,0));
    for (ll i=0;i<=V;i++) dist[i] = MAX;
    dist[st] = 0;
    ///cout<<"#"<<st<<endl;
    while(!Q.empty())
    {
        nodes = Q.top();
        Q.pop();
        len = graph[nodes.node].size();
        for (ll i=0;i<len;i++)
        {
            Nodes = graph[nodes.node][i];
            ll tmp = max(nodes.cost,Nodes.cost);
            if (tmp<dist[Nodes.node])
            {
                dist[Nodes.node] = tmp;
                Q.push(NODE(Nodes.node,tmp));
            }
        }
    }
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,caseno=0;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%d",&V,&E);
        graph.clear();
        track.clear();
        for (ll i=0;i<E;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            bool flag = false;
            if (track[u][v]==0)
                track[u][v] = track[v][u] = w,flag = true;
            else if (w<track[u][v])
                track[u][v] = track[v][u] = w,flag = true;
            if (flag)
            {
                graph[u].push_back(NODE(v,w));
                graph[v].push_back(NODE(u,w));
            }
        }
        scanf("%d",&T);
        printf("Case %d:\n",++caseno);
        Dijkstra(T);
        for (ll i=0;i<V;i++)
        {
            if (dist[i]==MAX)
                printf("Impossible\n");
            else
                printf("%d\n",dist[i]);
        }
    }
    return 0;
}
