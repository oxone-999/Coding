#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

void merge(vector<int> &arr,vector<int> &temp, int left, int mid, int right)
{
    int i, j, k;
 
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }else {
            temp[k++] = arr[j++];
        }
    }
 
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    while (j <= right)
        temp[k++] = arr[j++];
 
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
}

void _mergeSort(vector<int> &arr,vector<int> &temp, int left, int right)
{
    int mid;
    if (right > left) {
        mid = (right + left) / 2;
 
        _mergeSort(arr, temp, left, mid);
        _mergeSort(arr, temp, mid + 1, right);
 
        merge(arr, temp, left, mid + 1, right);
    }
}

void solve()
{
    int n;
    cin>>n;
    vector<int> A(n);
    vector<int> temp(n);
    for(auto &it:A){
        cin>>it;
    }

    _mergeSort(A,temp,0,n-1);   
    
    for(auto it:A){
        cout<<it<<" ";
    }
    cout<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    solve();
    return 0;
}