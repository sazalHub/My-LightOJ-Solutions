#include<bits/stdc++.h>
#define ll int
#define MAX 99999
using namespace std;
ll N,M,level[11][11],level1[11][11],cnt[11][11],tx,ty,add;
ll fx[] = {1,1,2,2,-1,-1,-2,-2};
ll fy[] = {2,-2,1,-1,2,-2,1,-1};
char graph[11][11];
bool vis[11][11];

struct chess{
    ll x,y;
    chess(){}
    chess(ll r,ll c)
    {
        x = r,y = c;
    }
}pos;

bool valid(ll x,ll y)
{
    if (x>=0&&x<N&&y>=0&&y<M) return true;
    return false;
}

void BFS(ll r,ll c,ll d)
{
    memset(level,0,sizeof(level));
    memset(vis,false,sizeof(vis));
    queue<chess>Q;
    vis[r][c] = true;
    cnt[r][c]++;
    Q.push(chess(r,c));
    while(!Q.empty())
    {
        pos = Q.front();
        Q.pop();
        for (ll i=0;i<8;i++)
        {
            tx = pos.x + fx[i];
            ty = pos.y + fy[i];
            if (!vis[tx][ty]&&valid(tx,ty))
            {
                level[tx][ty] = level[pos.x][pos.y] + 1;
                vis[tx][ty] = true;
                Q.push(chess(tx,ty));
                add = level[tx][ty]/d;
                if (level[tx][ty]%d!=0)
                    add++;
                level1[tx][ty]+=add;
                cnt[tx][ty]++;
            }
        }
    }
}

int main ()
{
    ll cases,caseno=0,knight;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%d",&N,&M);
        for (ll i=0;i<N;i++)
            scanf("%s",&graph[i]);

        memset(level1,0,sizeof(level1));
        memset(cnt,0,sizeof(cnt));
        knight = 0;
        for (ll i=0;i<N;i++)
        {
            for (ll j=0;j<M;j++)
            {
                if (graph[i][j]>='1'&&graph[i][j]<='9')
                    BFS(i,j,graph[i][j]-48),knight++;
            }
        }

        ll ans = MAX;
        for (ll i=0;i<N;i++)
        {
            for (ll j=0;j<M;j++)
            {
                if (cnt[i][j]==knight)
                    ans = min(ans,level1[i][j]);
            }
        }
        if (ans==MAX) ans = -1;

        printf("Case %d: %d\n",++caseno,ans);

    }
    return 0;
}
