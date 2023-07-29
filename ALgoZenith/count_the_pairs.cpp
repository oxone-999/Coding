// You are given an array A of size N. You need to find the number of pairs (i, j) , i != j, such that A[i]+A[j] ≤ X.

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
    int n,k;
    cin>>n>>k;

    vector<int> vec(n);
    for(auto &it:vec){
        cin>>it;
    }
    sort(vec.begin(),vec.end());
    int cnt = 0;
    for(int i=0;i<n;i++){
        int st = i+1;
        int en = n-1;
        int target = k-vec[i];
        int res = -1;

        while(st<=en){
            int mid = st+(en-st)/2;
            if(vec[mid] <= target){
                res = mid;
                st = mid+1;
            }
            else en = mid-1;
        }

        if(res != -1){
            cnt += res-i;
        }
    }
    cout<<2*cnt<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}