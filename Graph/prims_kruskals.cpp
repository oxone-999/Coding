#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

const int n = 1e5+7;

int parent[n];
int rankP[n];

int findParent(int node)
{
    if(node == parent[node]) 
        return node;
    return parent[node] = findParent(parent[node]);
}

void unionn(int u, int v)
{
    u = findParent(u);
    v = findParent(v);
    if(rankP[u] < rankP[v])
        parent[u] = v;
    else if(rankP[u] > rankP[v]) parent[v] = u;
    else 
    {
        parent[v] = u;
        rankP[u]++;
    }
}

int prims_algorithm(int A, vector<vector<int>> &B) {
    int N = A;
    vector<pair<int,int>> adj[N];
    int n = B.size();
    for(int i=0;i<n;i++)
    {
        int u=B[i][0]-1;
        int v=B[i][1]-1;
        int w=B[i][2];

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int parent[N]; 
    int key[N];
    bool mstSet[N]; 

    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 

    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    key[0] = 0; 
    parent[0] = -1;
    pq.push({0, 0});

    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 

        mstSet[u] = true;         

        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
                key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
    } 
    
    int ans = 0;
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            if(adj[i][j].first == parent[i])
            {
                ans += adj[i][j].second;
                break;   
            }
        }
    }
    return ans;
}

int kruskals_algorithm(int A, vector<vector<int>> &B){
    int N = A;
    for(int i=0;i<N;i++)
        parent[i] = i;
    
    int n = B.size();
    
    for(int i=0;i<n;i++)
    {
        B[i][0]--;
        B[i][1]--;
        reverse(B[i].begin(),B[i].end());
    }   
    
    sort(B.begin(),B.end());

    int cost = 0;
    for(auto it:B)
    {
        if(findParent(it[2]) != findParent(it[1]))
        {
            cost += it[0];
            unionn(it[2],it[1]);
        }
    }
    return cost;
}

void solve()
{
    int N;
    cin>>N;
    vector<vector<int>> B;

    cout<<prims_algorithm(N,B)<<endl;
    cout<<kruskals_algorithm(N,B)<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}