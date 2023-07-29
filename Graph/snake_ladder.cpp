void topoSort(int node,vector<int> &vis, vector<pair<int,int>> adj[],stack<int> &s)
{
    vis[node] = 1;
    
    for(auto &it:adj[node])
        if(!vis[it.first])
            topoSort(it,vis,adj,s);
    s.push(node);
}

int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    vector<pair<int,int>> adj[101];
    
    for(int i=1;i<100;i++)
        for(int j=i+1;j<min((7+i,100);i++)
            adj[i].push_back({j,1});
    
    int n = A.size();
    int m = B.size();
    
    for(int i=0;i<n;i++)
    {
        adj[A[i][0]].clear();
        adj[A[i][0]].push_back({A[i][1],0});
    }
    
    for(int i=0;i<m;i++)
    {
        adj[B[i][1]].clear();
        adj[B[i][1]].push_back({B[i][0],0});
    }
    
    vector<int> vis(101,0);
    stack<int> s;
    
    for(int i=1;i<101;i++)
        if(!vis[i])
            topoSort(i,vis,adj,s);
            
    int dist[101];
    int INF = 1e9;
    
    for(int i=0;i<101;i++)
        dist[i] = INF;
        
    while(!s.empty())
    {
        int node = s.top();
        s.pop();
        
        if(dist[node] != INF)
        {
            if(dist[node] + it.second < dist[it.second])
            {
                dist[it.second] = dist
            }
        }
    }
}
