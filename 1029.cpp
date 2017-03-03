#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct edge{
    ll u,v,w;
}edges[12005];
ll N,parent[105],E;

bool cmp(edge a,edge b)
{
    return (a.w<b.w);
}

ll find_root(ll r)
{
    if (parent[r]==r)
        return r;
    return parent[r] = find_root(parent[r]);
}

void kruskal()
{
    for (ll i=0;i<=N;i++)
        parent[i] = i;
    sort(edges,edges+E,cmp);
    ll ans = 0;
    for (ll i=0;i<E;i++)
    {
        ll fp = find_root(edges[i].u);
        ll tp = find_root(edges[i].v);
        if (fp!=tp)
        {
            ans+=edges[i].w;
            parent[fp] = tp;
        }
    }

    for (ll i=0;i<=N;i++)
        parent[i] = i;
    for (ll i=E-1;i>=0;i--)
    {
        ll fp = find_root(edges[i].u);
        ll tp = find_root(edges[i].v);
        if (fp!=tp)
        {
            ans+=edges[i].w;
            parent[fp] = tp;
        }
    }

    if (ans%2==0)
        printf("%lld\n",ans/2);
    else
        printf("%lld/2\n",ans);
}

int main ()
{
    ll cases,caseno=0,x,y,z;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld",&N);
        for (E=0;;E++)
        {
            scanf("%lld%lld%lld",&x,&y,&z);
            if (x+y+z==0)
                break;
            edges[E].u=x,edges[E].v=y,edges[E].w=z;
        }
        printf("Case %lld: ",++caseno);
        kruskal();
    }
    return 0;
}
