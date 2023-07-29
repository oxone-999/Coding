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
    string s;
    cin>>s;

    stack<char> st;
    int n = s.size();
    for(int i=0;i<n;i++){
        if(s[i] == ')'){
            if(!st.empty() && st.top() == '('){
                st.pop();
                continue;
            }
        }
        st.push(s[i]);
    }
    cout<<st.size()<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}