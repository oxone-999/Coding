// You have a 2-D array of size N x M. Consider connected 0s (which share a common edge) as one single component and 1s as walls. 
// Replace 0s with the size of the connected component but if the size of the component is one, then leave it with 0.

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

int n,m;
int cnter;

void dfs(vector<vector<int>> &vis,vector<vector<int>> &vec,int i,int j){
    vis[i][j] = 1;
    cnter++;
    if(i > 0 && !vis[i-1][j] && vec[i-1][j] == 0) dfs(vis,vec,i-1,j);
    if(j > 0 && !vis[i][j-1] && vec[i][j-1] == 0) dfs(vis,vec,i,j-1);
    if(i < n-1 && !vis[i+1][j] && vec[i+1][j] == 0) dfs(vis,vec,i+1,j);
    if(j < m-1 && !vis[i][j+1] && vec[i][j+1] == 0) dfs(vis,vec,i,j+1);
}

void setDfs(vector<vector<int>> &vis2,vector<vector<int>> &vec,int i,int j,int x){
    vis2[i][j] = 1;
    vec[i][j] = x;
    if(i > 0 && !vis2[i-1][j] && vec[i-1][j] == 0) setDfs(vis2,vec,i-1,j,x);
    if(j > 0 && !vis2[i][j-1] && vec[i][j-1] == 0) setDfs(vis2,vec,i,j-1,x);
    if(i < n-1 && !vis2[i+1][j] && vec[i+1][j] == 0) setDfs(vis2,vec,i+1,j,x);
    if(j < m-1 && !vis2[i][j+1] && vec[i][j+1] == 0) setDfs(vis2,vec,i,j+1,x);
}

void solve()
{
    cin>>n>>m;

    vector<vector<int>> vec(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];
        }
    }

    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<int>> vis2(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cnter = 0;
            if(vis[i][j] == 0 && vec[i][j] == 0) dfs(vis,vec,i,j);
            // deb(cnter);
            int cnt = cnter;
            if(cnter <= 1) continue;
            if(vis2[i][j] == 0 && vec[i][j] == 0) setDfs(vis2,vec,i,j,cnt);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}