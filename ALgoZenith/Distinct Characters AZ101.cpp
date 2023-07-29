//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

// 1≤ T ≤ 105

// 1≤ |S| ≤ 105

// 1≤ Q ≤ 106

// 1≤ Ai ≤ 105
 
void solve()
{
    string s;
    cin>>s;

    int n = s.size();

    int q;
    cin>>q;

    unordered_map<int,set<int>> mp;
    unordered_map<int,char> mp2;

    for(int i=0;i<n;i++){
        mp[s[i]-'a'].insert(i);
        mp2[i] = s[i];
    }

    for(int i=0;i<q;i++){
        int ch;
        cin>>ch;
        if(ch == 1){
            int i;
            char c;
            cin>>i>>c;
            i--;

            char ch = mp2[i];
            mp[ch-'a'].erase(i);
            mp[c-'a'].insert(i);
            mp2[i] = c;
        }else{
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            int ans = 0;
            for(int j=0;j<26;j++){
                set<int> d = mp[j];
                if(d.empty()) continue;
                int a = *d.begin();
                int b = *d.rbegin();
                if((a <= l && b >= l) || (a <= r && b >= r) || (l < a && b < r) || (a <= l && r <= b)){
                    ans++;
                }
            }
            cout<<ans<<endl;
        }
    }
}

signed main(){
    IOS
    int t=1;cin>>t;while(t--) solve();
    return 0;
}