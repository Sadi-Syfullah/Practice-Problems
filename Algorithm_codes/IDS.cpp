#include<bits/stdc++.h>
using namespace std;
map<string,vector<string> >Connected_Road;
map<string,map<string,int> > straightLineDistance;
map<string,map<string,int> > dist;
map<string,string>parent;
map<string,bool>vis;
map<string,bool>newCity;
map<string,int>Depth;

bool IDS(string source,string goal)
{
    queue<string>q;
    q.push(source);
    vis[source]=true;
    parent[source]=source;
    Depth[source]=0;
    while(q.empty()==false)
    {
        string s=q.front();
        q.pop();
        if(s==goal) break;
        if(Depth[s]<=5){
            for(int i=0;i<Connected_Road[s].size();i++)
            {
                string c=Connected_Road[s][i];
                if(vis[c]==false)
                {
                    vis[c]=true;
                    parent[c]=s;
                    Depth[c]=Depth[s]+1;
                    q.push(c);
                }
            }
        }
    }
}

void print(string s)
{
    if(s==parent[s])
    {
        cout<<s;
        return;
    }
    else print(parent[s]);
    cout<<"->"<<s;
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
        IDS(source,goal);
        cout<<endl;
        if(vis[goal]==true){
            cout<<"Solution Found :) :D :)"<<endl<<endl;
            print(goal);
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

