#include<bits/stdc++.h>
using namespace std;

map<string,bool>check_T;
map<string,bool>check_nT;
vector<string>terminal;
vector<string>nonterminal;
void is_terminal(string ss)
{
    if(ss.empty()==false)
    {
        if(check_T[ss]==false)
        {
            terminal.push_back(ss);
            check_T[ss]=true;
        }
    }
}
void is_nonterminal(string ss)
{
    if(check_nT[ss]==false)
    {
        nonterminal.push_back(ss);
        check_nT[ss]=true;
    }
}
int main()
{
    int i,j,a,n=0;
    string s,c,ss;
    freopen("nonterminalterminalinput.txt","r",stdin);
    freopen("nonterminalterminaloutput.txt","w",stdout);
    while(cin>>s)
    {
        n++;
        c=s[0];
        is_nonterminal(c);
        s.erase(s.begin(),s.begin()+3);
        j=0;
        c.clear();
        while(s.empty()==false)
        {
            if(isupper(s[0]))
            {
                is_terminal(c);
                c.clear();
                c=s[0];
                s.erase(s.begin());
                is_nonterminal(c);
                c.clear();
            }
            else if(s[0]=='|' or s[0]=='+' || s[0]=='-' || s[0]=='*')
            {
                is_terminal(c);
                c.clear();
                c=s[0];
                if(s[0]=='|') n++;
                else is_terminal(c);
                c.clear();
                s.erase(s.begin());
            }
            else
            {
                c+=s[0];
                s.erase(s.begin());

            }
        }
        is_terminal(c);

    }
    cout<<"number of transition:"<<n<<endl;
    cout<<"terminals:"<<endl;
    for(i=0;i<terminal.size();i++)
       cout<<terminal[i]<<endl;
    cout<<"nonterminal:"<<endl;
    for(i=0;i<nonterminal.size();i++)
    cout<<nonterminal[i]<<endl;
    return 0;
}
