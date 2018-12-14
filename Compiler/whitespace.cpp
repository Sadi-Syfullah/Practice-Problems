#include<bits/stdc++.h>
using namespace std;
string str;
int pos;
string getws()
{
    int state=22;

    if(str[pos]>=0&&str[pos]<=32)
    {
        pos++;
        return "Whitespace";
    }
    else
    {

        return "fail";
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
            string whites=getws();
            if(whites!="fail")
            {
                cout<<"WS "<<endl;
                continue;
            }
            pos++;
        }


    }

    return 0;
}
