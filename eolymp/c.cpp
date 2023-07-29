#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

int ans = INT_MAX;

void func(int i,int j,vector<vector<char>> vec,int cnt,int x){
    if(i<0 || i>3 | j<0 || j>3){
        return;
    }
    if(vec[i][j] == 'H' && x == 0){
        ans = min(ans,cnt);
        return;
    }
    if(vec[i+1][j] == 'F') func(i+1,j,vec,cnt,x-1);
    else func(i+1,j,vec,cnt,x);
    if(vec[i][j+1] == 'F') func(i,j+1,vec,cnt,x-1);
    else func(i,j+1,vec,cnt,x);
    if(vec[i-1][j] == 'F') func(i-1,j,vec,cnt,x-1);
    else func(i-1,j,vec,cnt,x);
    if(vec[i][j-1] == 'F') func(i,j-1,vec,cnt,x-1);
    else func(i,j-1,vec,cnt,x);
}

void solve()
{
    int x = 0;
    vector<vector<char>> vec(4,vector<char>(4,0));
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>vec[i][j];
            if(vec[i][j] == 'F') x++;
        }
    }
    int cnt = 0;
    int i,j;
    func(i,j,vec,cnt,x);
    cout<<cnt;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
solve();
return 0;
}