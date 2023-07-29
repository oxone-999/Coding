//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

int drx[4] = {1,0,-1,0};
int dry[4] = {0,1,0,-1};

int n,m;

bool isValid(int x,int y){
    if(x < 0 || y < 0 || x >= n || y >= m){
        return 0;
    }return 1;
}

void dfs(vector<string> &vec, vector<vector<bool>> &vis,int i,int j){
    vis[i][j] = 1;

    for(int k=0;k<4;k++){
        int newX = i + drx[k];
        int newY = j + dry[k];

        if(isValid(newX,newY) && vec[newX][newY] == '.' && vis[newX][newY] == 0){
            dfs(vec,vis,newX,newY);
        }
    }    
}

void solve()
{
    cin>>n>>m;

    vector<string> vec(n);

    for(int i=0;i<n;i++){
        cin>>vec[i];
    }

    vector<vector<bool>> vis(n,vector<bool>(m,0));

    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vec[i][j] == '.' && vis[i][j] == 0){
                cnt++;
                dfs(vec,vis,i,j);
            }
        }
    }

    cout<<cnt<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}