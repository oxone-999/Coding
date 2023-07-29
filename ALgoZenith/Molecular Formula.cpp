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
    string s;
    cin>>s;

    s.insert(0,"(");
    s.push_back(')');

    cout<<s<<endl;

    stack<pair<string,int>> st;
    string str;
    for(auto it:s){
        int num = it;
        if(num > 65 && num <= 96){
            st.push({str,1});
            str.clear();
        }else{
            str.push_back(it);
        } 
    }
}

signed main(){
    IOS
    solve();
    return 0;
}