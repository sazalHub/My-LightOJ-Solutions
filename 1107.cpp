#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int T,t,x1,y1,x2,y2,x,y,x3,y3,x4,y4,M,i;
    cin>>T;
    for (t=1;t<=T;t++)
    {
        cin>>x1>>y1>>x2>>y2;
        x3=x1;
        y3=y2;
        x4=x2;
        y4=y1;
        cin>>M;
        cout<<"Case "<<t<<':'<<endl;
        for (i=0;i<M;i++)
        {
            cin>>x>>y;
            if (x>=x1 && x<=x4 && y>=y1 && y<=y3 && y>=y4 && y<=y2)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
    return 0;
}

