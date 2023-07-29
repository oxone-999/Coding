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

    map<char,int> mp;

    for(auto it:s){
        mp[it]++;
    }

    string t;
    string p;
    int od = INT_MAX;
    for(int i=0;i<26;i++){
        char ch = 'a' + i;
        string u = string(mp[ch]/2,ch);
        t += u;
        if(mp[ch] % 2 != 0 && ch-'a' < od) od = ch-'a';
    }
    string c = t;
    reverse(all(c));
    if(od != INT_MAX) t.push_back(od+'a');
    t += c;
    cout<<t<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}