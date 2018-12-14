#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,a,b;
    string c1,c2,c3,s,ch;
    map<string,map<string,string> >ptabel;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(cin>>c1)
    {
        if(c1=="parsing_table") continue;
        if(c1=="END") break;
        cin>>c2>>c3;
        ptabel[c1][c2]=c3;
    }
    cin>>c1>>c2;
    cout<<"----------"<<c1<<"$----------"<<c2<<"$"<<"----------"<<endl;
    s=c1+"$";
    c2+="$";
//cout<<s<<endl;
    ch.clear();
    if(isalpha(c2[0]))
    {
        while(1)
        {
            if(c2.empty()==true) break;
            if(isalpha(c2[0])) ch+=c2[0];
            else break;
            c2.erase(c2.begin());
//cout<<ch<<endl;
        }
    }
    else{
        ch=c2[0];
        c2.erase(c2.begin());
    }
    string ans,ss;
//cout<<ch<<endl;
    while(1)
    {
        if(s[0]=='$') break;
        c1=s[0];
        s.erase(s.begin());
        if(s[0]=='\''){
            c1+=s[0];
            s.erase(s.begin());
        }
        ss=c3=ptabel[c1][ch];
        if(c3.empty()){
            cout<<"Error.... no value contain in the table"<<endl;
            return 0;
        }
        //cout<<c1<<" "<<ch<<" "<<c3<<endl;
        if(c3=="{") ss.clear();
        s.insert(0,ss);
        ss.clear();
        for(i=0;i<s.size();i++)
        {
            if(isupper(s[i])) break;
            else ss+=s[i];
        }
        if(ss==ch){
            if(ch=="$"){
                cout<<ans<<"----------"<<s<<"----------"<<ch+c2<<"----------"<<c1<<"->"<<c3<<endl;
                break;
            }
            s.erase(s.begin(),s.begin()+i);
            ans+=ss;
            cout<<ans<<"----------"<<s<<"----------"<<c2<<"----------"<<c1<<"->"<<c3<<endl;
            ch.clear();
            if(isalpha(c2[0]))
            {
                while(1)
                {
                    if(c2.empty()==true) break;
                    if(isalpha(c2[0])) ch+=c2[0];
                    else break;
                    c2.erase(c2.begin());
                }
            }
            else{
                ch=c2[0];
                c2.erase(c2.begin());
            }
        }
        else{
            cout<<ans<<"----------"<<s<<"----------"<<ch+c2<<"----------"<<c1<<"->"<<c3<<endl;
        }
        if(s[0]=='$') break;
    }
    return 0;
}
