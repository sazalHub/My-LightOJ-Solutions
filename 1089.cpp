#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
ll tree[550050],N,Q,l,r,q[50050],len,arr[250010];
struct limit{
    ll l,r;
    limit(ll L,ll R){
        l = L,r = R;
    }
};
vector<limit>lmt;
map<ll,bool>track;
map<ll,ll>pos;
 
void update(ll node,ll l,ll r,ll from,ll to){
    if (l>to || r<from) return;
    if (from<=l && r<=to){
        tree[node]++;
        return;
    }
 
    ll mid = (l+r)/2;
    ll lft = node*2;
    ll rgt = node*2 + 1;
 
    update(lft,l,mid,from,to);
    update(rgt,mid+1,r,from,to);
 
    ///tree[node] = tree[lft] + tree[rgt];
}
 
ll query(ll node,ll l,ll r,ll loc,ll carry){
    if (l==r) return tree[node]+carry;
 
    ll mid = (l+r)/2;
    ll lft = node*2;
    ll rgt = node*2 + 1;
 
    if (loc<=mid) return query(lft,l,mid,loc,carry+tree[node]);
    else return query(rgt,mid+1,r,loc,carry+tree[node]);
}
 
int main ()
{
    ///build(1,0,100000000);
    ///return 0;
 
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,caseno = 0;
    scanf("%lld",&cases);
    while(cases--){
        memset(tree,0,sizeof(tree));
        pos.clear();
        track.clear();
        lmt.clear();
 
        scanf("%lld%lld",&N,&Q);
 
        len = 1;
 
        for (ll i=0;i<N;i++){
            scanf("%lld%lld",&l,&r);
            if (!track[l]){
                arr[len++] = l;
                track[l] = true;
            }
            if (!track[r]){
                arr[len++] = r;
                track[r] = true;
            }
            lmt.push_back(limit(l,r));
        }
 
        for (ll i=0;i<Q;i++){
            scanf("%lld",&q[i]);
            if (!track[q[i]]){
                arr[len++] = q[i];
                track[q[i]] = true;
            }
        }
 
        sort(arr+1,arr+len+1);
 
        for (ll i=1;i<=len;i++) pos[arr[i]] = i;
 
        for (ll i=0;i<lmt.size();i++) update(1,1,len,pos[lmt[i].l],pos[lmt[i].r]);
 
        printf("Case %lld:\n",++caseno);
        for (ll i=0;i<Q;i++) printf("%lld\n",query(1,1,len,pos[q[i]],0));
    }
    return 0;
}
