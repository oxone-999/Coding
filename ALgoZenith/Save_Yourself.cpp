//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

lli n,m;

lli drx[4] = {1,0,-1,0};
lli dry[4] = {0,1,0,-1};

const lli N = 1005;

bool grid[N][N];
lli distM[N][N];
lli distA[N][N];

queue<pair<int,int>> monsOcc;
queue<pair<int,int>> playerOcc;


bool isValid(lli x,lli y){
    if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == false){
        return 0;
    }return 1;
}

void solve()
{
    cin>>n>>m;

    memset(distM,-1,sizeof(distM));
    memset(distA,-1,sizeof(distA));

    vector<string> vec;
    while(!monsOcc.empty()){
        monsOcc.pop();
    }

    while(!playerOcc.empty()){
        playerOcc.pop();
    }

    for(lli i=0;i<n;i++){
        string s;
        cin>>s;
        vec.push_back(s);
    }

    for(lli i=0;i<n;i++){
        for(lli j=0;j<m;j++){
            grid[i][j] = true;
            if(vec[i][j] == '#'){
                grid[i][j] = false;
            }else if(vec[i][j] == 'M'){
                distM[i][j] = 0;
                monsOcc.push({i,j});
            }else if(vec[i][j] == 'A'){
                distA[i][j] = 0;
                playerOcc.push({i,j});
            }
        }
    }

    lli ans = INT_MAX;

    //bfs monster

    while(!monsOcc.empty()){
        lli x = monsOcc.front().first;
        lli y = monsOcc.front().second;
        monsOcc.pop();

        for(lli k=0;k<4;k++){
            lli newX = x + drx[k];
            lli newY = y + dry[k];

            if(isValid(newX,newY) && distM[newX][newY] == -1){
                distM[newX][newY] = distM[x][y] + 1;
                monsOcc.push({newX,newY});
            }
        }
    }

    //bfs player

    while(!playerOcc.empty()){
        lli x = playerOcc.front().first;
        lli y = playerOcc.front().second;
        playerOcc.pop();

        for(lli k=0;k<4;k++){
            lli newX = x + drx[k];
            lli newY = y + dry[k];

            if(isValid(newX,newY) && distA[newX][newY] == -1){
                distA[newX][newY] = distA[x][y] + 1;
                playerOcc.push({newX,newY});
            }
        }
    }

    for(lli i=0;i<n;i++){
        for(lli j=0;j<m;j++){
            if(i == 0 || j == 0){
                if(grid[i][j] && distA[i][j] >= 0 && (distM[i][j] > distA[i][j] || distM[i][j] == -1)){
                    ans = min(ans,distA[i][j]);
                }
            }
        }
    }

    for(lli i=0;i<n;i++){
        for(lli j=0;j<m;j++){
            if(i == n-1 || j == m-1){
                if(grid[i][j] && distA[i][j] >= 0 && (distM[i][j] > distA[i][j] || distM[i][j] == -1)){
                    ans = min(ans,distA[i][j]);
                }
            }
        }
    }
    
    if(ans != INT_MAX){
        cout<<"YES"<<endl<<ans<<endl;
    }
    else cout<<"NO"<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}