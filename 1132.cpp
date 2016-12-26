#include<bits/stdc++.h>
#define ll long long
#define mod 4294967296
using namespace std;
ll bionomial_co[55][55];

struct matrix {
    ll row,column;
    ll mat[55][55];
};

void bionomial_coefficients()
{
    memset(bionomial_co,0,sizeof(bionomial_co));
    for (ll i=0;i<55;i++)
        bionomial_co[i][0] = 1;
    for (ll i=1;i<55;i++)
        bionomial_co[i][i] = 1,bionomial_co[i][1] = i;
    for (ll i=3;i<55;i++)
        for (ll j=2;j<i;j++)
            bionomial_co[i][j] = (bionomial_co[i-1][j-1]%mod+bionomial_co[i-1][j]%mod)%mod;
}

matrix Mat_Mul(matrix A,matrix B)
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
                C.mat[i][j]=C.mat[i][j]+(A.mat[i][k]%mod*B.mat[k][j]%mod)%mod;
            }
            C.mat[i][j]%=mod;
        }
    }
    return C;
}

matrix Mat_Expo(matrix mat,ll power)
{
    if (power==1) return mat;
    if (power%2==1)
        return Mat_Mul(mat,Mat_Expo(mat,power-1));
    matrix ret = Mat_Expo(mat,power/2);
    return Mat_Mul(ret,ret);
}

int main ()
{
    bionomial_coefficients();
    ll cases,caseno=0,N,K;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld%lld",&N,&K);
        printf("Case %lld: ",++caseno);
        if (N==1)
        {
            printf("1\n");
            continue;
        }
        if (K==0)
        {
            printf("%lld\n",N%mod);
            continue;
        }
        if (K==1)
        {
            ll ans = ((N%mod*(N+1)%mod)%mod)/2;
            printf("%lld\n",ans%mod);
            continue;
        }
        matrix arr;
        arr.row = K+2;
        arr.column = K+2;
        for (ll i=0;i<=K;i++)
            for (ll j=0;j<=i;j++)
                arr.mat[i][j] = bionomial_co[i][i-j];
        for (ll i=0;i<=K;i++)
            arr.mat[K+1][i] = bionomial_co[K][K-i];
        arr.mat[K+1][K+1] = 1;

        matrix ret = Mat_Expo(arr,N-1);
        ll ans = 0;
        for (ll i=0;i<=K+1;i++)
            ans = (ans%mod + ret.mat[K+1][i]%mod)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
