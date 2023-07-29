//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;
int ans = 0;
const int N = 7;
int vis[N][N];

void func(int n,string &s,int i,int j){
    if(i == N-1 && j == 0){
        if(n == N*N-1) ans++;
        return;
    }

    if (((i + 1 == N || (vis[i - 1][j] && vis[i + 1][j])) && j - 1 >= 0 && j + 1 < N && !vis[i][j - 1] && !vis[i][j + 1]) ||
        ((j + 1 == N || (vis[i][j - 1] && vis[i][j + 1])) && i - 1 >= 0 && i + 1 < N && !vis[i - 1][j] && !vis[i + 1][j]) ||
        ((i == 0 || (vis[i + 1][j] && vis[i - 1][j])) && j - 1 >= 0 && j + 1 < N && !vis[i][j - 1] && !vis[i][j + 1]) ||
        ((j == 0 || (vis[i][j + 1] && vis[i][j - 1])) && i - 1 >= 0 && i + 1 < N && !vis[i - 1][j] && !vis[i + 1][j]))
        return;

    vis[i][j] = 1;

    if(s[n] == '?'){
        //down
        if(i+1 < N && !vis[i+1][j]){
            func(n+1,s,i+1,j);
        }
        //up
        if(i-1 >= 0 && !vis[i-1][j]){
            func(n+1,s,i-1,j);
        }
        //left
        if(j-1 >= 0 && !vis[i][j-1]){
            func(n+1,s,i,j-1);
        }
        //right
        if(j+1 < N && !vis[i][j+1]){
            func(n+1,s,i,j+1);
        }
    }else{
        if(s[n] == 'D'){
            //down
            if(i+1 < N && !vis[i+1][j]){
                func(n+1,s,i+1,j);
            }
        }else if(s[n] == 'U'){
            //up
            if(i-1 >= 0 && !vis[i-1][j]){
                func(n+1,s,i-1,j);
            }
        }else if(s[n] == 'L'){
            //left
            if(j-1 >= 0 && !vis[i][j-1]){
                func(n+1,s,i,j-1);
            }
        }else{
            //right
            if(j+1 < N && !vis[i][j+1]){
                func(n+1,s,i,j+1);
            }
        }
    }
    vis[i][j] = 0;
    return;
}

void solve()
{
    string s;
    cin>>s;
    int n = 0;
    func(n,s,0,0);
    cout<<ans<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}