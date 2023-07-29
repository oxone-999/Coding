// There are N children standing in a line. Each child is assigned a rating value.

// You are giving candies to these children subjected to the following requirements:

// 1. Each child must have at least one candy.
// 2. Children with a higher rating get more candies than their neighbors.
// What is the minimum candies you must give?

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

int candy(vector<int> &A) {
    vector<int> left(A.size(),1);
    vector<int> right(A.size(),1);
    
    for(int i=1;i<A.size();i++)
    {
        if(A[i]>A[i-1]) left[i] = left[i-1] + 1;
    }
    for(int i=A.size()-2;i>=0;i--)
    {
        if(A[i+1]<A[i]) right[i] = right[i+1] + 1;
    }
    int sum = 0;
    for(int i=0;i<A.size();i++)
    {
        sum += max(left[i],right[i]);
    }
    return sum;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int n;cin>>n;
    vector<int> A;
    for(auto &it:A) cin>>it;
    cout<<candy(A);
    return 0;
}
