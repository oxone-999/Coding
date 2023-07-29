// Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.
// You may assume that the array is non-empty and the majority element always exist in the array.

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

int majorityElement(const vector<int> &A) {
    int anyElement = A[0];
    int count = 1;

    for(int i=1;i<A.size();i++)
    {
        if(A[i] == anyElement) count++;
        else count--;

        if(count == 0)
        {
            anyElement = A[i];
            count = 1;
        }
    }
    return anyElement;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> A(n);
    for(auto &it:A){
        cin>>it;
    }
    cout<<majorityElement(A)<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}