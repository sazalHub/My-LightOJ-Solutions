#include<bits/stdc++.h>
#define ll long long
#define MAX 9999999999999
using namespace std;

struct NODE{
    ll node,cost;
    bool Proposed;
    NODE(){}
    NODE(ll nd,ll ct,bool pr)
    {
        node = nd,cost = ct,Proposed = pr;
    }
}nodes;

struct NODE1{
    ll used,node,cost;
}prev,next;

bool operator<(NODE1 a,NODE1 b)
{
    return (a.cost>b.cost);
}

map<ll,vector<NODE> >graph;
ll V,E,u,v,w,len,dist[15][10005],K,D;

ll DIJKSTRA()
{
    for (ll i=0;i<13;i++)
        for (ll j=0;j<=V;j++)
            dist[i][j] = MAX;

    priority_queue<NODE1>Q;
    prev.node = 0;
    prev.cost = 0;
    prev.used = 0;
    Q.push(prev);
    dist[0][0] = 0;
    while(!Q.empty())
    {
        prev = Q.top();
        Q.pop();
        if (prev.node==V-1)
            return prev.cost;
        len = graph[prev.node].size();
        for (ll i=0;i<len;i++)
        {
            nodes = graph[prev.node][i];
            next.node = nodes.node;
            next.cost = prev.cost + nodes.cost;
            next.used = prev.used;
            if (nodes.Proposed)
                next.used++;
            if (next.used<=D && next.cost<dist[next.used][next.node])
            {
                dist[next.used][next.node] = next.cost;
                Q.push(next);
            }
        }
    }
    return -1;
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,caseno=0;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld%lld%lld%lld",&V,&E,&K,&D);
        graph.clear();
        for (ll i=0;i<E;i++)
        {
            scanf("%lld%lld%lld",&u,&v,&w);
            graph[u].push_back(NODE(v,w,false));
            ///graph[v].push_back(NODE(u,w,false));
        }
        for (ll i=0;i<K;i++)
        {
            scanf("%lld%lld%lld",&u,&v,&w);
            graph[u].push_back(NODE(v,w,true));
            ///graph[v].push_back(NODE(u,w,true));
        }
        printf("Case %lld:",++caseno);
        ll ans = DIJKSTRA();
        if (ans!=-1)
            printf(" %lld\n",ans);
        else
            printf(" Impossible\n");
    }
    return 0;
}
