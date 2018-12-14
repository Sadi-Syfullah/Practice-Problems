#include<bits/stdc++.h>
using namespace std;

string str;
int pos;
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
int main()
{
    while(getline(cin,str))
    {
        pos=0;
        while(pos<str.length())
        {
            string num=getnum();//Number Check
            if(num!="fail")
            {
                cout<<"Num "<<num<<"\n";
                continue;
            }

        }
    }
        return 0;
    }
