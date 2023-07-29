//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

//            D,R,U,L
int drx[4] = {1,0,-1,0};
int dry[4] = {0,1,0,-1};

void solve()
{
    int n,m;
    cin>>n>>m;

    vector<vector<char>> vec(n,vector<char>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];
        }
    }

    deque<pair<int,int>> dq;

    dq.push_front({0,0});

    vector<vector<int>> dist(n,vector<int>(m,1e9));
    dist[0][0] = 0;

    // cerr<<"sdf"<<endl;
    while(!dq.empty()){
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();

        for(int k=0;k<4;k++){
            int newX = x + drx[k];
            int newY = y + dry[k];

            if(newX >= 0 && newX < n && newY >= 0 && newY < m){
                if(vec[newX][newY] == '.'){
                    if(dist[newX][newY] > dist[x][y]){
                        dist[newX][newY] = dist[x][y];
                        dq.push_front({newX,newY});
                    }
                }else {
                    for(int p=newX-1;p<=newX+1;p++){
                        for(int q=newY-1;q<=newY+1;q++){
                            if(p < 0 || p >=n || q < 0 || q >= m) continue;
                            if(dist[p][q] > dist[x][y] + 1){
                                dist[p][q] = dist[x][y] + 1;
                                dq.push_back({p,q});
                            }
                        }
                    }
                }
            }
        }
    }

    cout<<dist[n-1][m-1]<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}