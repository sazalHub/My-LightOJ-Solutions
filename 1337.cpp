#include<bits/stdc++.h>
#define ll long long
using namespace std;

char graph[505][505];
ll crystal[505][505];
ll fx[] = {1,-1,0,0};
ll fy[] = {0,0,1,-1};
ll N,M,P,tx,ty;

struct cord{
    ll x,y;
    cord(){}
    cord(ll a,ll b){x=a,y=b;}
}xy;

bool valid(ll x,ll y)
{
    if (x>=0&&x<N&&y>=0&&y<M)
        return true;
    return false;
}

void BFS(ll r,ll c)
{
    ll cnt=0;
    bool vis[505][505]={{false}};
    queue<cord>Q;
    vis[r][c] = true;
    Q.push(cord(r,c));

    while(!Q.empty())
    {
        xy = Q.front();
        Q.pop();
        for (ll i=0;i<4;i++)
        {
            tx = xy.x+fx[i];
            ty = xy.y+fy[i];
            if (valid(tx,ty)&&!vis[tx][ty]&&graph[tx][ty]!='#')
            {
                vis[tx][ty] = true;
                Q.push(cord(tx,ty));
                if (graph[tx][ty]=='C')
                    cnt++;
            }
        }
    }
    for (ll i=0;i<N;i++)
        for (ll j=0;j<M;j++)
            if (vis[i][j])
                crystal[i][j] = cnt;
    printf("%lld\n",cnt);
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,caseno=0,x,y;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld%lld%lld",&N,&M,&P);
        for (ll i=0;i<N;i++)
            scanf("%s",&graph[i]);
        printf("Case %lld:\n",++caseno);

        for (ll i=0;i<=N;i++)
            for (ll j=0;j<=M;j++)
                crystal[i][j] = -1;

        for (ll i=0;i<P;i++)
        {
            scanf("%lld%lld",&x,&y);
            x--,y--;
            if (crystal[x][y]!=-1)
                printf("%lld\n",crystal[x][y]);
            else
                BFS(x,y);
        }
    }
    return 0;
}
