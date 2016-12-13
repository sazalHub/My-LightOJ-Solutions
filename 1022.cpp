#include<bits/stdc++.h>
using namespace std;
double pi=2*acos(0.0);
int main ()
{
    int T,t;
    double r,R,area;
    cin>>T;
    for (t=0;t<T;t++)
    {
        cin>>r;
        R=2.0*r;
        area=R*R-pi*r*r;
        cout<<"Case "<<t+1<<": ";
        cout<<fixed<<setprecision(2)<<area<<endl;
    }
    return 0;
}

