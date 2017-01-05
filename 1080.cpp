#include<bits/stdc++.h>
#define ll long long
using namespace std;

char str[100005];
struct nodes {
    int val;
    ll change;
}tree[3*100005];

void make(ll node,ll l,ll r)
{
    if (l==r)
    {
        ///cout<<node<<" "<<str[l-1]<<endl;
        tree[node].val = str[l-1];
        tree[node].change = 0;
        return;
    }
    ll lft = 2*node;
    ll rgt = 2*node + 1;
    ll mid = (l+r)/2;
    make(lft,l,mid);
    make(rgt,mid+1,r);
    tree[node].change = tree[lft].change + tree[rgt].change;
}

void update(ll node,ll f,ll la,ll l,ll r)
{
    ///cout<<1<<endl;
    if (r<f || la<l)
        return;
    ///cout<<2<<endl;
    if (l<=f && la<=r)
    {
        tree[node].change++;
        return;
    }
    ///cout<<3<<endl;
    ll lft = node*2;
    ll rgt = node*2+1;
    ll mid = (f+la)/2;
    update(lft,f,mid,l,r);
    update(rgt,mid+1,la,l,r);
    ///tree[node].change = tree[lft].change + tree[rgt].change;
    ///cout<<node<<" "<<tree[node].change<<endl;
}

int query(ll node,ll f,ll la,ll loc,ll carry)
{
    if (loc<f || loc>la)
        return 0;
    if (f==la && f==loc)
        return tree[node].change+carry;
    ll lft = node*2;
    ll rgt = node*2 + 1;
    ll  mid = (f+la)/2;
    ll ret1=0,ret2=0;
    if (loc<=mid)
        ret1 = query(lft,f,mid,loc,carry+tree[node].change);
    else
        ret2 = query(rgt,mid+1,la,loc,carry+tree[node].change);
    return ret1+ret2;
}

int main ()
{
    ll cases,caseno=0,Q,len,x,y;
    char ch[2];
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    scanf("%lld",&cases);
    getchar();
    while(cases--)
    {
        scanf("%s%lld",&str,&Q);
        len = strlen(str);
        make(1,1,len);
        ///cout<<endl;

        printf("Case %lld:\n",++caseno);
        for (ll i=0;i<Q;i++)
        {
            ///getchar();
            scanf("%s",&ch);
            if (ch[0]=='I')
            {
                ///cout<<1<<endl;
                scanf("%lld%lld",&x,&y);
                update(1,1,len,x,y);
            }
            else
            {
                scanf("%lld",&x);
                ll ret = query(1,1,len,x,0);
                ///cout<<"ret =  "<<ret<<endl;
                if (ret%2==0)
                    printf("%c\n",str[x-1]);
                else
                    printf("%c\n",(!(str[x-1]-48)+48));
            }
        }
    }
    return 0;
}
