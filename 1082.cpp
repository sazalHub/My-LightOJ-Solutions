#include<bits/stdc++.h>
using namespace std;
#define limit 100003
#define ll long long
ll arr[limit],tree[limit*3];

void make_min(ll node,ll i,ll j)
{
    if (i==j)
    {
        tree[node]=arr[j];
        return;
    }
    ll l=node*2;
    ll r=node*2+1;
    ll mid=(i+j)/2;
    make_min(l,i,mid);
    make_min(r,mid+1,j);
    tree[node]=min(tree[l],tree[r]);
}

ll find_min(ll node,ll i,ll j,ll f,ll la)
{
    if (f>j || la<i)
        return -1;
    if (i>=f && j<=la)
        return tree[node];
    ll l=node*2;
    ll r=node*2+1;
    ll mid=(i+j)/2;

    ll min1=find_min(l,i,mid,f,la);
    ll min2=find_min(r,mid+1,j,f,la);

    if (min1!=-1 && min2!=-1)
        return min(min1,min2);
    else
    {
        if (min1==-1)
            return min2;
        else
            return min1;
    }
}


int main ()
{
    ll cases,caseno=0,numbers,querys;

    ///freopen("test.txt","r",stdin);
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld%lld",&numbers,&querys);
        for (ll i=1;i<=numbers;i++)
            scanf("%lld",&arr[i]);
        make_min(1,1,numbers);

        printf("Case %lld:\n",++caseno);
        ll I,J;
        for (ll i=1;i<=querys;i++)
        {
            scanf("%lld%lld",&I,&J);
            ll ans=find_min(1,1,numbers,I,J);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
