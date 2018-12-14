#include<bits/stdc++.h>
using namespace std;
#define FOR(i, b, e) for(int i = b; i <= e; i++)
string keyword[32]= {"auto","break","case","char","const",
"continue","default", "do","double","else","enum","extern",
"float","for","goto", "if","int","long","register","return",
"short","signed", "sizeof","static","struct","switch",
"typedef","union", "unsigned","void","volatile","while"};
string str;
int pos;
string getid()
{
    int state=9;
    string temp="";
    while(1)
    {
        switch(state)
        {
        case 9:
            if(isalpha(str[pos])||str[pos]=='_')
            {
                state=10;
                temp+=str[pos];
            }
            else return "fail";
            pos++;
            break;
        case 10:
            if(isalnum(str[pos]))
            {
                state=10;
                temp+=str[pos];
            }
            else return temp;
            pos++;
            break;
        }
    }
}
int main()
{
   ifstream inp("input.txt");
    ofstream oup("output.txt");
    while(!inp.eof())
    {
        getline(inp,str);
        pos=0;
        while(pos<str.length())
        {
            string id =getid();//Identifier Check
            if(id!="8fail")
            {
                bool ans=true;
                for(int i=0;i<=31;i++)
                if(id==keyword[i])//Keyword Check
                {
                    ans=false;
                    break;
                }
                if(ans)
                oup<<"Id "<<id<<"\n";
                else
                oup<<"Key "<<id<<"\n";
            }
            pos++;
        }
    }
    return 0;
}

