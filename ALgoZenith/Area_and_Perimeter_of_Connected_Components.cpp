//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

int n;
vector<string> vec;

int drx[4] = {1,0,-1,0};
int dry[4] = {0,1,0,-1};

pair<int,int> dfs(int i ,int j, vector<vector<bool>> &vis){
    if(i >= n || i < 0 || j >= n || j < 0) return {0,1};
    if(vec[i][j] == '.') return {0,1};
    if(vis[i][j]) return {0,0};

    vis[i][j] = 1;

    int area = 1,par = 0;

    for(int k=0;k<4;k++){
        int newX = i + drx[k];
        int newY = j + dry[k];

        pair<int,int> ans = dfs(newX,newY,vis);

        area += ans.first;
        par += ans.second;
    }

    return {area,par};
}

void solve()
{
    cin>>n;
    vector<vector<bool>> vis(n,vector<bool>(n,0));

    for(int i=0;i<n;i++){
            string s;
            cin>>s;
            vec.push_back(s);
    }

    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vec[i][j] == '#' && vis[i][j] == 0){
                pair<int,int> x = dfs(i,j,vis);
                v.push_back(x);
            }
        }
    }

    sort(all(v),[](pair<int,int> &a,pair<int,int> &b){
        if(a.first == b.first) return a.second < b.second;
        else return a.first > b.first;
    });

    cout<<v[0].first<<" "<<v[0].second;
}

signed main(){
    IOS
    solve();
    return 0;
}