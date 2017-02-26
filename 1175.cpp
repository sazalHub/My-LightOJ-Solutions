#include<bits/stdc++.h>
#define ll int
using namespace std;
ll fx[] = {0,0,1,-1};
ll fy[] = {1,-1,0,0};
char graph[205][205];
ll levelf[205][205],levelj[205][205],R,C,tx,ty;
bool vis1[205][205],vis2[205][205],fire[205][205];

struct cord{
    ll x,y;
    cord(){}
    cord(ll a,ll b){x = a,y = b;}
}xy;

bool valid(ll a,ll b)
{
    if (a>=0&&a<R&&b>=0&&b<C) return true;
    return false;
}

ll BFS1(ll r,ll c)
{
   queue<cord>Q;
   levelf[r][c] = 0;
   vis1[r][c] = true;
   fire[r][c] = true;
   Q.push(cord(r,c));
   while(!Q.empty())
   {
       xy = Q.front();
       Q.pop();
       for (ll i=0;i<4;i++)
       {
           tx = xy.x+fx[i];
           ty = xy.y+fy[i];
           if (valid(tx,ty)&&graph[tx][ty]!='#')
           {
               if (!vis1[tx][ty])
               {
                   levelf[tx][ty] = 1 + levelf[xy.x][xy.y];
                   vis1[tx][ty] = true;
                   Q.push(cord(tx,ty));
               }
               else if (levelf[tx][ty]>1+levelf[xy.x][xy.y])
               {
                   levelf[tx][ty] = 1 + levelf[xy.x][xy.y];
                   vis1[tx][ty] = true;
                   Q.push(cord(tx,ty));
               }
               fire[tx][ty] = true;
           }
       }
   }
}

ll BFS(ll r,ll c)
{
    queue<cord>Q;
    levelj[r][c] = 0;
    vis2[r][c] = true;
    Q.push(cord(r,c));
    while(!Q.empty())
    {
        xy = Q.front();
        if (xy.x==R-1||xy.y==C-1||xy.x==0||xy.y==0)
            return levelj[tx][ty]+1;
        Q.pop();
        for (ll i=0;i<4;i++)
        {
            tx = xy.x+fx[i];
            ty = xy.y+fy[i];
            if (valid(tx,ty)&&graph[tx][ty]!='#')
            {
                if (!vis2[tx][ty])
                {
                    if (fire[tx][ty])
                    {
                        if (1+levelj[xy.x][xy.y]<levelf[tx][ty])
                        {
                            levelj[tx][ty] = 1 + levelj[xy.x][xy.y];
                            vis2[tx][ty] = true;
                            Q.push(cord(tx,ty));
                            if (tx==R-1||ty==C-1||tx==0||ty==0)
                                return levelj[tx][ty]+1;
                        }
                    }
                    else
                    {
                        levelj[tx][ty] = 1 + levelj[xy.x][xy.y];
                        vis2[tx][ty] = true;
                        Q.push(cord(tx,ty));
                        if (tx==R-1||ty==C-1||tx==0||ty==0)
                            return levelj[tx][ty]+1;
                    }
                }
           }
       }
    }
    return -1;
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,ans,caseno=0,xx,yy;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%d",&R,&C);

        for (ll i=0;i<R;i++) scanf("%s",&graph[i]);

        for (ll i=0;i<R+3;i++)
        {
            for (ll j=0;j<C+3;j++)
            {
                levelf[i][j] = levelj[i][j] = 0;
                fire[i][j] = vis1[i][j] = vis2[i][j] = false;
            }
        }

        for (ll i=0;i<R;i++)
        {
            for (ll j=0;j<C;j++)
            {
                if (graph[i][j]=='F')
                    BFS1(i,j);
                else if (graph[i][j]=='J')
                    xx = i,yy = j;
            }
        }

        ans = BFS(xx,yy);

        printf("Case %d: ",++caseno);
        if (ans!=-1)
            printf("%d\n",ans);
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
