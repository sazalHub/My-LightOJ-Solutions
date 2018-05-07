#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool flag;
struct node{
	bool found;
	node* edge[15];

	node(){
		found = false;
		for (ll i=0;i<10;i++) edge[i] = NULL;
	}
} *root;

void insrt(char* msg, ll len){
	node* cur = root;
	for (ll i=0;i<len;i++){
		ll idx = msg[i] - '0';
		///cout<<idx;
		if (cur->edge[idx]==NULL) cur->edge[idx] = new node();
		cur = cur->edge[idx];
	}
	///cout<<endl;
	cur->found = true;
}

void consistent(node* cur){
	if (!flag) return;
	if (cur->found){
		for (ll i=0;i<10;i++){
			if (cur->edge[i]!=NULL){
				flag = false;
				return;
			}
		}
	}
	for (ll i=0;i<10;i++){
		if (cur->edge[i]!=NULL){
			///cout<<"call = "<<i<<endl;
			consistent(cur->edge[i]);
		}
	}
}

void del(node* cur){
	for (ll i=0;i<10;i++){
		if (cur->edge[i]) del(cur->edge[i]);
	}
	delete(cur);
}

int main (){

	ll cases,caseno = 0,N;
	char number[15];
	///freopen("in.txt","r",stdin);
	///freopen("out.txt","w",stdout);
	scanf("%lld",&cases);
	while(cases--){
		scanf("%lld",&N);
		///getchar();

		root = new node();
		for (ll i=0;i<N;i++){
			scanf("%s",&number);
			///cout<<number<<endl;
			insrt(number,strlen(number));
		}

		flag = true;

		for (ll i=0;i<10 && flag;i++){
			if (root->edge[i]!=NULL){
				///cout<<"i = "<<i<<endl;
				consistent(root->edge[i]);
			}
		}

		printf("Case %lld: ",++caseno);

		if (flag) printf("YES\n");
		else printf("NO\n");

		del(root);
	}
	return 0;
}


