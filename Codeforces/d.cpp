#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

struct result{
    result(): output(){}
    int output[100];
};

struct result sort(int input1,int input2[]){
    result res;
    vector<pair<int,int>> ans;

    for(int i=0;i<input1;i++){
        int cnt = 0;
        int val = input2[i];
        while(val){
            val = val&(val-1);
            cnt++;
        }
        ans.push_back({cnt,input2[i]});
    }
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    for(int i=0;i<input1;i++){
        res.output[i] = ans[i].second;
    }
    return res;
}

void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    result res = sort(n,arr);
    for(int i=0;i<n;i++){
        cout<<res.output[i]<<" ";
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
solve();
return 0;
}