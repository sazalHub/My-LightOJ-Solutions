#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct matrix{
    ll row,column;
    ll mat[10][10];
};

matrix Mat_Mul(matrix A,matrix B,ll mod)
{
    matrix C;
    C.row = A.row;
    C.column = B.column;
    for (ll i=0;i<C.row;i++)
    {
        for (ll j=0;j<C.column;j++)
        {
            C.mat[i][j] = 0;
            for (ll k=0;k<A.column;k++)
            {
                C.mat[i][j]=(C.mat[i][j]%mod + (A.mat[i][k]%mod * B.mat[k][j]%mod)%mod)%mod;
            }
        }
    }
    return C;
}

matrix Mat_Expo(matrix A,ll n,ll mod)
{
    if (n==1) return A;
    if (n%2==1)
        return Mat_Mul(A,Mat_Expo(A,n-1,mod),mod);
    matrix ret = Mat_Expo(A,n/2,mod);
    return Mat_Mul(ret,ret,mod);
}

int main ()
{
    ll cases,caseno=0,a,b,n,m;
    ll md[] = {10,100,1000,10000};
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&n,&m);
        if (n==0)
        {
            printf("Case %lld: %lld\n",++caseno,a%md[m-1]);
            continue;
        }
        if (n==1)
        {
            printf("Case %lld: %lld\n",++caseno,b%md[m-1]);
            continue;
        }
        matrix arr;
        arr.row = 2;
        arr.column = 2;
        arr.mat[0][0] = 1,arr.mat[0][1] = 1;
        arr.mat[1][0] = 1,arr.mat[1][1] = 0;

        ll mod = md[m-1];
        matrix ret = Mat_Expo(arr,n-1,mod);
        ll ans = ((ret.mat[0][0]*b)%mod + (ret.mat[0][1]*a)%mod)%mod;
        printf("Case %lld: %lld\n",++caseno,ans%mod);
    }
    return 0;
}
