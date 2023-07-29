//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

void solve()
{
    lli n;
    cin>>n;
    
    vector<lli> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    stack<pair<lli,lli>> st;
    vector<lli> v1;

    for(lli i=0;i<n;i++){
        if(st.empty()) v1.push_back(-1);
        else if(st.top().first >= vec[i]){
            while(!st.empty() && st.top().first >= vec[i]){
                st.pop();
            }
            if(!st.empty()) v1.push_back(st.top().second);
            else v1.push_back(-1);
        }else v1.push_back(st.top().second);
        st.push({vec[i],i});
    }

    while(!st.empty()){
        st.pop();
    }

    vector<lli> v2;

    for(lli i=n-1;i>=0;i--){
        if(st.empty()) v2.push_back(n);
        else if(st.top().first >= vec[i]){
            while(!st.empty() && st.top().first >= vec[i]){
                st.pop();
            }
            if(!st.empty()) v2.push_back(st.top().second);
            else v2.push_back(n);
        }else v2.push_back(st.top().second);
        st.push({vec[i],i});
    }
    reverse(v2.begin(),v2.end());

    vector<lli> ans(n,0);
    for(lli i=0;i<n;i++){
        lli x = v2[i]-v1[i]-2;
        ans[x] = max(ans[x],vec[i]);
    }

    for(lli i=n-2;i>=0;i--){
        ans[i] = max(ans[i+1],ans[i]);
    }

    for(lli i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}