#include<bits/stdc++.h>
#define ii int
using namespace std;

struct room{
    ii u,v,w;
}links[2505];
ii N,E,parent[55],total;

bool cmp(room a,room b)
{
    return (a.w<b.w);
}

ii find_root(ii r)
{
    if (r==parent[r])
        return r;
    return parent[r] = find_root(parent[r]);
}

void kruskal()
{
    for (ii i=1;i<=N;i++)
        parent[i] = i;
    sort(links,links+E,cmp);

    ii ans = 0,edge = 0;
    for (ii i=0;i<E;i++)
    {
        ii fp = find_root(links[i].u);
        ii tp = find_root(links[i].v);
        if (fp!=tp)
        {
            edge++;
            ans+=links[i].w;
            parent[fp] = tp;
        }
    }

    if (N-1==edge)
        printf("%d\n",total-ans);
    else
        printf("-1\n");
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ii cases,caseno=0,num;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d",&N);
        E = total = 0;
        for (ii i=1;i<=N;i++)
        {
            for (ii j=1;j<=N;j++)
            {
                scanf("%d",&num);
                if (num>0)
                    links[E].u = i,links[E].v = j,links[E++].w = num,total+=num;
            }
        }

        printf("Case %d: ",++caseno);
        kruskal();
    }
    return 0;
}
