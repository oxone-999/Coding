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
    map<lli,lli> mp;
    set<lli> st;

    lli n;
    cin>>n;
    lli sum = 0;

    while(n--){
        lli ch;
        cin>>ch;

        if(ch == 1){
            lli x;cin>>x;
            mp[x]++;
            st.insert(x);
            sum += x;
        }else if(ch == 2){
            lli x;cin>>x;
            if(mp.count(x)){
                mp[x]--;
                if(mp[x] == 0){
                    st.erase(x);
                    mp.erase(x);
                } 
                sum -= x;
            }
        }else if(ch == 3){
            char ch;cin>>ch;
            if(!st.empty()) cout<<*st.begin()<<endl;
            else cout<<(-1)<<endl;
        }else if(ch == 4){
            char ch;cin>>ch;
            if(!st.empty()) cout<<*st.rbegin()<<endl;
            else cout<<(-1)<<endl;
        }else{
            char ch;cin>>ch;
            if(!st.empty()) cout<<sum<<endl;
            else cout<<0<<endl;
        }
    }
}

signed main(){
    IOS
    solve();
    return 0;
}