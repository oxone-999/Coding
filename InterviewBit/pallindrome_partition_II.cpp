// Given a string A, partition A such that every substring of the partition is a palindrome.

// Return the minimum cuts needed for a palindrome partitioning of A.

int t[502][502];

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

bool isPalindrome(string A,int i, int j)
{
    if(i==j) return true;
    while(i<j)
    {
        if(A[i] != A[j]) return false;
        i++;
        j--;
    }
    return true;
}

int solve(string A,int i,int j)
{
    if(i>=j) return 0;
    if(t[i][j] != -1) return t[i][j];
    if(isPalindrome(A,i,j)) return false;

    int mn = INT_MAX;

    for(int k=i;k<j;k++)
    {
        int temp,left,right;

        if(t[i][k] != -1) left = t[i][k];
        else
        {
            left = solve(A,i,k);
            t[i][k] = left;
        }
        if(t[k+1][j] != -1) right = t[k+1][j];
        else
        {
             right = solve(A,k+1,j);
             t[k+1][j] = right;
        }

        temp = left + right + 1;
        mn = min(temp,mn);
    }
    t[i][j] = mn;
    return t[i][j];
}

int minCut(string A) { // Matrix Chain Multiplication
    if(A.size() <= 1) return 0;
    memset(t,-1,sizeof(t));
    return solve(A,0,A.size()-1);
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    string A;cin>>A;cout<<minCut(A);return 0;
}