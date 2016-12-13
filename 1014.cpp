#include<bits/stdc++.h>
using namespace std;
#define Max 1000005

int main ()
{
    long T,t,L,P,i,temp,d,j;
    long div[Max];
    cin>>T;
    for (t=1;t<=T;t++)
    {
        cin>>P>>L;
        temp=P-L;
        cout<<"Case "<<t<<':';
        if (temp<=L)
            cout<<' '<<"impossible"<<endl;
        else
        {
            j=0;
            for (i=1;i<=sqrt(temp);i++)
            {
                if (temp%i==0)
                {
                    d=temp/i;
                    if (d>L)
                    {
                        div[j++]=d;
                    }
                    if (i>L&&d!=i)
                    {
                        div[j++]=i;
                    }
                }
            }
            sort(div,div+j);
            for (i=0;i<j;i++)
                cout<<' '<<div[i];
            cout<<endl;
        }
    }
    return 0;
}

