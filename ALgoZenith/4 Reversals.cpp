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
    string s,t;
    cin>>s>>t;

    int n = s.size();
    int m = t.size();

    if(n != m){
        cout<<"NO"<<endl;
        return;
    }

    set<string> s1;
    set<string> s2;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            string f = s;
            reverse(f.begin()+i,f.begin()+j+1);
            s1.insert(f);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            string f = t;
            reverse(f.begin()+i,f.begin()+j+1);
            s2.insert(f);
        }
    }

    set<string> t1;
    set<string> t2;

    for(auto it:s1){
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                string f = it;
                reverse(f.begin()+i,f.begin()+j+1);
                t1.insert(f);
            }
        }
    }

    for(auto it:s2){
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                string f = it;
                reverse(f.begin()+i,f.begin()+j+1);
                t2.insert(f);
            }
        }
    }

    for(auto it:t1){
        if(t2.find(it) != t2.end()){
            cout<<"YES"<<endl;
            return;
        }
    }
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}