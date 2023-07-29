// You are given an array of N integers and a size K. Find the maximum integer for every contiguous subarray of size K.

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
    int n,k;
    cin>>n>>k;

    vector<int> vec(n);

    for(auto &it:vec){
        cin>>it;
    }

    int i=0;
    int j=0;
    deque<int> dq;
    while(j<n){
        while(!dq.empty() && dq.back() < vec[j]){
            dq.pop_back();
        }
        dq.push_back(vec[j]);

        if(j-i+1 == k){
            cout<<dq.front()<<" ";
            if(vec[i] == dq.front()){
                dq.pop_front();
            }
            i++;
        }
        j++;
    }
    cout<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}