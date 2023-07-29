#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

int canJump(vector<int> &A) {
    int reach = 0;
    int n = A.size();
    for(int i = 0; i<n; i++)
    {
        if(reach < i)
            return 0;
        reach = max(reach, i+A[i]);
    }
    if(reach >= n-1)
        return 1;
    return 0;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> A(n);
    for(auto &it:A){
        cin>>it;
    }
    cout<<canJump(A)<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}
