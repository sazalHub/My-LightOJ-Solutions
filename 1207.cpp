#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll tree[600500],N,Q;
bool updt[600500];

struct Query{
	ll L,R;
	Query(ll l,ll r){
		L = l,R = r;
	}
};
vector<Query>queries;

void DOWN(ll node,ll l,ll r){
	if (!updt[node]) return;

	ll mid = (l+r)/2;
	ll lft = node*2;
	ll rgt = node*2 + 1;

	tree[lft] = mid - l + 1;
	tree[rgt] = r - mid;
	updt[lft] = updt[rgt] = true;

	updt[node] = false;
}

void build(ll node,ll l,ll r){
	updt[node] = false;
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

void update(ll node,ll l,ll r,ll from,ll to){
	if (l>to || r<from) return;
	if (from<=l && r<=to){
		tree[node] = r-l+1;
		updt[node] = true;
		return;
	}

	DOWN(node,l,r);

	ll mid = (l+r)/2;
	ll lft = node*2;
	ll rgt = node*2 + 1;

	update(lft,l,mid,from,to);
	update(rgt,mid+1,r,from,to);

	tree[node] = tree[lft] + tree[rgt];
}

ll query(ll node,ll l,ll r,ll from,ll to){
	///cout<<l<<" "<<r<<endl;
	if (l>to || r<from) return 0;
	if (from<=l && r<=to){
		///cout<<node<<" "<<tree[node]<<endl;
		return tree[node];
	}

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
	ll cases,caseno=0,l,r,ans,ret;

	scanf("%lld",&cases);
	while(cases--){
		scanf("%lld",&N);
		Q = N;
		N = N*2;

		build(1,1,N);

		for (ll i=0;i<Q;i++){
			scanf("%lld%lld",&l,&r);
			queries.push_back(Query(l,r));
		}

		ans = 0;
		for (ll i=queries.size()-1;i>=0;i--){
			l = queries[i].L,r = queries[i].R;
			///cout<<l<<" "<<r<<" "<<endl;
			ret = query(1,1,N,l,r);
			///cout<<ret<<endl;
			if (ret<(r-l+1)){
				ans++;
				update(1,1,N,l,r);
			}
		}

		printf("Case %lld: %lld\n",++caseno,ans);

		queries.clear();

	}

	return 0;
}

