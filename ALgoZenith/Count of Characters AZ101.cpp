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

    vector<int> vec(26,0);

    for(auto it:s){
        if(isalpha(it)){
            it = tolower(it);
            vec[it-'a']++;
        }
    }

    for(auto it:vec){
        cout<<it<<" ";
    }cout<<endl;
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