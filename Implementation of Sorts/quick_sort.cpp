#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

int partition (vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
 
    while(i<j){
        while(arr[i] <= pivot) i++;
        while(arr[j] > pivot) j--;
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j],arr[low]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void solve()
{
    // int n;
    // cin>>n;
    // vector<int> A(n);
    // for(auto &it:A){
    //     cin>>it;
    // }

    // quickSort(A,0,n-1);

    // for(auto it:A){
    //     cout<<it<<" ";
    // }

    vector<int> vec;
    stack<int> st;
    for(int i=0;i<129;i++){
        vec.push_back(i);
        // st.push(i);
    }
    vec.resize(128);
    cout<<vec.capacity()<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    solve();
    return 0;
}