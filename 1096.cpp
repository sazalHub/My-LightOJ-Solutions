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

    for(int i=0; i<C.row; i++){
        for(int j=0; j<C.column; j++){
            ll sum = 0;
            for(int k=0; k<A.column; k++){
                sum = sum + A.mat[i][k] * B.mat[k][j];
                sum = (sum%mod+mod)%mod;
            }
            C.mat[i][j] = sum;
        }
    }
    return C;
}

matrix Mat_Expo(matrix Mat,ll power,ll mod)
{
    if (power==1) return Mat;
    else if (power%2==1)
        return Mat_Mul(Mat,Mat_Expo(Mat,power-1,mod),mod);
    matrix ret = Mat_Expo(Mat,power/2,mod);
    return Mat_Mul(ret,ret,mod);
}

int main ()
{
    matrix arr,arr1;
    arr.row=4;
    arr.column=4;
    arr.mat[0][0]=0,arr.mat[0][1]=0,arr.mat[0][2]=0,arr.mat[0][3]=0;
    arr.mat[1][0]=1,arr.mat[1][1]=0,arr.mat[1][2]=0,arr.mat[1][3]=0;
    arr.mat[2][0]=0,arr.mat[2][1]=1;arr.mat[2][2]=0,arr.mat[2][3]=0;
    arr.mat[3][0]=0,arr.mat[3][1]=0;arr.mat[3][2]=0,arr.mat[3][3]=1;

    ll cases,caseno=0,n,a,b,c;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
        if (n<=2)
        {
            printf("Case %lld: %lld\n",++caseno,0);
            continue;
        }
        arr.mat[0][0]=a,arr.mat[0][2]=b,arr.mat[0][3] = 1;
        matrix ret = Mat_Expo(arr,n-2,10007);
        ll ans = (ret.mat[0][3]%10007*c%10007)%10007;
        printf("Case %lld: %lld\n",++caseno,ans%10007);
    }
    return 0;
}

