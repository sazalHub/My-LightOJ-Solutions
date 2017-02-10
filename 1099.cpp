#include<bits/stdc++.h>
#define ll long long
#define MAX 999999999999999
using namespace std;
ll V,E,u,v,cost,len,dist1[5005],dist2[5005],MN[5005];
bool visited[5005],Back[5005];

struct NODE{
    ll node,cost;
}nodes,Nodes;
map<ll,vector<NODE> >graph;

bool operator<(NODE a,NODE b)
{
    return (a.cost>b.cost);
}

ll DIJKSTRA()
{
    for (ll i=1;i<=V;i++)
    {
        dist1[i] = dist2[i] = MAX;
        len = graph[i].size();
        MN[i] = MAX;
        for (ll j=0;j<len;j++)
        {
            nodes = graph[i][j];
            MN[i] = min(MN[i],2*nodes.cost);
        }
    }

    memset(visited,false,sizeof(visited));
    memset(Back,false,sizeof(Back));
    priority_queue<NODE>Q;
    nodes.node = 1;
    nodes.cost = 0;
    dist1[1] = 0;
    Q.push(nodes);
    while(!Q.empty())
    {
        nodes = Q.top();
        Q.pop();
        if (visited[nodes.node])
        {
            if (dist1[nodes.node]<nodes.cost && dist2[nodes.node]>=nodes.cost)
                dist2[nodes.node] = nodes.cost;
            else
                continue;
        }
        else
            visited[nodes.node] = true;
        len = graph[nodes.node].size();
        for (ll i=0;i<len;i++)
        {
            Nodes = graph[nodes.node][i];
            if (nodes.cost+Nodes.cost<dist1[Nodes.node])
            {
                dist2[Nodes.node] = dist1[Nodes.node];
                dist1[Nodes.node] = nodes.cost+Nodes.cost;
                Nodes.cost = dist1[Nodes.node];
                Q.push(Nodes);
            }
            else if (nodes.cost+Nodes.cost<dist2[Nodes.node])
            {
                if (nodes.cost+Nodes.cost>dist1[Nodes.node])
                {
                    Nodes.cost = nodes.cost+Nodes.cost;
                    Q.push(Nodes);
                }
            }
        }
        if (!Back[nodes.node])
        {
            Back[nodes.node] = true;
            nodes.cost = nodes.cost + MN[nodes.node];
            Q.push(nodes);
        }
    }
    return dist2[V];
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,caseno=0;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld%lld",&V,&E);
        graph.clear();
        for (ll i=0;i<E;i++)
        {
            scanf("%lld%lld%lld",&u,&v,&cost);
            nodes.node = v;
            nodes.cost = cost;
            graph[u].push_back(nodes);
            nodes.node = u;
            graph[v].push_back(nodes);
        }
        printf("Case %lld: %lld\n",++caseno,DIJKSTRA());
    }
    return 0;
}

