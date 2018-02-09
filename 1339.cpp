#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct nodes{
	ll lval,rval,lbest,rbest,best;
}tree[300010];
ll N,C,Q,arr[100010];

void build(ll node,ll l,ll r){

	if (l==r){
		tree[node].lval = tree[node].rval = arr[l];
		tree[node].lbest = tree[node].rbest = tree[node].best = 1;
		return;
	}

	ll mid = (l+r)/2;
	ll lft = node*2;
	ll rgt = node*2 + 1;

	build(lft,l,mid);
	build(rgt,mid+1,r);

	tree[node].lval = tree[lft].lval;
	tree[node].rval = tree[rgt].rval;
	tree[node].lbest = tree[lft].lbest;
	tree[node].rbest = tree[rgt].rbest;
	tree[node].best = 0;

	if (tree[lft].lval == tree[rgt].lval) tree[node].lbest+=tree[rgt].lbest;
	if (tree[lft].rval == tree[rgt].rval) tree[node].rbest+=tree[lft].rbest;
	if (tree[lft].rval == tree[rgt].lval) tree[node].best = tree[lft].rbest + tree[rgt].lbest;

	tree[node].best = max(tree[node].best,max(tree[lft].best,tree[rgt].best));
}

nodes query(ll node,ll l,ll r,ll from,ll to){
	if (l>to || r<from){
		nodes nn;
		nn.lval = nn.rval = nn.rbest = nn.lbest = nn.best = 0;
		return nn;
	}

	if (from<=l && r<=to) return tree[node];

	ll mid = (l+r)/2;
	ll lft = node*2;
	ll rgt = node*2 + 1;

	nodes res;
	nodes left = query(lft,l,mid,from,to);
	nodes right = query(rgt,mid+1,r,from,to);

	res.lval = left.lval;
	res.rval = right.rval;
	res.lbest = left.lbest;
	res.rbest = right.rbest;
	res.best = 0;

	if (left.lval == right.lval) res.lbest+=right.lbest;
	if (left.rval == right.rval) res.rbest+=left.rbest;
	if (left.rval == right.lval) res.best = left.rbest + right.lbest;

	res.best = max(res.best,max(left.best,right.best));

	return res;
}

int main ()
{
	ll cases,caseno = 0,l,r;
	scanf("%lld",&cases);
	while(cases--){
		scanf("%lld%lld%lld",&N,&C,&Q);
		for (ll i=1;i<=N;i++) scanf("%lld",&arr[i]);

		build(1,1,N);

		printf("Case %lld:\n",++caseno);
		for (ll i=0;i<Q;i++){
			scanf("%lld%lld",&l,&r);
			printf("%lld\n",query(1,1,N,l,r).best);
		}
	}
	return 0;
}

