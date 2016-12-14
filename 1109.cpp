#include<bits/stdc++.h>
using namespace std;
struct node
{
    int num;
    int div;
}temp[1005];

void div_gen()
{
    int i,c,j,tmp;
    temp[1].num=1;
    temp[1].div=1;
    for (i=2;i<=1000;i++)
    {
        c=0;
        for (j=2;j<=i/2;j++)
        {
            if (i%j==0)
                c++;
        }
        c+=2;
        temp[i].num=i;
        temp[i].div=c;
    }
    for (i=1;i<=1000;i++)
    {
        for (j=i+1;j<=1000;j++)
        {
            if (temp[i].div>temp[j].div)
                swap(temp[i],temp[j]);
            else if (temp[i].div==temp[j].div)
            {
                if (temp[i].num<temp[j].num)
                    swap(temp[i],temp[j]);
            }
        }
    }
}
int main ()
{
    div_gen();
    int n,T,t=1;
    cin>>T;
    while(T)
    {
        cin>>n;
        cout<<"Case "<<t++<<": "<<temp[n].num<<endl;
        T--;
    }
    return 0;
}
