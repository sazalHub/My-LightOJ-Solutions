#include<bits/stdc++.h>
#define ll long long
using namespace std;
string lft,rgt,mid;
char str[100005];
ll len;

bool make(char str[100005])
{
    lft = "",rgt = "",mid="";
    ll md = len/2;
    ll cnt = 0;
    if (len%2==1)
    {
        if (str[md]=='9')
            cnt++;
        mid+=str[md];
    }
    for (ll i=0;i<md;i++)
    {
        if (str[i]=='9')
            cnt++;
        if (str[len-i-1]=='9')
            cnt++;
        lft+=str[i];
        rgt+=str[len-i-1];
    }
    ///cout<<lft<<" "<<mid<<" "<<rgt<<endl;
    if (cnt==len)
        return true;
    return false;
    ///cout<<lft<<" "<<mid<<" "<<rgt<<endl;
}

void make_next_palindrome()
{
    ll md = len/2,tmp;
    string man = str;
    for (ll i=0;i<md;i++)
    {
        if (lft[i]!=rgt[i])
            rgt[i]=lft[i];
    }
    string temp = rgt;
    reverse(temp.begin(),temp.end());
    string ans = lft+mid+temp;
    ///cout<<man<<endl;
    if (ans<=man)
    {
        ///cout<<ans<<endl;
        ans="";
        ll carry = 0;
        if (len%2==1)
        {
            ///cout<<1<<endl;
            tmp = mid[0]-48;
            tmp+=1;
            mid[0]=tmp%10+48;
            carry = tmp/10;
            for (ll i=md-1;i>=0;i--)
            {
                tmp = (lft[i] - 48) + carry;
                ans+=(tmp%10+48);
                lft[i] = tmp%10;
                carry = tmp/10;
            }
            if (carry!=0)
                ans+=(carry+48);
        }
        else
        {
            ans = "";
            carry = 1;
            for (ll i=md-1;i>=0;i--)
            {
                tmp = (lft[i] - 48) + carry;
                ans+=(tmp%10+48);
                lft[i] = tmp%10;
                carry = tmp/10;
            }
            if (carry!=0)
                ans+=(carry+48);
        }
        temp = ans;
        reverse(ans.begin(),ans.end());
        ans = ans + mid + temp;
    }
    printf("%s\n",ans.c_str());
}

int main ()
{
    ll cases,caseno=0;
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    scanf("%lld",&cases);
    getchar();
    while(cases--)
    {
        scanf("%s",&str);
        len = strlen(str);
        bool fl = make(str);
        printf("Case %lld: ",++caseno);
        if (fl)
        {
            ///cout<<1<<endl;
            string ans = "1";
            for (ll i=0;i<len-1;i++)
                ans+="0";
            ans+="1";
            printf("%s\n",ans.c_str());
        }
        else
            make_next_palindrome();
    }
    return 0;
}
