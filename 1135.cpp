#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
struct nodes {
    ll zero,one,two,change;
    void Rotate()
    {
        ll tmp = two;
        two = one;
        one = zero;
        zero = tmp;
    }
} tree[500010];
 
void UP(ll node)
{
    ll lft = node*2,rgt = node*2 + 1;
    tree[node].zero = tree[lft].zero + tree[rgt].zero;
    tree[node].one = tree[lft].one + tree[rgt].one;
    tree[node].two = tree[lft].two + tree[rgt].two;
}
 
void DOWN(ll node)
{
    ll lft = node*2,rgt = node*2 + 1;
    tree[node].change%=3;
    tree[lft].change+=tree[node].change;
    tree[rgt].change+=tree[node].change;
 
    for (ll k=0; k<tree[node].change; k++) {
        tree[lft].Rotate();
        tree[rgt].Rotate();
    }
 
    tree[node].change = 0;
}
 
 
void build(ll node,ll l,ll r)
{
    if (l==r) {
        tree[node].zero = 1;
        tree[node].one = tree[node].two = tree[node].change = 0;
        return;
    }
 
    ll mid = (l+r)/2;
    ll lft = node*2;
    ll rgt = node*2 + 1;
 
    tree[node].zero = tree[node].one = tree[node].two = tree[node].change = 0;
 
    build(lft,l,mid);
    build(rgt,mid+1,r);
 
    UP(node);
}
 
void update(ll node,ll l,ll r,ll from,ll to)
{
    if (to<l || r<from) return;
    if (from<=l&&r<=to) {
        tree[node].Rotate();
        tree[node].change++;
        return;
    }
 
    DOWN(node);
 
    ll mid = (l+r)/2;
    ll lft = node*2;
    ll rgt = node*2 + 1;
 
    update(lft,l,mid,from,to);
    update(rgt,mid+1,r,from,to);
 
    UP(node);
}
 
ll query(ll node,ll l,ll r,ll from,ll to)
{
    if (to<l || r<from) return 0;
    if (from<=l && r<=to) {
        return tree[node].zero;
    }
 
    DOWN(node);
 
    ll mid = (l+r)/2;
    ll lft = node*2;
    ll rgt = node*2 + 1;
 
    ll ret1 = query(lft,l,mid,from,to);
    ll ret2 = query(rgt,mid+1,r,from,to);
 
    return ret1+ret2;
}
 
int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,caseno=0,N,Q,type,x,y;
    scanf("%lld",&cases);
    while(cases--) {
        scanf("%lld%lld",&N,&Q);
        build(1,1,N);
        printf("Case %lld:\n",++caseno);
        while(Q--) {
            scanf("%lld%lld%lld",&type,&x,&y);
            x++,y++;
            if (type==0) update(1,1,N,x,y);
            else printf("%lld\n",query(1,1,N,x,y));
        }
    }
    return 0;
}
