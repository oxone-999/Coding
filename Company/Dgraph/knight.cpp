// One knight and M pawns are placed on an 8 x 8 chessboard. Given all of their positions, calculate the minimum number of moves the 
// knight should take to kill all the pawns.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<pair<int, int>> pos;
vector<vector<int>> dist;
vector<vector<int>> dp;

void bfs(int id)
{
    int dx[] = {2, 2, -2, -2, 1, 1, -1, -1}, dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
    vector<vector<int>> D(8,vector<int>(8,1e9));
    D[pos[id].first][pos[id].second] = 0;

    queue<pair<int, int>> q;
    q.push(pos[id]);

    while(!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for(int k=0;k<8;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx>=0 && ny>=0 && nx<8 && ny<8 && D[nx][ny] > D[x][y] + 1){
                D[nx][ny] = D[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }

    for(int i=0;i<dist.size();i++){
        dist[id][i] = D[pos[i].first][pos[i].second];
    }
}

int rec(int mask,int curr){
    int m = pos.size()-1;

    if(mask == ((1<<m)-1)){
        return 0;
    }

    if(dp[mask][curr] != -1)
        return dp[mask][curr];

    int ans = 1e9;

    for(int i=0;i<m;i++){
        if(mask & (1<<i)) continue;
        ans = min(ans,dist[curr][i] + rec((mask | (1<<i)),i));
    }
    return dp[mask][curr] = ans;
}

void solve()
{
    int X,Y;
    int m;
    cin>>X>>Y;
    cin>>m;

    pos.clear();
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        pos.push_back({a,b});
    }
    pos.push_back({X, Y});

    dist = vector<vector<int>>(m+1,vector<int>(m+1));
    for(int i=0; i<=m; i++)
        bfs(i);

    dp = vector<vector<int>>((1<<m),vector<int>(m+1,-1));

    cout<<rec(0,m)<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    solve();
    return 0;
}