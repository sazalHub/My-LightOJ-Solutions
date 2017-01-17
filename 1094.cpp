#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,vector<ll> >graph;
map<ll,map<ll,ll> >graph_weight;
bool visited[30005];
ll weight[30005];

void DFS(ll start,ll W)
{
    if (visited[start]) return;
    visited[start] = true;
    weight[start]=W;
    for (ll i=0;i<graph[start].size();i++)
        DFS(graph[start][i],W+graph_weight[start][graph[start][i]]);
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,caseno=0,x,y,w,MX,MX_POS,N;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld",&N);
        ///cout<<N<<endl;
        graph.clear();
        graph_weight.clear();
        for (ll i=0;i<N-1;i++)
        {
            scanf("%lld%lld%lld",&x,&y,&w);
            ///cout<<x<<" "<<y<<" "<<w<<endl;
            graph[x].push_back(y);
            graph[y].push_back(x);
            graph_weight[x][y] = graph_weight[y][x] = w;
        }
        memset(visited,false,sizeof(visited));
        memset(weight,0,sizeof(weight));
        DFS(0,0);
        MX = weight[0],MX_POS = 0;
        for (ll i=1;i<N;i++)
        {
            if (MX<weight[i])
            {
                MX = weight[i];
                MX_POS = i;
            }
        }
        memset(visited,false,sizeof(visited));
        memset(weight,0,sizeof(weight));
        ///cout<<MX_POS<<endl;
        DFS(MX_POS,0);
        MX = weight[0];
        for (ll i=0;i<N;i++)
        {
            ///cout<<i<<" "<<weight[i]<<endl;
            if (MX<weight[i])
                MX = weight[i];
        }
        printf("Case %lld: %lld\n",++caseno,MX);
    }
    return 0;
}
