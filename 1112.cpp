#include<bits/stdc++.h>
using namespace std;
#define limit 100003
#define ll long long
ll arr[limit],tree[limit*3];

void make(ll num,ll i,ll j)
{
    if (i==j)
    {
        tree[num]=arr[j];
        return;
    }
    ll l=2*num;
    ll r=2*num+1;
    ll mid=(i+j)/2;
    make(l,i,mid);
    make(r,mid+1,j);
    tree[num]=tree[l]+tree[r];
}

void update(ll num,ll i,ll j,ll loc)
{
    if (loc<i || loc>j)
        return;
    if (i==j&&i==loc)
    {
        tree[num]=arr[loc];
        return;
    }
    ll l=num*2;
    ll r=num*2+1;
    ll mid=(i+j)/2;
    update(l,i,mid,loc);
    update(r,mid+1,j,loc);
    tree[num]=tree[l]+tree[r];
}

ll find_sum(ll num,ll i,ll j,ll f,ll la)
{
    if (f>j || la<i)
        return 0;
    if (i>=f && j<=la)
        return tree[num];
    ll l=num*2;
    ll r=num*2+1;
    ll mid=(i+j)/2;
    ll sum1=find_sum(l,i,mid,f,la);
    ll sum2=find_sum(r,mid+1,j,f,la);
    return sum1+sum2;
}

int main ()
{
    ll cases,caseno=0,n,q,i;
    ///freopen("test.txt","r",stdin);
    scanf("%lld",&cases);

    while(cases--)
    {
        scanf("%lld%lld",&n,&q);
        for (i=1;i<=n;i++)
            scanf("%lld",&arr[i]);
        make(1,1,n);

        printf("Case %lld:\n",++caseno);
        for (i=0;i<q;i++)
        {
            ll type,fa,las;
            scanf("%lld%lld",&type,&fa);
            if (type==1)
            {
                printf("%lld\n",arr[fa+1]);
                arr[fa+1]=0;
                update(1,1,n,fa+1);
            }
            else if (type==2)
            {
                ll value;
                scanf("%lld",&value);
                arr[fa+1]+=value;
                update(1,1,n,fa+1);
            }
            else
            {
                scanf("%lld",&las);
                ll ans=find_sum(1,1,n,fa+1,las+1);
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}

