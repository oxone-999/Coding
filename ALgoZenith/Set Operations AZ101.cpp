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
    int n,m;
    cin>>n>>m;
    
    set<int> s1;
    for(int i =0;i<n;i++){
        int x;cin>>x;
        s1.insert(x);
    }
    set<int> s2;
    for(int i=0;i<m;i++){
        int x;cin>>x;
        s2.insert(x);
    }

    set<int> s3 = s1;
    for(auto it:s2){
        s3.insert(it);
    }

    set<int> s4;
    set<int> s5 = s1;

    for(auto it:s2){
        if(s1.count(it)){
            s4.insert(it);
        }
    }

    for(auto it:s4){
        if(s5.count(it)){
            s5.erase(it);
        }
    }

    for(auto it:s3){
        cout<<it<<" ";
    }cout<<endl;
    for(auto it:s4){
        cout<<it<<" ";
    }cout<<endl;
    for(auto it:s5){
        cout<<it<<" ";
    }cout<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}