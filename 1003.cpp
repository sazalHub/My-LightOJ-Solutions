#include<bits/stdc++.h>
#define ll int
using namespace std;
vector<ll>graph[20001];
ll V,E;
bool flag;
int visited[20001];

void DFS(ll u)
{
    ll v,len;
    visited[u] = 1;
    len = graph[u].size();
    for (ll i=0;i<len;i++)
    {
        v = graph[u][i];
        if (visited[v]==1)
        {
            flag = true;
            return;
        }
        DFS(v);
    }
    visited[u] = 2;
}

int main ()
{
    ll cases,caseno=0;
    string x,y;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d",&E);

        map<string,ll>track;
        V = 0;
        for (ll i=0;i<E;i++)
        {
            cin>>x>>y;
            if (track[x]==0)
                track[x] = ++V;
            if (track[y]==0)
                track[y] = ++V;
            graph[track[x]].push_back(track[y]);
            ///cout<<x<<" "<<track[x]<<" "<<y<<" "<<track[y]<<endl;
        }

        for (ll i=1;i<=V;i++)
            visited[i] = 0;

        flag = false;
        for (ll i=1;i<=V&&!flag;i++)
        {
            if (visited[i]==0)
                DFS(i);
        }

        printf("Case %d: ",++caseno);
        if (!flag)
            printf("Yes\n");
        else
            printf("No\n");

        for (ll i=1;i<=V;i++)
            graph[i].clear();
    }
    return 0;
}
