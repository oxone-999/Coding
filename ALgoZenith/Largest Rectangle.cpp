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

    stack<pair<lli,lli>> st2;
    vector<lli> v2;

    for(lli i=n-1;i>=0;i--){
        if(st2.empty()) v2.push_back(n);
        else if(st2.top().first >= vec[i]){
            while(!st2.empty() && st2.top().first >= vec[i]){
                st2.pop();
            }
            if(!st2.empty()) v2.push_back(st2.top().second);
            else v2.push_back(n); 
        }else v2.push_back(st2.top().second);
        st2.push({vec[i],i});
    }
    reverse(all(v2));

    // for(auto it:v1) cout<<it<<" ";
    // cout<<endl;
    // for(auto it:v2) cout<<it<<" ";
    // cout<<endl;

    lli ans = LLONG_MIN;
    for(lli i=0;i<n;i++){
        ans = max<lli>(ans,abs(v2[i]-v1[i]-1)*vec[i]);
    }
    cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}