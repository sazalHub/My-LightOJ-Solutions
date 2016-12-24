#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct matrix {
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
                C.mat[i][j]=(C.mat[i][j] + A.mat[i][k]* B.mat[k][j])%mod;
            }
        }
    }
    return C;
}

matrix Mat_Expo(matrix mat,ll power,ll mod)
{
    if (power==1) return mat;
    if (power%2==1) return Mat_Mul(mat,Mat_Expo(mat,power-1,mod),mod);
    matrix ret = Mat_Expo(mat,power/2,mod);
    return Mat_Mul(ret,ret,mod);
}

int main ()
{
    ll cases,caseno=0,Q,M,N;
    ll a1,b1,c1,a2,b2,c2;
    ll f[5],g[5];
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld%lld%lld",&a1,&b1,&c1);
        scanf("%lld%lld%lld",&a2,&b2,&c2);
        scanf("%lld%lld%lld",&f[0],&f[1],&f[2]);
        scanf("%lld%lld%lld",&g[0],&g[1],&g[2]);
        scanf("%lld",&M);
        scanf("%lld",&Q);

        matrix arr;
        arr.row = 6,arr.column = 6;
        arr.mat[0][0] = a1,arr.mat[0][1] = b1,arr.mat[0][2] = 0;arr.mat[0][3] = 0,arr.mat[0][4] = 0,arr.mat[0][5] = c1;
        arr.mat[1][0] = 1,arr.mat[1][1] = 0,arr.mat[1][2] = 0;arr.mat[1][3] = 0,arr.mat[1][4] = 0,arr.mat[1][5] = 0;
        arr.mat[2][0] = 0,arr.mat[2][1] = 1,arr.mat[2][2] = 0;arr.mat[2][3] = 0,arr.mat[2][4] = 0,arr.mat[2][5] = 0;
        arr.mat[3][0] = 0,arr.mat[3][1] = 0,arr.mat[3][2] = c2;arr.mat[3][3] = a2,arr.mat[3][4] = b2,arr.mat[3][5] = 0;
        arr.mat[4][0] = 0,arr.mat[4][1] = 0,arr.mat[4][2] = 0;arr.mat[4][3] = 1,arr.mat[4][4] = 0,arr.mat[4][5] = 0;
        arr.mat[5][0] = 0,arr.mat[5][1] = 0,arr.mat[5][2] = 0;arr.mat[5][3] = 0,arr.mat[5][4] = 1,arr.mat[5][5] = 0;


        printf("Case %lld:\n",++caseno);
        for (ll i=0;i<Q;i++)
        {
            scanf("%lld",&N);
            ll ff,gg;
            if (N==0)
                ff = f[0],gg = g[0];
            else if (N==1)
                ff = f[1],gg = g[1];
            else if (N==2)
                ff = f[2],gg = g[2];
            else
            {
                matrix ret = Mat_Expo(arr,N-2,M);
                ff = 0,gg = 0;
                for (ll i=0;i<3;i++)
                {
                    ff+=ret.mat[0][i]*f[2-i];
                    gg+=ret.mat[3][i]*f[2-i];
                }
                for (ll i=3;i<6;i++)
                {
                    ff+=ret.mat[0][i]*g[5-i];
                    gg+=ret.mat[3][i]*g[5-i];
                }
            }
            printf("%lld %lld\n",ff%M,gg%M);
        }
    }
    return 0;
}
