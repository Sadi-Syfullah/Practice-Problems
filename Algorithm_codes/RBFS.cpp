#include<bits/stdc++.h>
#define inf 2147483647
using namespace std;
map<string,vector<string> >Connected_Road;
map<string,map<string,int> > straightLineDistance;
map<string,map<string,int> > dist;
map<string,string>parent;
map<string,map<string,bool> >vis;
map<string,bool>newCity;
map<string,bool>visited;
map<string,int>length;
map<string,map<string,int> >Total;
string goal;

struct town{
    string name;
    int cost;
    bool operator < (const town & p) const
    {
        return cost > p.cost;
    }
};


bool solution_not_found=true;
void RBFS(town first,town second)
{
    town u,v;
    u=first;
    visited[first.name]=true;
    if(first.name==goal)
    {
        solution_not_found=false;
        return;
    }
    while(solution_not_found and u.cost<second.cost)
    {
        priority_queue<town>q;
        for(int i=0;i<Connected_Road[first.name].size();i++)
        {
            town newtown;
            string ss=Connected_Road[first.name][i];
            if(vis[first.name][ss]==false)
            {
                vis[first.name][ss]=true;
                length[ss]=length[first.name]+dist[first.name][ss];
                newtown.name=ss;
                newtown.cost=length[ss]+straightLineDistance[ss][goal];
                Total[first.name][ss]=newtown.cost;
                q.push(newtown);
            }
            else{
                newtown.name=ss;
                newtown.cost=Total[first.name][ss];
                q.push(newtown);
            }
        }

        u=q.top(); q.pop();
        v=q.top(); q.pop();

        if(u.cost<second.cost)
        {
            parent[u.name]=first.name;
            if(v.cost<second.cost)
            {
                RBFS(u,v);
            }
            else RBFS(u,second);
        }
        u.cost=Total[first.name][u.name];

        if(u.cost>second.cost)
        {
            string cc=parent[first.name];
            Total[cc][first.name]=Total[first.name][u.name];
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
    string s,c,ch,source;
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
        town u,v;
        u.name=source;
        u.cost=straightLineDistance[source][goal];
        v.name=source;
        v.cost=inf;
        length[source]=0;
        parent[source]=source;
        Total[source][source]=u.cost;
        RBFS(u,v);
        cout<<endl;
        if(visited[goal]==true){
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



