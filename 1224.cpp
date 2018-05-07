#include<bits/stdc++.h>
#define ll int
using namespace std;

struct node{
	bool found;
	ll cnt[5];
	node* edge[5];

	node(){
		found = false;
		for (ll i=0;i<4;i++){
			cnt[i] = 0;
			edge[i] = NULL;
		}
	}
}*root;

ll ans;

ll index(char ch){
	if (ch=='A') return 0;
	if (ch=='C') return 1;
	if (ch=='G') return 2;
	if (ch=='T') return 3;
}

void insrt(char* msg,ll len){

	node* cur = root;
	for (ll i=0;i<len;i++){
		ll idx = index(msg[i]);
		if (cur->edge[idx]==NULL) cur->edge[idx] = new node();
		cur->cnt[idx]++;
		ans = max(ans,cur->cnt[idx]*(i+1));
		cur = cur->edge[idx];
	}

	cur->found = true;
}

void del(node* cur){
	for (ll i=0;i<4;i++){
		if (cur->edge[i]) del(cur->edge[i]);
	}
	delete(cur);
}

int main (){
	ll cases,caseno = 0,N;
	char str[55];
	///freopen("in.txt","r",stdin);
	///freopen("out.txt","w",stdout);
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&N);
		ans = 0;
		root = new node();
		for (ll i=0;i<N;i++){
			scanf("%s",&str);
			insrt(str,strlen(str));
		}
		printf("Case %d: %d\n",++caseno,ans);
		del(root);
	}
	return 0;
}

