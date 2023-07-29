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
    vector<int> vec;
    for(int i=0;i<n;i++){
        vec.push_back(i+1);
    }

    do{
        for(auto it:vec){
            cout<<it<<" ";
        }cout<<endl;
    }while(next_permutation(all(vec)));
}

signed main(){
    IOS
    solve();
    return 0;
}