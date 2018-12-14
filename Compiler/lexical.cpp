//Lexical Analyzer
//Abinash Ghosh(Om)
#include<bits/stdc++.h>
using namespace std;
string keyword[32]= {"auto","break","case","char","const",
"continue","default", "do","double","else","enum","extern",
"float","for","goto", "if","int","long","register","return",
"short","signed", "sizeof","static","struct","switch",
"typedef","union", "unsigned","void","volatile","while"};

string str;
int pos;
string getrelop()
{
    int state=0;
    while(1)
    {
        switch(state)
        {
        case 0:
            if(str[pos]=='<')state=1;
            else if(str[pos]=='=')state=5;
            else if(str[pos]=='>')state=6;
            else return "fail";
            pos++;
            break;
        case 1:
            if(str[pos]=='=')state=2;
            else if(str[pos]=='>')state=3;
            else state=4;
            pos++;
            break;
        case 2:
            pos++;
            return "LE";
        case 3:
            pos++;
            return "NE";
        case 4:
            return "LT";
        case 5:
            pos++;
            return "EQ";
        case 6:
            if(str[pos]=='=')state=7;
            else state=8;
            pos++;
            break;
        case 7:
            pos++;
            return "GE";
        case 8:
            return "GT";
        }
    }
}
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
            else return "8fail";
            pos++;
            break;
        case 10:
            if(isalnum(str[pos])||str[pos]=='_')
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
string getnum()
{
    int  state=12;
    string temp="";
    while(1)
    {
        switch(state)
        {
        case 12:
            if(isdigit(str[pos]))state=13;
            else return "fail";
            temp+=str[pos];
            pos++;
            break;
        case 13:
            if(isdigit(str[pos]))state=13;
            else if(str[pos]=='.')state=14;
            else if(str[pos]=='E')state=16;
            else return temp;
            temp+=str[pos];
            pos++;
            break;
        case 14:
            if(isdigit(str[pos]))state=15;
            else return "fail";
            temp+=str[pos];
            pos++;
            break;
        case 15:
            if(isdigit(str[pos]))state=15;
            else if(str[pos]=='E')state=16;
            else return temp;
            temp+=str[pos];
            pos++;
            break;
        case 16:
            if(isdigit(str[pos]))state=18;
            else if(str[pos]=='+'||str[pos]=='-')
                state=17;
            temp+=str[pos];
            pos++;
            break;
        case 17:
            if(isdigit(str[pos]))state=18;
            temp+=str[pos];
            pos++;
            break;
        case 18:
            if(isdigit(str[pos]))state=18;
            else return temp;
            temp+=str[pos];
            pos++;
            break;
        }
    }
}
string getws()
{
    int state =22;
    while(1)
    {
        switch(state)
        {
        case 22:
            if(str[pos]>=0&&str[pos]<=32)state=23;
            else return "fail";
            pos++;
            break;
        case 23:
            if(str[pos]>=0&&str[pos]<=32)state=23;
            else return "Whitespace";
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
            string relop=getrelop();
            if(relop!="fail")//Relational Operator Check
            {
                pos--;
                oup<<"Relop "<<relop<<"\n";
                continue;
            }
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
                continue;
            }
            string num=getnum();//Number Check
            if(num!="fail")
            {
                oup<<"Num "<<num<<"\n";
                continue;
            }
            string whites=getws();//Whitespace Check
            if(whites!="fail")
            {
                oup<<"WS "<<"\n";
                continue;
            }
                //Unary Operator Check
            if(str[pos]=='+'||str[pos]=='-'||
               str[pos]=='*'||str[pos]=='/'||str[pos]=='%')
            {
                oup<<"Unary "<<str[pos]<<"\n";
                pos++;
                continue;
            }
            pos++;
        }
    }
    return 0;
}
