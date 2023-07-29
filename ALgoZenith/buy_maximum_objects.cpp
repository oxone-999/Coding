// There are N objects, and each object has some price. The price of ith object is Ai.
// You have been asked Q queries. In each query, you have been given total money M, and find the maximum number of 
// objects that you can buy.

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

    vector<int> vec(n);
    for(auto &it:vec){
        cin>>it;
    }
    sort(vec.begin(),vec.end());
    vector<int> v(n);

    int sum = 0;
    for(int i=0;i<n;i++){
        sum += vec[i];
        v[i] = sum;
    }

    for(int i=0;i<q;i++){
        int m;
        cin>>m;
        auto ind = upper_bound(v.begin(),v.end(),m);
        ind--;
        if(v[ind-v.begin()] <= m){
            cout<<((ind-v.begin()) + 1)<<endl;
        }else{
            cout<<0<<endl;
        }
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;while(t--) solve();
    return 0;
}