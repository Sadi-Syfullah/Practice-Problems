#include<bits/stdc++.h>
using namespace std;
string single_op="+-*&^<>=~/%";
int main()
{
    int i,j,k,a,b,c;
    string s;
    char ch;
    freopen("speinput.txt","r",stdin);
    freopen("speoutput.txt","w",stdout);
    while(cin>>s)
    {
        if(ispunct(ch))
        {
            for(i=0;i<single_op.size();i++)
            if(ch==single_op[i])break;
            if(i>=single_op.size())
            cout<<ch<<endl;
        }
    }
    return 0;
}
