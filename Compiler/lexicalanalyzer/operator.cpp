#include<bits/stdc++.h>
using namespace std;
string op="+-/%^&*<>^!=";
int main()
{
    int i,j,n;
    string s;
    freopen("input4.txt","r",stdin);
    freopen("output4.txt","w",stdout);
    while(cin>>s)
    {
        while(s.empty()==false)
        {
            while(1)
            {
                if(s.empty()==true)break;
                for(i=0;i<op.size();i++)
                {
                    if(s[0]==op[i])break;
                }
                if(i<op.size())break;
                s.erase(s.begin());
            }
            if(s.empty())continue;
            cout<<s[0];
            s.erase(s.begin());
            for(i=0;i<op.size();i++)
            {
                if(op[i]==s[0])
                {
                    cout<<s[0];s.erase(s.begin());

                }
            }
            cout<<endl;
        }

    }
    return 0;
}

