//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int q;
    cin>>q;

    vector<int> vec;
    vec.clear();

    for(int i=0;i<q;i++){
        string ch;
        cin>>ch;

        if(ch == "add"){
            int x;
            cin>>x;
            vec.push_back(x);
        }else if(ch == "print"){
            int x;
            cin>>x;
            if(vec.empty() || x >= vec.size()) cout<<0<<endl;
            else cout<<vec[x]<<endl;
        }else if(ch == "clear"){
            vec.clear();
        }else if(ch == "remove"){
            if(!vec.empty()){
                vec.pop_back();
            }
        }
    }	
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}