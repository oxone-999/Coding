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
{           //  INSERTING UNSORTED ELEMENT INTO ITS CORRECT POSITION
    int n; //                 _________________                       
    cin>>n;//                 |                |
    vector<int> a(n);//       v                |
    for(auto &it:a){ // [sorted array | unsorted array]
        cin>>it;
    }   
    
    for(int i=0;i<n;i++){
        int temp = a[i];
        int j = i-1;
        while(j>=0 && a[j]>temp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }

    for(auto it:a){
        cout<<it<<" ";
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    solve();
    return 0;
}