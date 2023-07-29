// Given an integer array A of size N consisting of unique integers from 1 to N. You can swap any two integers atmost B times.

// Return the largest lexicographical value array that can be created by executing atmost B swaps.

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

vector<int> solve(vector<int> &A, int k) {
    int n = A.size();
    
    int pos[n + 1];
 
    for (int i = 0; i < n; ++i)
        pos[A[i]] = i;
 
    for (int i = 0; i < n && k; ++i) {
        if (A[i] == n - i)
            continue;
 
        int temp = pos[n - i];
 
        pos[A[i]] = pos[n - i];
        pos[n - i] = i;
 
        swap(A[temp], A[i]);
        --k;
    }
    
    return A;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    vector<int> B;
    int k;
    vector<int> A = solve(B,k);
    return 0;
}

