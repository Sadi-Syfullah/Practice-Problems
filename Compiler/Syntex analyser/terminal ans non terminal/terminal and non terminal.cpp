#include<bits/stdc++.h>
using namespace std;
map<string,bool>check_T;
map<string,bool>check_nT;
vector<string>terminal;
vector<string>nonterminal;
void is_terminal(string ss)
{
    if(ss.size()>0)
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
    int i,j,a,n=0;;
    string s,c,s1;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
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
            if(isupper(s[0])){
                is_terminal(c);
                c.clear();
                c=s[0];
                s.erase(s.begin());
                is_nonterminal(c);
                c.clear();
            }

            else if(s[0]=='|' or s[0]=='+'){
                is_terminal(c);
                c.clear();
                if(s[0]=='|') n++;
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
    cout<<"Number of transition : "<<n<<endl;
    cout<<"Terminals : "<<endl;
    for(i=0;i<terminal.size();i++)
    {
        cout<<"    "<<terminal[i]<<endl;
    }
    cout<<"Nonterminals : "<<endl;
    for(i=0;i<nonterminal.size();i++)
    {
        cout<<"    "<<nonterminal[i]<<endl;
    }
    return 0;
}
