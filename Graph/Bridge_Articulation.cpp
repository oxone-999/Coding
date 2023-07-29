#include<bits/stdc++.h>
using namespace std;

#define int long long

#define MAXN 200100

vector<int> adj[MAXN];
int inTime[MAXN],loTime[MAXN];
int timer = 0;
int numSplit[MAXN];

void dfs(int node,int parent)
{
    timer++;
    inTime[node] = loTime[node] = timer;
    bool isArti = false;
    int child = 0;
    numSplit[node] = 1;

    for(auto it:adj[node])
    {
        if(it == parent) continue;
        if(!inTime[it]){ // node-it forward edge
            child++;
            dfs(it,node);
            loTime[node] = min(loTime[node],inTime[it]);
            if(loTime[it] >= inTime[node]){
                isArti = true;
                numSplit[node]++;
            }
            if(loTime[it] > inTime[node]){
                //node-it is a Bridge
            }
        }else{//node-it backward edge
            loTime[node] = min(loTime[node],loTime[it]);
        }
    }

    if(parent == 0){
        numSplit[node] = child;
    }

    if(parent == 0 && child>=2 || (parent != 0 && isArti)){
        //this node is a articulation point
    }
}

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    int comp = 0;
    for(int i=1;i<=n;i++){
        if(!inTime[i]){
            comp++;
            dfs(1,0);
        }
    }

    for(int i=1;i<=n;i++){
        if(adj[i].size() == 0){
            cout<<comp-1<<endl;
        }else{
            cout<<comp+numSplit[i]-1<<endl; 
        } 
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);cout.tie(NULL);
    solve();
}