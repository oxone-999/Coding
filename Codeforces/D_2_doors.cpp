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
    int n,q;
    cin>>n>>q;

    if(q == 0){
        vector<int> v(n,0);
        for(auto it:v){
            cout<<it<<endl;
        }
        return;
    }
    int w = (1<<30)-1;
    vector<int> vec(n,0);
    map<int,int> mp;
    for(int i=0;i<q;i++){
        int x,y,z;
        cin>>x>>y>>z;
        
        if(x == y){
            vec[x-1] = z;
            mp[x-1]++;
        } 
        else{
            mp[x-1]++;
            mp[y-1]++;
            if(vec[x-1] == 0) vec[x-1] = (z&w);
            else vec[x-1] = (vec[x-1]&z);
            if(vec[y-1] == 0) vec[y-1] = (z&w);
            else vec[y-1] = (vec[y-1]&z);
        }
    }
    for(auto it:mp){
        if(it.second > 1){
            vec[it.first] = 0;
        }
    }

    for(auto it:vec){
        cout<<it<<" ";
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
solve();
return 0;
}