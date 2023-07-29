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
    int m;
    cin>>m;

    int n = m*(m+1)/2;    
    vector<int> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }
    sort(all(vec));
    vector<vector<int>> vec2;
    int x = 0;
    int j=0;
    for(int i=0;i<m;i++){
        x++;
        int c = x;
        vector<int> v;
        while(c--){
            v.push_back(vec[j]);
            j++;
        }
        vec2.push_back(v);
    }
    for(int i=0;i<vec2.size()-1;i++){
        for(int j=0;j<vec2[i].size();j++){
            if(vec2[i][j] >= vec2[i+1][j] || vec2[i][j] >= vec2[i+1][j+1]){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}