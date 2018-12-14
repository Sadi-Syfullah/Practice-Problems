#include<bits/stdc++.h>
using namespace std;
map<string,vector<string> >Connected_Road;
map<string,map<string,int> > straightLineDistance;
map<string,map<string,int> > dist;
map<string,string>parentF;
map<string,string>parentB;
map<string,bool>visF;
map<string,bool>visB;
map<string,bool>newCity;
map<string,int>DepthF;
map<string,int>DepthB;

string BI_IDS(string source,string goal)
{
    queue<string>F;
    F.push(source);
    visF[source]=true;
    parentF[source]=source;
    DepthF[source]=0;

    queue<string>B;
    B.push(goal);
    parentB[goal]=goal;
    visB[goal]=true;
    DepthB[goal]=0;

    string c,s;
    while(F.empty()==false or B.empty()==false)
    {
        s=F.front();
        F.pop();
        if(visB[s]==true){
            return s;
        }
        if(DepthF[s]<=10){
            for(int i=0;i<Connected_Road[s].size();i++)
            {
                c=Connected_Road[s][i];
                if(visF[c]==false)
                {
                    visF[c]=true;
                    parentF[c]=s;
                    DepthF[c]=DepthF[s]+1;
                    F.push(c);
                }
            }
        }

        s=B.front();
        B.pop();
        if(visF[s]==true){
            return s;
        }
        if(DepthB[s]<=10){
            for(int i=0;i<Connected_Road[s].size();i++)
            {
                c=Connected_Road[s][i];
                if(visB[c]==false)
                {
                    visB[c]=true;
                    parentB[c]=s;
                    DepthB[c]=DepthB[s]+1;
                    B.push(c);
                }
            }
        }


    }
}

void printF(string s)
{
    if(s==parentF[s])
    {
        cout<<s;
        return;
    }
    else printF(parentF[s]);
    cout<<"->"<<s;
}

void printB(string s)
{
    cout<<"->"<<s;
    if(s==parentB[s]) return;
    else printB(parentB[s]);
}

int main()
{

    int i,j,a,b,n,m,d,noT;
    string s,c,ch,source,goal;
    vector<string>city;
    cout<<"Enter Your Current City :"; cin>>source;
    cout<<"Enter Your Goal City :"; cin>>goal;
    freopen("Romania.txt","r",stdin);
    cin>>noT; //no of target
    while(noT--)
    {
        cin>>s;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>c>>m;
            if(newCity[c]==false){
                city.push_back(c);
                newCity[c]=true;
            }
            straightLineDistance[c][s]=m;
        }
    }
    while(cin>>c>>s>>m)
    {
        Connected_Road[c].push_back(s);
        Connected_Road[s].push_back(c);
        dist[c][s]=m;
        dist[s][c]=m;
    }

    if(newCity[goal]==true and newCity[source]==true){
        string mid="NULL";
        mid=BI_IDS(source,goal);
        cout<<endl;
        if(visB[mid]==true){
            cout<<"Solution Found :) :D :)"<<endl<<endl;
            printF(parentF[mid]);
            printB(mid);
        }
        else{
            cout<<"Solution Not Found :( :0"<<endl;
        }
    }
    else{
        cout<<"Something wrong in the name of the City"<<endl;
        cout<<"Suggestion"<<endl;
        for(i=0;i<city.size();i++)
        {
            cout<<i+1<<" "<<city[i]<<endl;
        }
    }
    return 0;
}


