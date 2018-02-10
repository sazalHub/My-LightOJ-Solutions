#include<bits/stdc++.h>
#define ll long long
#define MAX 1050054
#define lmt 150010
using namespace std;
 
ll arr[lmt],cut,tree[MAX];
 
void build(ll node,ll l,ll r){
    ///cout<<node<<endl;
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
 
void add(ll node,ll l,ll r,ll loc){
    if (l==r){
        tree[node] = 1;
        return;
    }
 
    ll mid = (l+r)/2;
    ll lft = node*2;
    ll rgt = node*2 + 1;
 
    if (loc<=mid) add(lft,l,mid,loc);
    else add(rgt,mid+1,r,loc);
 
    tree[node] = tree[lft] + tree[rgt];
}
 
ll query(ll node,ll l,ll r,ll k){
    if (l==r){
        tree[node] = 0;
        return arr[l];
    }
 
    ll mid = (l+r)/2;
    ll lft = node*2;
    ll rgt = node*2 + 1;
 
    ll ret;
 
    if (tree[lft]<k) ret = query(rgt,mid+1,r,k-tree[lft]);
    else ret = query(lft,l,mid,k);
 
    tree[node] = tree[lft] + tree[rgt];
 
    return ret;
}
 
int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,caseno = 0,N,Q,P,ret;
    char ch;
    scanf("%lld",&cases);
    while(cases--){
        scanf("%lld %lld",&N,&Q);
 
        for (ll i=0;i<=150010;i++) arr[i] = -1;
 
        for (ll i=1;i<=N;i++) scanf("%lld",&arr[i]);
 
        build(1,1,lmt);
        cut = 0;
 
        printf("Case %lld:\n",++caseno);
 
        while(Q--){
            scanf("%c%c %lld",&ch,&ch,&P);
 
            if (ch=='a'){
                arr[++N] = P;
                add(1,1,lmt,N);
            }
            else{
                if (N-cut<P)
                    printf("none\n");
                else printf("%lld\n",query(1,1,lmt,P)),cut++;
            }
        }
    }
    return 0;
}
