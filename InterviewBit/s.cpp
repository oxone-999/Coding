#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

map<string,int> mp;

int func(vector<vector<int>> &A,int sum,int i,int j,int k,int n,int m){
    if(i == n-1 && j == m-1){
        if(sum % k == 0) return true;
        else false;
    }

    string s;
    s += to_string(i) + to_string(j) + to_string(sum);

    if(mp.find(s) != mp.end()) return mp[s];

    int l = 0;
    int r = 0;
    if(i+1<n) l = func(A,sum+A[i+1][j],i+1,j,k,n,m);
    if(j+1<m) r = func(A,sum+A[i][j+1],i,j+1,k,n,m);
    
    return mp[s] = l+r;
}

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<int>> A(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>A[i][j];
        }
    }
    int sum = 0;
    cout<<func(A,A[0][0],0,0,k,n,m)<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}