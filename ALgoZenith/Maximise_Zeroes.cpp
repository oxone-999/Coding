// You are given two arrays, A and B of N integers. You have to create a new array, Ci = Ai * D + Bi

// Find the maximum number of zeros you can get in the new array Ci taking an optimal value of D. (D is a real number)

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
    int n;
    cin>>n;

    vector<int> A(n);
    vector<int> B(n);

    for(int i=0;i<n;i++){
        cin>>A[i];
    }

    for(int i=0;i<n;i++){
        cin>>B[i];
    }
    int cnt = 0;
    map<double,int> mp;
    for(int i=0;i<n;i++){
        if(A[i] != 0){
            double x = (double)B[i]/(double)A[i];
            mp[x]++;
        }else if(A[i] == 0 && B[i] == 0){
            cnt++;
        }
    }
    int mx = INT_MIN;
    for(auto &it:mp){
        // cout<<it.first<<" "<<it.second<<endl;
        mx = max(mx,it.second);
    }

    int ans = 0;
    ans = cnt + mx;
    cout<<ans<<endl; 
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}