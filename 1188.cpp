#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
ll N,Q;
ll tree[300010],arr[100010],ans[50010];
 
struct Query{
    ll r,idx;
    Query(ll R,ll id){
        r = R;
        idx = id;
    }
};
vector<Query>queries[100010];
vector<ll>position[100010];
 
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
 
    tree[node] = tree[lft] + tree[rgt];
}
 
ll query(ll node,ll l,ll r,ll from,ll to){
    if (l>to || r<from) return 0;
    if (from<=l && r<=to) return tree[node];
 
    ll mid = (l+r)/2;
    ll lft = node*2;
    ll rgt = node*2 + 1;
 
    return (query(lft,l,mid,from,to)+query(rgt,mid+1,r,from,to));
}
 
int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,caseno = 0,l,r;
    scanf("%lld",&cases);
    while(cases--){
 
        scanf("%lld%lld",&N,&Q);
        for (ll i=1;i<=N;i++) scanf("%lld",&arr[i]);
 
        for (ll i=0;i<=100005;i++){
            position[i].clear();
            queries[i].clear();
        }
 
        for (ll i=0;i<Q;i++){
            scanf("%lld%lld",&l,&r);
            queries[l].push_back(Query(r,i));
        }
 
        memset(tree,0,sizeof(tree));
 
        for (ll i=N;i>=1;i--) position[arr[i]].push_back(i);
 
        for (ll i=0;i<=100000;i++){
            if (position[i].size()>0){
                update(1,1,N,position[i].back(),1);
                position[i].pop_back();
            }
        }
 
        for (ll i=1;i<=N;i++){
            if (queries[i].size()>0){
                for (ll j=0;j<queries[i].size();j++){
                    ans[queries[i][j].idx] = query(1,1,N,i,queries[i][j].r);
                }
            }
            update(1,1,N,i,0);
            if (position[arr[i]].size()>0){
                update(1,1,N,position[arr[i]].back(),1);
                position[arr[i]].pop_back();
            }
        }
 
        printf("Case %lld:\n",++caseno);
        for (ll i=0;i<Q;i++)
            printf("%lld\n",ans[i]);
 
    }
    return 0;
}
