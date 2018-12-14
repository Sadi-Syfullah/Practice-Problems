#include<bits/stdc++.h>
using namespace std;
map<string,vector<string> >Connected_Road;
map<string,map<string,int> > straightLineDistance;
map<string,map<string,int> > dist;
map<string,string>parent;
map<string,bool>vis;
map<string,bool>ok;
map<string,bool>newCity;
map<string,int>length;
string source,goal;

struct town{
    string name;
    int cost;
    bool operator < (const town & p) const
    {
        return cost > p.cost;
    }
};

priority_queue<town>q;

void dfs(town u,int cutoff)
{
    for(int i=0;i<Connected_Road[u.name].size();i++)
    {
        string cc=Connected_Road[u.name][i];
        if(length[u.name]+dist[u.name][cc]+straightLineDistance[cc][goal]<=cutoff)
        {
            parent[cc]=u.name;
            length[cc]=length[u.name]+dist[u.name][cc];
            town v;
            v.name=cc;
            v.cost=length[cc]+straightLineDistance[cc][goal];
            dfs(v,cutoff);
            vis[u.name]=true;
            ok[u.name]=true;
        }
    }
    if(ok[u.name]==false)
    {
//cout<<"......"<<u.name<<" "<<u.cost<<endl;
        vis[u.name]=true;
        q.push(u);
    }
}

void IDA_Star()
{
    int cutoff=straightLineDistance[source][goal];
    town u;
    u.name=source;
    u.cost=cutoff;
    while(cutoff<=700)
    {
        if(vis[goal]==true) break;
        length[u.name]=0;
        while(q.empty()==false) q.pop();
        parent.clear();
        parent[u.name]=u.name;
//cout<<u.name<<" "<<cutoff<<endl;
        dfs(u,cutoff);
        town v;
        v=q.top();
        cutoff=2147483647;
        for(int i=0;i<Connected_Road[v.name].size();i++)
        {
            string ss=Connected_Road[v.name][i];
            int a=length[v.name]+dist[v.name][ss]+straightLineDistance[ss][goal];
//cout<<"next cutoff "<<ss<<" "<<a<<endl;
            cutoff=min(cutoff,a);
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
    string s,c,ch;
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
        IDA_Star();
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


