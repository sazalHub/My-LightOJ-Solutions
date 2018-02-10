#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
ll N,Q;
struct nodes{
    ll val,sum;
    bool status;
}tree[300010];
 
void DOWN(ll node,ll l,ll r){
 
    if (!tree[node].status) return;
 
    ll mid = (l+r)/2;
    ll lft = node*2;
    ll rgt = node*2 + 1;
 
    tree[lft].val = tree[rgt].val = tree[node].val;
    tree[lft].sum = (mid-l+1)*tree[lft].val;
    tree[rgt].sum = (r-mid)*tree[rgt].val;
    tree[lft].status = tree[rgt].status = true;
    tree[node].status = false;
}
 
void build(ll node,ll l,ll r){
 
    tree[node].status = false;
 
    if (l==r){
        tree[node].val = 0;
        tree[node].sum = 0;
        return;
    }
 
    ll mid = (l+r)/2;
    ll lft = node*2;
    ll rgt = node*2 + 1;
 
    build(lft,l,mid);
    build(rgt,mid+1,r);
 
    tree[node].sum = tree[lft].sum + tree[rgt].sum;
}
 
void update(ll node,ll l,ll r,ll from,ll to,ll v){
    if (l>to || r<from) return;
    if (from<=l && r<=to){
        tree[node].val = v;
        tree[node].sum = v*(r-l+1);
        tree[node].status = true;
        return;
    }
 
    DOWN(node,l,r);
 
    ll mid = (l+r)/2;
    ll lft = node*2;
    ll rgt = node*2 + 1;
 
    update(lft,l,mid,from,to,v);
    update(rgt,mid+1,r,from,to,v);
 
    tree[node].sum = tree[lft].sum + tree[rgt].sum;
}
 
ll query(ll node,ll l,ll r,ll from,ll to){
    if (l>to || r<from) return 0;
    if (from<=l && r<=to) return tree[node].sum;
 
    DOWN(node,l,r);
 
    ll mid = (l+r)/2;
    ll lft = node*2;
    ll rgt = node*2 + 1;
 
    ll ret1 = query(lft,l,mid,from,to);
    ll ret2 = query(rgt,mid+1,r,from,to);
 
    return (ret1+ret2);
}
 
int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,caseno = 0,type,l,r,v,sum,n,g;
    scanf("%lld",&cases);
    while(cases--){
        scanf("%lld%lld",&N,&Q);
 
        build(1,1,N);
 
        printf("Case %lld:\n",++caseno);
        for (ll i=1;i<=Q;i++){
            scanf("%lld%lld%lld",&type,&l,&r);
            l++,r++;
            if (type==1){
                scanf("%lld",&v);
                update(1,1,N,l,r,v);
            }
            else{
                sum = query(1,1,N,l,r);
                n = r-l+1;
                g = __gcd(sum,n);
                sum/=g,n/=g;
                printf("%lld",sum);
                if (n>1) printf("/%lld",n);
                printf("\n");
            }
        }
    }
    return 0;
}
 
