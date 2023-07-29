#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

void selection_Sort(vector<int> &A){
    int n = A.size();

    for(int i=0;i<n;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(A[j]<[min]){
                min = j;
            }
        }
        if(min != i){
            swap(A[min],A[j]);
        }
    }
}

void solve()
{
    int n;
    cin>>n;

    vector<int> A(n);
    for(auto &it:A){
        cin>>it;
    }
    selection_Sort(A);
    for(auto it:A){
        cout<<it<<" ";
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}