// One knight and M pawns are placed on an 8 x 8 chessboard. Given all of their positions, calculate the minimum number of moves the 
// knight should take to kill all the pawns.

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int m;
int dx[8] = {2,-2,1,-1,2,-2,1,-1};
int dy[8] = {1,1,2,2,-1,-1,-2,-2};

void bfs(int i)
{
    vector<int> dist(n+1);
    dist[i] = 0;
    queue<pair<int, int>> q;
    q.push({v[i].first, v[i].second});
    while(!q.empty())
    {
        
    }
}

int rec(int mask,int curr){
        if(mask == ((1<<m)-1)){
            return 0;
        }

        int ans = 0;
        for()

    }
}

void solve()
{
    int X,Y;
    cin>>X>>Y;

    cin>>m;

    vector<pair<int, int>> v(m);
    for(auto &it : v)
        cin >> it.first >> it.second;

    v.push_back({X, Y});

    for(int i=0; i<m; i++)
        bfs(i);

    cout<<rec(0,m)<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    solve();
    return 0;
}