#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[105][105],len;
char A[105],B[105];
string Ans[110][110];

ll LCS(ll i,ll j)
{
    ll len1 = strlen(A),len2 = strlen(B);
    for (int i=1;i<=len1;i++)
    {
        for (int j=1;j<=len2;j++)
        {
            if (A[i-1]==B[j-1]) dp[i][j] = 1 + dp[i-1][j-1],Ans[i][j] = Ans[i-1][j-1]+A[i-1];
            else if (dp[i-1][j]>dp[i][j-1]) dp[i][j] = dp[i-1][j],Ans[i][j] = Ans[i-1][j];
            else if (dp[i-1][j]<dp[i][j-1]) dp[i][j] = dp[i][j-1],Ans[i][j] = Ans[i][j-1];
            else dp[i][j] = dp[i-1][j],Ans[i][j] = min(Ans[i-1][j],Ans[i][j-1]);
        }
    }
    return dp[len1][len2];
}

int main ()
{
    ll cases,caseno=0;
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    scanf("%lld",&cases);
    getchar();
    while(cases--)
    {
        getchar();
        scanf("%s",&A);
        getchar();
        scanf("%s",&B);
        ///printf("%s %s\n",A,B);
        memset(dp,0,sizeof(dp));
        ll length = LCS(0,0);
        ///cout<<length<<endl;
        printf("Case %lld: ",++caseno);
        if (length==0)
            printf(":(\n");
        else
            printf("%s\n",Ans[strlen(A)][strlen(B)].c_str());
        getchar();
    }
    return 0;
}
