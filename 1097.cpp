#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[1500000],N,ans[100010],len,nth,tree[1429445];
 
void build(ll node,ll l,ll r){
    if (l==r){
        tree[node] = 1;
        return;
    }
 
    ll mid = (l+r)/2;
    ll lft = node*2;
    ll rgt = node*2 + 1;
 
    build(lft,l,mid);
    build(rgt,mid+1,r);
 
    tree[node] = tree[lft] + tree[rgt];
}
 
void update(ll node,ll l,ll r,ll K){
    if (l==r){
        ///cout<<tree[node].val<<endl;
        tree[node] = 0;
        return;
    }
 
    ll mid = (l+r)/2;
    ll lft = node*2;
    ll rgt = node*2 + 1;
 
    if (K<=tree[lft]) update(lft,l,mid,K);
    else update(rgt,mid+1,r,K-tree[lft]);
 
    tree[node] = tree[lft] + tree[rgt];
}
 
ll query(ll node,ll l,ll r,ll K){
    if (l==r) return arr[l];
 
    ll mid = (l+r)/2;
    ll lft = node*2;
    ll rgt = node*2 + 1;
 
    if (K<=tree[lft])
        return query(lft,l,mid,K);
    return query(rgt,mid+1,r,K-tree[lft]);
}
 
int main ()
{
    ///freopen("out.txt","w",stdout);
 
    N = 1;
    for (ll i=1;i<=1429439;i+=2){
        if ((i+1)%3==0) continue;
        ///cout<<i<<endl;
        arr[N++] = i;
    }
    ///cout<<N<<endl;
    ///cout<<arr[9]<<endl;
 
    build(1,1,N);
    ///cout<<1<<endl;
 
 
    ans[1] = 1,ans[2] = 3;
    len = 3;
 
    while(true){
        ///cout<<len<<endl;
        ans[len] = query(1,1,N,len);
        nth = ans[len];
        ///cout<<len<<" "<<nth<<endl;
        if (len>100000) break;
        ///if (len>20) break;
        ///cout<<"kata porbe"<<endl;
        while(nth<=1429435){
            update(1,1,N,nth);
            nth+=ans[len]-1;
            ///cout<<nth<<endl;
        }
        len++;
        ///cout<<ans[len]<<endl;
    }
 
    ///cout<<2<<endl;
 
    ///for (ll i=1;i<=100000;i++) cout<<ans[i]<<endl;
 
    ll cases,caseno = 0;
 
    scanf("%lld",&cases);
 
    while(cases--){
        scanf("%lld",&N);
        printf("Case %lld: %lld\n",++caseno,ans[N]);
    }
 
    return 0;
}
