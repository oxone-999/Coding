//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

lli drx[4] = {0,0,1,-1};
lli dry[4] = {1,-1,0,0};

void solve()
{
    lli n,m;
    cin>>n>>m;

    vector<vector<lli>> vec(n+1,vector<lli>(m+1,0));

    for(lli i=1;i<=n;i++){
        for(lli j=1;j<=m;j++){
            cin>>vec[i][j];
        }
    }

    deque<pair<lli,lli>> q;

    vector<vector<lli>> dist(n+1,vector<lli>(m+1,1e18));

    dist[1][1] = 0;

    q.push_back({1,1});

    while(!q.empty()){
        lli x = q.front().first;
        lli y = q.front().second;
        q.pop_front();    

        for(lli k=0;k<4;k++){
            lli newX = x + drx[k];
            lli newY = y + dry[k];
            lli w = 1;
            if(newX < 1 || newX > n || newY < 1 || newY > m) continue;

            if(k+1 == vec[x][y]){
                w = 0;
            }

            if(dist[newX][newY] > dist[x][y] + w){
                dist[newX][newY] = dist[x][y] + w;
                if(w == 0){
                    q.push_front({newX,newY});
                }else q.push_back({newX,newY});
            }
        }
    }

    if(dist[n][m] == 1e18){
        cout<<(-1)<<endl;
    }else cout<<dist[n][m]<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}