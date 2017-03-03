#include<bits/stdc++.h>
#define ii int
using namespace std;

struct cities{
    ii u,v,w;
}links[55];
ii N,parent[105];

bool cmp(cities a,cities b)
{
    return (a.w<b.w);
}

ii find_root(ii r)
{
    if (parent[r]==r)
        return r;
    return parent[r] = find_root(parent[r]);
}

void kruskal(ii city)
{
    for (ii i=1;i<=city;i++)
        parent[i] = i;
    sort(links,links+N,cmp);

    ii ans = 0,edge = 0;
    for (ii i=0;i<N;i++)
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

    if (edge==city-1)
        printf("%d\n",ans);
    else
        printf("Impossible\n");

}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);

    ii cases,caseno=0,cost,u,v,city;
    string x,y;

    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d",&N);
        map<string,ii>track;
        city = 1;
        for (ii i=0;i<N;i++)
        {
            cin>>x>>y>>cost;
            if (track[x]==0)
                track[x] = city++;
            if (track[y]==0)
                track[y] = city++;
            links[i].u = track[x];
            links[i].v = track[y];
            links[i].w = cost;
        }

        printf("Case %d: ",++caseno);
        kruskal(city-1);

    }
    return 0;
}
