#include<bits/stdc++.h>
using namespace std;
map<string,vector<string> >Connected_Road;
map<string,map<string,int> > straightLineDistance;
map<string,map<string,int> > dist;
map<string,string>parent;
map<string,bool>vis;
map<string,bool>newCity;
map<string,int>length;

struct town{
    string name;
    int cost;
    bool operator < (const town & p) const
    {
        return cost > p.cost;
    }
};

void UCS(string source,string goal)
{
    priority_queue<town>q;
    town t,w,v;
    t.name=source; t.cost=0;
    q.push(t);
    vis[source]=true;
    parent[source]=source;
    length[source]=0;
    while(q.empty()==false)
    {
        w=q.top(); q.pop();
        string c=w.name;
        if(c==goal) return;
        for(int i=0;i<Connected_Road[c].size();i++)
        {
            string s=Connected_Road[c][i];
            if(vis[s]==false){
                vis[s]=true;
                length[s]=-1;
            }

            if(length[s]>length[c]+dist[c][s]  or length[s]==-1)
            {
                length[s]=length[c]+dist[c][s];
                v.cost=length[s];
                v.name=s;
                q.push(v);
                parent[s]=c;
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
        UCS(source,goal);
        cout<<endl;
        if(vis[goal]==true){
            cout<<"Solution Found :) :D :)"<<endl<<endl;
            print(goal);
            cout<<endl<<endl;
            cout<<"Total Cost = "<<length[goal]<<endl;
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

