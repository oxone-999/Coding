// Find the contiguous subarray within an array (containing at least one number) which has the largest product.

// Return an integer corresponding to the maximum product possible.

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

int maxProduct(const vector<int> &A) {
    int res = INT_MIN;
    for(int i=0;i<A.size();i++)
    {
        res = max(res,A[i]);
    }
    int currMax=1,currMin=1;
    for(int i=0;i<A.size();i++)
    {
        if(A[i] == 0)
        {
            currMax = 1;
            currMin = 1;
            continue;
        } 
        int temp = currMax * A[i];
        currMax = max(temp,max(currMin*A[i],A[i])); // max(currMax*A[i], currMin*A[i], A[i])
        currMin = min(temp,min(currMin*A[i],A[i])); // min(currMax*A[i], currMin*A[i], A[i])
        res = max(res,currMax);
    }
    return res;
}


void solve()
{
    int n;
    cin>>n;
    vector<int> A(n);
    for(auto &it:A){
        cin>>it;
    }
    cout<<maxProduct(A)<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}