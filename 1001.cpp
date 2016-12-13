#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int a,b,c,T;
    cin>>T;
    while(T)
    {
        cin>>a;
        if (a<=10)
        {
            b=0;
            c=a;
        }
        else
        {
            b=a/2;
            c=a-b;
        }
        cout<<b<<' '<<c<<endl;
        T--;
    }
    return 0;
}
