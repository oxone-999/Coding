//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;
const lli N = 1e5+7;

void solve()
{
    int n;
    cin>>n;

    int x;
    cin>>x;

    set<int> st;

    for(int i=0;i<N;i++){
        st.insert(i);
    }

    while(n--){
        int y;
        cin>>y;

        if((*st.begin())%x == y%x){
            st.erase(*st.begin());
        }else if(st.count(y)){
            st.erase(y);
        }else if(st.count(y%x)){
            st.erase(y%x);
        }
        cout<<*st.begin()<<" ";
    }cout<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}