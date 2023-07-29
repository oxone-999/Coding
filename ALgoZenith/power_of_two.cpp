// You are given an array A of N integers. Find the number of pairs (i, j) such that i < j and Ai + Aj is a power of 2.

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) for(int i=0;i<vec.size();i++) cout<<vec[i]<<" "
#define debarr(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" "
#define MOD 1e9

void solve()
{
    int n;
    cin>>n;
    vector<int> vec;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vec.push_back(x);
        mp[x]++;
    }
    int cnt = 0;
    int x = 1;

    for(int i=0;i<32;i++){
        for(int j=0;j<n;j++){
            mp[vec[j]]--;
            if(mp.find(x - vec[j]) != mp.end()){
                cnt += mp[x - vec[j]];
            }
        }
        for(int j=0;j<n;j++){
            mp[vec[j]]++;
        }
        x *= 2;
    }
    cout<<cnt<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}