// You are given a string S. You are given Q queries of two types, asking the number of distinct characters in the 
// range [L, R] and changing the i-th character to c. (1-based indexing)

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
    int n = s.size();

    set<int> v[26];
    for(int i=0;i<n;i++){
        v[s[i]-'a'].insert(i);
    }

    // for(int i=0;i<26;i++){
    //     char ch = i+'a';
    //     if(v[i].size()) cout<<ch<<" : ";
    //     for(auto &it:v[i]){
    //         cout<<it<<" ";
    //     }
    //     if(v[i].size()) cout<<endl;
    // }

    int q;
    cin>>q;

    for(int i=0;i<q;i++){
        int ch;
        cin>>ch;
        if(ch == 1){
            int x;
            char c;
            cin>>x>>c;
            char d = s[x-1];
            s[x-1] = c;
            v[c-'a'].insert(x-1);
            v[d-'a'].erase(x-1);
        }else{
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            int cnt = 0;
            for(int k = 0;k<26;k++)
            {
                if(v[k].empty())
                    continue;
                auto val = v[k].rbegin();
                if((*val) < l)
                    continue;
                auto it = v[k].lower_bound(l);
                if((*it) <= r)
                    cnt++;  
            }
            cout<<cnt<<endl;
        }
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}