#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int a[5],T,t;
    cin>>T;
    for (t=1;t<=T;t++)
    {
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        cout<<"Case "<<t<<": ";
        if (a[0]*a[0]+a[1]*a[1]==a[2]*a[2] || a[0]*a[0]==a[1]*a[1]+a[2]*a[2] || a[1]*a[1]==a[1]*a[1]+a[2]*a[2])
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
