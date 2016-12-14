#include<bits/stdc++.h>
using namespace std;
int data[105],temp[105],n;
void rev()
{
    int i,j;
    for (i=n-1,j=0;i>=0,j<n;i--,j++)
    {
        temp[j]=data[i];
    }
    for (i=0;i<n;i++)
        data[i]=temp[i];
}
void add(int d)
{
    for (int i=0;i<n;i++)
        data[i]+=d;
}
void multi(int d)
{
    for (int i=0;i<n;i++)
        data[i]*=d;
}
void div(int d)
{
    for (int i=0;i<n;i++)
        data[i]/=d;
}
int main ()
{
    int T,m,t,j,tmp,tm;
    char ch;
    cin>>T;
    for (t=1;t<=T;t++)
    {
        cin>>n>>m;
        for (j=0;j<n;j++)
            cin>>data[j];
        for (j=0;j<m;j++)
        {
            cin>>ch;
            getchar();
            if (ch=='S')
            {
                cin>>tmp;
                add(tmp);
            }
            else if (ch=='M')
            {
                cin>>tmp;
                multi(tmp);
            }
            else if (ch=='D')
            {
                cin>>tmp;
                div(tmp);
            }
            else if (ch=='R')
                rev();
            else if (ch=='P')
            {
                cin>>tmp>>tm;
                swap(data[tmp],data[tm]);
            }
        }
        cout<<"Case "<<t<<":"<<endl;
        for (j=0;j<n;j++)
        {
            cout<<data[j];
            if (j<n-1)
                cout<<' ';
        }
        cout<<endl;
    }
    return 0;
}
