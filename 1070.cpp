#include<bits/stdc++.h>
#define ll long long unsigned
using namespace std;

struct matrix{
    ll row,column;
    ll mat[5][5];
};

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
                C.mat[i][j] = C.mat[i][j] + A.mat[i][k] * B.mat[k][j];
            }
        }
    }
    return C;
}

matrix Mat_Expo(matrix mat,ll power)
{
    if (power==1) return mat;
    if (power%2==1) return Mat_Mul(mat,Mat_Expo(mat,power-1));
    matrix ret = Mat_Expo(mat,power/2);
    return Mat_Mul(ret,ret);
}

int main ()
{
    ll cases,caseno=0,p,q,n;
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%llu%llu%llu",&p,&q,&n);
        if (n==0)
        {
            printf("Case %llu: 2\n",++caseno);
            continue;
        }
        if (n==1)
        {
            printf("Case %llu: %llu\n",++caseno,p);
            continue;
        }
        matrix arr;
        arr.row = 2,arr.column = 2;
        arr.mat[0][0] = p,arr.mat[0][1] = -q;
        arr.mat[1][0] = 1,arr.mat[1][1] = 0;
        matrix ret = Mat_Expo(arr,n-1);
        ll ans = ret.mat[0][0]*p + ret.mat[0][1]*2;
        printf("Case %llu: %llu\n",++caseno,ans);
    }
    return 0;
}
