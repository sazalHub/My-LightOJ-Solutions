#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
ll tree[500010];
 
struct data{
    ll val,pos;
}arr[100010];
 
bool cmp(data a,data b){
    if (a.val==b.val) return (a.pos>b.pos);
    return (a.val<b.val);
}
 
void build(ll node,ll l,ll r){
    if (l==r){
        tree[node] = 0;
        return;
    }
 
    ll mid = (l+r)/2;
    ll lft = node*2;
    ll rgt = node*2 + 1;
 
    build(lft,l,mid);
    build(rgt,mid+1,r);
 
    tree[node] = tree[lft] + tree[rgt];
}
 
ll query(ll node,ll l,ll r,ll from,ll to){
    if (l>to || r<from) return 0;
    if (from<=l && r<=to) return tree[node];
 
    ll mid = (l+r)/2;
    ll lft = node*2;
    ll rgt = node*2 + 1;
 
    return (query(lft,l,mid,from,to)+query(rgt,mid+1,r,from,to))%MOD;
}
 
void update(ll node,ll l,ll r,ll loc,ll val){
    if (l==r){
        tree[node] = val;
        return;
    }
 
    ll mid = (l+r)/2;
    ll lft = node*2;
    ll rgt = node*2 + 1;
 
    if (loc<=mid) update(lft,l,mid,loc,val);
    else update(rgt,mid+1,r,loc,val);
 
    tree[node] = (tree[lft] + tree[rgt])%MOD;
}
 
int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,caseno=0,N,ans,ret;
    scanf("%lld",&cases);
    while(cases--){
        scanf("%lld",&N);
 
        for (ll i=1;i<=N;i++){
            scanf("%lld",&arr[i].val);
            arr[i].pos = i;
        }
 
        sort(arr+1,arr+N+1,cmp);
        ///for (ll i=1;i<=N;i++)
            ///cout<<arr[i].pos<<" "<<arr[i].val<<endl;
 
        build(1,1,N);
 
        ans = 0;
 
        for (ll i=1;i<=N;i++){
            ret = query(1,1,N,1,arr[i].pos-1) + 1;
            ///cout<<ret<<endl;
            update(1,1,N,arr[i].pos,ret);
            ans = (ans+ret)%MOD;
        }
 
        printf("Case %lld: %lld\n",++caseno,ans);
    }
    return 0;
}
