//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;
lli inv = 0;

vector<lli> merge(vector<lli> &v1, vector<lli> &v2){
    vector<lli> final;
    lli n = v1.size();
    lli m = v2.size();

    lli i=0;
    lli j=0;

    while(i < n && j < m){
        if(v1[i] <= v2[j]){
            final.push_back(v1[i++]);
        }else{
            final.push_back(v2[j++]);
            inv += n-i;
        }
    }

    while(i < n){
        final.push_back(v1[i++]);
    }

    while(j < m){
        final.push_back(v2[j++]);
    }

    return final;
}

vector<lli> mergeSort(vector<lli> &vec){
    lli n = vec.size();
    if(n <= 1){
        return vec;
    }
    lli mid = n/2;
    vector<lli> v1;
    vector<lli> v2;

    for(lli i=0;i<n;i++){
        if(i < mid){
            v1.push_back(vec[i]);
        }else v2.push_back(vec[i]);
    }

    v1 = mergeSort(v1);
    v2 = mergeSort(v2);

    vector<lli> final = merge(v1,v2);
    return final;
}

void solve()
{
    lli n;
    cin>>n;    
    vector<lli> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    inv = 0;
    mergeSort(vec);

    cout<<inv<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}