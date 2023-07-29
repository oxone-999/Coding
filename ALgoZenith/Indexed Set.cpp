//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

//Policy Based Data Structure Header Files
//*p.find_by_order(3)
//p.order_of_key(7)

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using pbds_ordered_set = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using pbds_multi_set = tree<T, null_type, less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>;

const lli mod = 1e9+7;

void solve()
{
    int n;
    cin>>n;

    pbds_ordered_set<int> st;

    while(n--){
        string s;
        int x;
        cin>>s>>x;

        if(s == "add"){
            st.insert(x);
        }else if(s == "find"){
            if(x >= 0 && x < st.size()) cout<<(*st.find_by_order(x))<<endl;
            else cout<<(-1)<<endl;
        }else if(s == "findpos"){
            cout<<st.order_of_key(x)<<endl;
        }else{
            if(st.find(x) != st.end()) st.erase(x);
        }
    }
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}