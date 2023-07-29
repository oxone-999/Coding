//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const int MOD = 1e9+7;

void solve()
{
    string s;
    getline(cin,s);
    string str;
    for(auto it:s){
        int num = it;
        if(num >=97 && num <=122){
            str.push_back(it);
        }
    }
    string r = str;
    reverse(r.begin(),r.end());
    // cout<<r<<" "<<str<<" ";
    if(str == r) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    string s;
    getline(cin,s);
    while(t--) solve();
    return 0;
}