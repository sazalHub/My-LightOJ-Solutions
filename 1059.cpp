#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct link{
    ll u,v,w;
}links[100005];
ll V,E,A,parent[10005];

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
    for (ll i=1;i<=V;i++) parent[i] = i;
    sort(links,links+E,cmp);

    ll ans = 0,airports = 0;
    for (ll i=0;i<E;i++)
    {
        if (links[i].w>=A)
            break;
        ll fp = find_root(links[i].u);
        ll tp = find_root(links[i].v);
        if (fp!=tp)
        {
            parent[fp] = tp;
            ans+=links[i].w;
        }
    }

    for (ll i=1;i<=V;i++)
    {
        if (find_root(i)==i)
            airports++;
    }

    printf("%lld %lld\n",ans+airports*A,airports);

}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,caseno=0;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld%lld%lld",&V,&E,&A);
        for (ll i=0;i<E;i++)
            scanf("%lld%lld%lld",&links[i].u,&links[i].v,&links[i].w);

        printf("Case %lld: ",++caseno);
        kruskal();
    }
    return 0;
}
