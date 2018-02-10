#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
struct data{
    ll value,pos;
    data(ll v,ll p){
        value = v,pos = p;
    }
};
stack<data>st;
data temp(0,0),ttemp(0,0);
 
int main ()
{
    ll cases,caseno=0,N,ans,MN,num;
    scanf("%lld",&cases);
    while(cases--){
        scanf("%lld",&N);
 
        ans = -INT_MAX;
        scanf("%lld",&num);
        st.push(data(num,1));
        for (ll i=2;i<=N;i++){
            scanf("%lld",&num);
            temp = st.top();
            if (temp.value<num){
                st.push(data(num,i));
                continue;
            }
            while(!st.empty()){
                ttemp = temp;
                temp = st.top();
                if (temp.value<num){
                    temp = ttemp;
                    break;
                }
                ans = max(ans,temp.value*abs(i-temp.pos));
                ///cout<<i<<" "<<ans<<endl;
                st.pop();
            }
            st.push(data(num,temp.pos));
        }
 
        while(!st.empty()){
            temp = st.top();
            ans = max(ans,temp.value*(N-temp.pos+1));
            ///cout<<temp.value<<" "<<temp.pos<<" "<<ans<<endl;
            st.pop();
        }
 
        printf("Case %lld: %lld\n",++caseno,ans);
    }
    return 0;
}
