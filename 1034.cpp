#include<bits/stdc++.h>
using namespace std;
vector<int>graph[10001];
int V,E,a,b;
bool visited[2][10001];
stack<int>TopSorted;

void DFS(int u,int type)
{
    visited[type][u] = true;
    int len = graph[u].size();
    for (int i=0;i<len;i++)
    {
        int v = graph[u][i];
        if (!visited[type][v])
            DFS(v,type);
    }
    if (type==0)
        TopSorted.push(u);
}

int main ()
{
    int cases,caseno=0,Switch;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%d",&V,&E);
        for (int i=0;i<E;i++)
        {
            scanf("%d%d",&a,&b);
            graph[a].push_back(b);
        }

        for (int i=1;i<=V;i++) visited[0][i] = visited[1][i] = false;

        for (int i=1;i<=V;i++)
        {
            if (!visited[0][i])
                DFS(i,0);
        }

        Switch = 0;
        while(!TopSorted.empty())
        {
            a = TopSorted.top();
            TopSorted.pop();
            if (!visited[1][a])
                DFS(a,1),Switch++;
        }

        printf("Case %d: %d\n",++caseno,Switch);

        for (int i=1;i<=V;i++)
            graph[i].clear();
    }
    return 0;
}

