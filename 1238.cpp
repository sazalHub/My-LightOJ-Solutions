#include<bits/stdc++.h>
#define ll int
using namespace std;
ll fx[] = {0,0,1,-1};
ll fy[] = {-1,1,0,0};
ll N,M,level[21][21],tx,ty;
char graph[21][21];
bool vis[21][21];

struct chess{
    ll x,y;
    chess(){}
    chess(ll r,ll c){x=r,y=c;}
}pos;

bool valid(ll x,ll y)
{
    if (x>=0&&x<N&&y>=0&&y<M) return true;
    return false;
}

ll BFS(ll r,ll c)
{
    queue<chess>Q;
    memset(vis,false,sizeof(vis));
    memset(level,0,sizeof(level));
    vis[r][c] = true;
    Q.push(chess(r,c));

    while(!Q.empty())
    {
        pos = Q.front();
        Q.pop();
        for (ll i=0;i<4;i++)
        {
            tx = pos.x+fx[i];
            ty = pos.y+fy[i];
            if (valid(tx,ty)&&!vis[tx][ty]&&graph[tx][ty]!='m'&&graph[tx][ty]!='#')
            {
                vis[tx][ty] = true;
                level[tx][ty] = level[pos.x][pos.y] + 1;
                if (graph[tx][ty]=='h') return level[tx][ty];
                Q.push(chess(tx,ty));
            }
        }
    }
}

int main ()
{
    ll cases,caseno=0,ans;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%d",&N,&M);
        for (ll i=0;i<N;i++)
            scanf("%s",graph[i]);
        ans = -1;
        for (ll i=0;i<N;i++)
        {
            for (ll j=0;j<M;j++)
            {
                if (graph[i][j]=='a'||graph[i][j]=='b'||graph[i][j]=='c')
                    ans = max(ans,BFS(i,j));
            }
        }
        printf("Case %d: %d\n",++caseno,ans);
    }
    return 0;
}
