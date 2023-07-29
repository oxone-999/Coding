//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const int MOD = 1e9+7;

void solve()
{
    int n,k;
    cin>>n>>k;

    vector<int> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }
    int i=0;
    int j=0;
    deque<int> q;
    while(j<n){
        while(!q.empty() && q.back() < vec[j]){
            q.pop_back();
        }
        q.push_back(vec[j]);
        if(j-i+1 == k){
            cout<<q.front()<<" ";
            if(vec[i] == q.front()) q.pop_front();
            i++; 
        }
        j++;
    }cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}