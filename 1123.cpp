#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct link{
    ll u,v,w;
    link(){}
    link(ll a,ll b,ll c){u=a,v=b,w=c;}
};
vector<link>links;
ll V,E,parent[205];

bool cmp(link a,link b)
{
    return (a.w<b.w);
}

ll find_root(ll r)
{
    if (r==parent[r])
        return r;
    return parent[r] = find_root(parent[r]);
}


void kruskal()
{
    for (ll i=1;i<=V;i++)
        parent[i] = i;
    sort(links.begin(),links.end(),cmp);

    ll ans = 0,edges = 0,W=links.size();
    vector<link>edge;
    for (ll i=0;i<W&&edges<V-1;i++)
    {
        ll fp = find_root(links[i].u);
        ll tp = find_root(links[i].v);
        if (fp!=tp)
        {
            parent[fp] = tp;
            edge.push_back(link(links[i].u,links[i].v,links[i].w));
            edges++;
            ans+=links[i].w;
        }
    }

    links = edge;

    if (edges==V-1)
        printf("%lld\n",ans);
    else
        printf("-1\n");

}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,caseno=0,W,u,v,w;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld%lld",&V,&E);
        links.clear();
        printf("Case %lld:\n",++caseno);
        for (ll i=1;i<=E;i++)
        {
            scanf("%lld%lld%lld",&u,&v,&w);
            links.push_back(link(u,v,w));
            if (i<V-1)
                printf("-1\n");
            else
                kruskal();
        }
    }
    return 0;
}
