// You are given an array of N integers. For each position, find the nearest position to its left having a smaller value. 
// (1-based indexing)

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

    vector<int> vec(n);
    for(auto &it:vec){
        cin>>it;
    }

    stack<pair<int,int>> st;

    for(int i=0;i<n;i++){
        if(st.empty()) cout<<0<<" ";
        else if(st.top().first >= vec[i]){
            while(!st.empty() && st.top().first >= vec[i]){
                st.pop();
            }
            if(st.empty()) cout<<0<<" ";
            else cout<<st.top().second+1<<" ";
        }
        else cout<<st.top().second+1<<" ";
        st.push({vec[i],i});
    }
    cout<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}
