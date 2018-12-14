#include<bits/stdc++.h>
using namespace std;
string key[33]={"int","main","float","for","while"};
int main()
{
    int i,j,a,b;
    string s,c;
    char ch;
    freopen("lexicalkeywordinput.txt","r",stdin);
    freopen("lexicalkeywordoutput.txt","w",stdout);
    while(cin>>s)
    {
        c.clear();j=0;
        for(i=0;i<s.size();i++)
        {
            if(isalpha(s[i]))
                j++;
            else
                break;

        }
        c=s.substr(0,j);
        for(i=0;i<32;i++)
        {
            if(c==key[i])break;

        }
        if(i<32)
        {
            cout<<c<<endl;
        }
    }
    return 0;
}
