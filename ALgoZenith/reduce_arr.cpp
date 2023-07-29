// You are given an array of N integers. In one operation, remove any two elements in the array and add their sum to the array. 
// The cost of this operation will be the sum of the two elements. Print the minimum cost till the size of the array does not 
// become 1.

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

void solve()
{
    int n;
    cin>>n;

    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        pq.push(x);
    }
    int ans = 0;
    while(!pq.empty())
    {
        int num(0),num2(0);
        if(!pq.empty()) {
            num = pq.top();
            pq.pop();
        }
        if(!pq.empty()){
            num2 = pq.top();
            pq.pop();
        }
        ans += num + num2;
        if(pq.empty()) break;
        pq.push(num + num2);
    }
    cout<<ans<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}