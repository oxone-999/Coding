// Given an array of integers, arr and a value k. We can perform an operation on the array in which we 
// can delete three consecutive elements, say arr[i], arr[i+1], arr[i+2] of the array. We can do this 
// operation only if arr[i+2]-arr[i+1]=arr[i+1]-arr[i]=k. Find the minimum possible length of the array 
// by doing this operation as many times as you wish. For example arr = [6, 8, 10, 12, 8, 10]. We can 
// firstly delete the subarray [8, 10, 12] to obtain arr = [6, 8, 10] then we can delete the whole array 
// [6, 8, 10] to obtain an array of  length 0. So the answer will be 0.

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
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    stack<int> s;
    int x = 0;
    for(int i=0;i<n;i++){
        if(!s.empty()){
            if(x == k){
                s.pop();
                s.pop();
                s.pop();
                x = 0;
            }
            else if(arr[i]-s.top()==k){
                x++;
            }
        }
        s.push(arr[i]);
    }
    cout<<s.size()<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    solve();
    return 0;
}