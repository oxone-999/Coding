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

    for(auto &it:s){
        if(isalpha(it)){
            if(isupper(it)) it = tolower(it);
            else it = toupper(it);
        }
    }
    cout<<s<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;
    string s;
    getline(cin,s);
    while(t--) solve();
    return 0;
}