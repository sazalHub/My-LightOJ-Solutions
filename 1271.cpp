#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,vector<ll> >graph;
bool visited[50005];
ll N,num,prev,parent[50005],level[50005],Start,End,V,u,v,len;

void BFS()
{
    for (ll i=1;i<=V+5;i++)
        parent[i] = i,visited[i] = false,sort(graph[i].begin(),graph[i].end());
    queue<ll>Q;
    Q.push(Start);
    visited[Start] = true;
    level[Start] = 0;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        len = graph[u].size();
        for (ll i=0;i<len;i++)
        {
            v = graph[u][i];
            if (!visited[v])
            {
                level[v] = level[u] + 1;
                visited[v] = true;
                parent[v] = u;
                Q.push(v);
            }
        }
    }
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,caseno = 0;
    scanf("%lld",&cases);
    while(cases--)
    {
        graph.clear();
        scanf("%lld",&N);
        v = 0;
        for (ll i=0;i<N;i++)
        {
            scanf("%lld",&num);
            V = max(V,num);
            if (i==0)
                Start = num;
            else if (i==N-1)
                End = num;
            if (i>0)
            {
                graph[prev].push_back(num);
                graph[num].push_back(prev);
            }
            prev = num;
        }
        BFS();
        printf("Case %lld:\n",++caseno);
        vector<ll>ans;
        v = End;
        while(parent[v]!=v)
        {
            ans.push_back(v);
            v = parent[v];
        }
        ans.push_back(v);
        len = ans.size();
        for (ll i=len-1;i>=0;i--)
        {
            printf("%lld",ans[i]);
            if (i>0)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
