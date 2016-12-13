#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long T,t,n,i,sum,a;
    cin>>T;
    for (t=1;t<=T;t++)
    {
        cin>>n;
        sum=0;
        for (i=0;i<n;i++)
        {
            cin>>a;
            if (a>0)
               sum=sum+a;
        }
        cout<<"Case "<<t<<':'<<' '<<sum<<endl;
    }
    return 0;
}

