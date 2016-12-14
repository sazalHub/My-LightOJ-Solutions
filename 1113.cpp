#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int test,t=1;
    cin>>test;
    while(t<=test)
    {
        stack<string>f,b;
        string temp;
        string c_page;
        c_page="http://www.lightoj.com/";
        b.push(c_page);
        cout<<"Case "<<t<<':'<<endl;
        while(cin>>temp)
        {
            if (temp=="QUIT")
                break;
            else if (temp=="VISIT")
            {
                cin>>c_page;
                b.push(c_page);
                while(!f.empty())
                    f.pop();
                cout<<c_page<<endl;
            }
            else if (temp=="BACK")
            {
                if (b.size()==1||b.empty())
                {
                    cout<<"Ignored"<<endl;
                }
                else
                {
                    c_page=b.top();
                    f.push(c_page);
                    b.pop();
                    c_page=b.top();
                    cout<<c_page<<endl;
                }
            }
            else if (temp=="FORWARD")
            {
                if (f.empty())
                {
                    cout<<"Ignored"<<endl;
                }
                else
                {
                    c_page=f.top();
                    b.push(c_page);
                    f.pop();
                    cout<<c_page<<endl;
                }
            }
        }
        t++;
    }
    return 0;
}

