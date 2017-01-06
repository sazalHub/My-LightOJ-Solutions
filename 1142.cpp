#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll N,K;

struct matrics {
    ll CC[31][31];
    ll CCr,CCc;
};

struct matrix {
    matrics mat[5];
    ll Cr,Cc;
};

void reset (matrix &arr)
{
    arr.Cr = N;
    arr.Cc = N;
    arr.mat[0].CCr = N;
    arr.mat[0].CCc = N;
    arr.mat[1].CCr = N;
    arr.mat[1].CCc = N;
    for (ll i=1;i<=N;i++)
    {
        for (ll j=1;j<=N;j++)
        {
            scanf("%lld",&arr.mat[0].CC[i][j]);
            arr.mat[1].CC[i][j] = arr.mat[0].CC[i][j];
        }
    }
    arr.mat[2].CCr = N;
    arr.mat[2].CCc = N;
    for (ll i=1;i<=N;i++)
        for (ll j=1;j<=N;j++)
            arr.mat[2].CC[i][j]=0;
    arr.mat[3].CCr = N;
    arr.mat[3].CCc = N;
    for (ll i=1;i<=N;i++)
    {
        for (ll j=1;j<=N;j++)
        {
            if (i==j)
                arr.mat[3].CC[i][j] = 1;
            else
                arr.mat[3].CC[i][j] = 0;
        }
    }
}

matrics Mat_Mul1(matrics a,matrics b)
{
    matrics c;
    c.CCr = c.CCc = N;
    for (ll i=1;i<=N;i++)
    {
        for (ll j=1;j<=N;j++)
        {
            c.CC[i][j] = 0;
            for (ll k=1;k<=N;k++)
            {
                c.CC[i][j]+=a.CC[i][k]*b.CC[k][j];
            }
            c.CC[i][j]%=10;
        }
    }
    return c;
}

matrics Mat_Sum(matrics a,matrics b)
{
    matrics c;
    c.CCr = c.CCc = N;
    ll i,j;
    for (i=1;i<=N;i++)
    {
        for (j=1;j<=N;j++)
        {
            c.CC[i][j] = a.CC[i][j] + b.CC[i][j];
        }
        c.CC[i][j]%=10;
    }
    return c;
}

matrix Mat_Mul(matrix A,matrix B)
{
    matrix temp;
    temp.Cr = temp.Cc = N;
    temp.mat[0].CCr = temp.mat[0].CCc = N;
    temp.mat[1].CCr = temp.mat[1].CCc = N;
    temp.mat[2].CCr = temp.mat[2].CCc = N;
    temp.mat[3].CCr = temp.mat[3].CCc = N;

    temp.mat[0] = Mat_Mul1(A.mat[0],B.mat[0]);
    temp.mat[1] = Mat_Sum(Mat_Mul1(A.mat[0],B.mat[1]),Mat_Mul1(A.mat[1],B.mat[3]));
    temp.mat[2] = A.mat[2];
    temp.mat[3] = A.mat[3];

    return temp;
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
    ll cases,caseno = 0;
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld%lld",&N,&K);
        matrix arr;
        reset(arr);
        matrix ret = Mat_Expo(arr,K);
        printf("Case %lld:\n",++caseno);
        for (ll i=1;i<=N;i++)
        {
            for (ll j=1;j<=N;j++)
            {
                printf("%lld",ret.mat[1].CC[i][j]%10);
            }
            printf("\n");
        }
    }
    return 0;
}
