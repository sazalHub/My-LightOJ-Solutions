#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long int n;
    int T,t,c,r;
    cin>>T;
    for (t=1;t<=T;t++)
    {
        cin>>n;
        c=0;
        while(n!=0)
        {
            r=n%2;
            n=n/2;
            if (r==1)
                c++;
        }
        if (c%2==0)
            cout<<"Case "<<t<<": "<<"even"<<endl;
        else
            cout<<"Case "<<t<<": "<<"odd"<<endl;
    }
    return 0;
}


