#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll  N, X, M, Y, K;
struct matrix{
    ll mat[3][3];
    ///ll row,column;
}arr[5];

void sett()
{
    arr[0].mat[0][0] = arr[1].mat[0][0] = arr[2].mat[0][0] = 0;
    arr[0].mat[0][1] = arr[1].mat[0][1] = arr[2].mat[0][1] = 1;
    arr[0].mat[1][0] = arr[1].mat[1][0] = arr[2].mat[1][0] = 1;
    arr[0].mat[1][1] = arr[1].mat[1][1] = arr[2].mat[1][1] = 1;
}

matrix Mat_Mul(matrix A,matrix B)
{
    matrix C;
    for (ll i=0;i<2;i++)
    {
        for (ll j=0;j<2;j++)
        {
            C.mat[i][j] = 0;
            for (ll k=0;k<2;k++)
                C.mat[i][j]+=(A.mat[i][k]*B.mat[k][j]);
            C.mat[i][j]%=mod;
        }
    }
    return C;
}

matrix Mat_Expo(matrix MaT,ll power)
{
    if (power==1) return MaT;
    if (power%2==1)
        return Mat_Mul(MaT,Mat_Expo(MaT,power-1));
    matrix ret = Mat_Expo(MaT,power/2);
    return Mat_Mul(ret,ret);
}

int main ()
{
    ll cases,caseno=0,c,d,cc,dd,a0,b0,hor;
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    scanf("%lld",&cases);
    while(cases--)
    {
        sett();
        scanf("%lld%lld%lld%lld%lld",&N,&X,&M,&Y,&K);
        matrix ret1 = Mat_Expo(arr[0],N);
        matrix ret2 = Mat_Expo(arr[1],M);
        c = ret1.mat[1][0],d = ret1.mat[1][1];
        cc = ret2.mat[1][0],dd = ret2.mat[1][1];
        hor = c*dd-d*cc;
        printf("Case %lld: ",++caseno);
        if (hor==0)
        {
            printf("Impossible\n");
            continue;
        }
        a0 = (X*dd-Y*d)/hor;
        b0 = (c*Y-X*cc)/hor;
        if (a0<0 || b0<0 || (X*dd-Y*d)%hor!=0 || (c*Y-X*cc)%hor!=0)
        {
            printf("Impossible\n");
            continue;
        }
        matrix ret = Mat_Expo(arr[2],K);
        printf("%lld\n",(ret.mat[1][0]*a0+ret.mat[1][1]*b0)%mod);
    }
    return 0;
}
