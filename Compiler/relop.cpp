#include<bits/stdc++.h>
using namespace std;


#define FOR(i, b, e) for(int i = b; i <= e; i++)

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
            if(str[pos]=='<') state=1;
            else if(str[pos]=='=') state=5;
            else if(str[pos]=='>') state=6;
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
            pos++;
            return "LT";
        case 5:
            pos++;
            return "EQ";
        case 6:
            if(str[pos]=='=')
                state=7;
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
           if(relop!="fail")
           {
               pos--;
               cout<<"Relop "<<relop<<endl;
               continue;
           }
           pos++;

       }
   }

    return 0;
}
