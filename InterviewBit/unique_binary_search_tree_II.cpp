// Given an integer A, how many structurally unique BST’s (binary search trees) exist that can store values 1…A?

#include<bits/stdc++.h> // (2nCn/(n+1)) Catalan number
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

long long t[40][40];

long long func(int n,int r)
{
    if(r == 1) return n;
    if(n == r || r == 0) return 1;
    
    if(t[n][r] != -1) return t[n][r];
    return t[n][r] = func(n-1,r-1) + func(n-1,r);
}

int numTrees(int n) {
    memset(t,-1,sizeof(t));
    long long l = func(2*n,n);
    long long r = l/(n+1);
    return r;
}

void solve()
{
    int n;
    cin>>n;
    cout<<numTrees(n)<<endl;   
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}
