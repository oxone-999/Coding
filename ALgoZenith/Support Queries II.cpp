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
    multiset<lli> st;
    multiset<lli> st2;

    lli n,k;
    cin>>n>>k;
    lli sum = 0;

    while(n--){
        lli ch;
        cin>>ch;

        if(ch == 1){
            lli x;
            cin>>x;
            st.insert(x);
            sum += x;
            if(st.size() > k){
                int y = *st.begin();
                st.erase(st.find(y));
                sum -= y;
                st2.insert(y);
            }
        }else if(ch == 2){
            lli x;
            cin>>x;
            if(st2.count(x)){
                st2.erase(st2.find(x));
            }else if(st.count(x)){
                sum -= x;
                st.erase(st.find(x));
                if(!st2.empty()){
                    int it = *st2.rbegin();
                    st.insert(it);
                    sum += it;
                    st2.erase(st2.find(it));
                } 
            }
        }else if(ch == 3){
            char ch1;cin>>ch1;
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