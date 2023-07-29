// Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

// Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) 
// of the characters without disturbing the relative positions of the remaining characters. (ie, “ACE” is a subsequence of “ABCDE” 
// while “AEC” is not).

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

int numDistinct(string A, string B) {
    if(B.size()>A.size()) return 0;
    if(A==B) return 1;
    int n = A.size();
    int m = B.size();
    int t[m+1][n+1];
    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++){
            if(i==0) t[i][j] = 1;
            else if(j==0 && i!=0) t[i][j] = 0;
        }
    }
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(B[i-1] == A[j-1]) t[i][j] = t[i-1][j-1] + t[i][j-1]; 
            else t[i][j] = t[i][j-1];
        }
    }
    return t[m][n];
}

void solve()
{
    string A,B;
    cin>>A>>B;
    cout<<numDistinct(A,B)<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}