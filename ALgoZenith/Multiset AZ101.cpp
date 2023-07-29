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
    int n;
    cin>>n;

    multiset<int> mp;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s == "print" || s == "empty"){
            if(s == "empty") mp.clear();
            else{
                if(!mp.empty()){
                    for(auto it:mp){
                        cout<<it<<" ";
                    }
                }
                cout<<endl;
            }
        }else{
            int x;
            cin>>x;

            if(s == "add"){
                mp.insert(x);
            }else if(s == "erase"){
                if(mp.count(x)){
                    auto it = mp.find(x);
                    mp.erase(it);
                }
            }else if(s == "eraseall"){
                if(mp.count(x)){
                    mp.erase(x);
                }
            }else if(s == "find"){
                if(mp.count(x)) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }else if(s == "count"){
                cout<<mp.count(x)<<endl;
            }
        }
    }
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}