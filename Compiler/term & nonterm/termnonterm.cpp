#include<bits/stdc++.h>
using namespace std;
map<string,bool>check_t;
map<string,bool>check_nt;
vector<string>term;
vector<string>nonterm;

void is_term(string ss)
{
    if(ss.empty()==false)
    {
        if(check_t[ss]==false)
        {
            term.push_back(ss);
            check_t[ss]=true;
        }
    }
}

void is_nonterm(string ss)
{
    if(check_nt[ss]==false)
    {
        nonterm.push_back(ss);
        check_nt[ss]=true;
    }
}

int main()
{
    int i,n=0;
    string s,c;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(cin>>s)
    {
        n++;
        c=s[0];
        is_nonterm(c);

        s.erase(s.begin(),s.begin()+3);
        c.clear();
        while(s.empty()==false)
        {

          if(isupper(s[0]))
          {
              is_term(c);
              c.clear();
              c=s[0];
              s.erase(s.begin());
              is_nonterm(c);
              c.clear();
          }
          else if(s[0]=='|'||s[0]=='+'||s[0]=='*'||s[0]=='-')
          {
              is_term(c);
              c.clear();
              c=s[0];
              if(s[0]=='|')
                n++;
                else

                {


                    is_term(c);
                    c.clear();
                    s.erase(s.begin());
                }

          }
          else

            {

              c+=s[0];
              s.erase(s.begin());
            }




        }

        is_term(c);
    }

    cout<<"number of transition: "<<n<<endl;

    cout<<" terminal: "<<endl;
    for(i=0;i<term.size();i++)


        cout<<term[i]<<endl;

    cout<<" nonterminal: "<<endl;
    for(i=0;i<nonterm.size();i++)

        cout<<nonterm[i]<<endl;

return 0;
}


















