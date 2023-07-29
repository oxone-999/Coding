//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

bool check(int mid,vector<int> &vec){
    if(vec[mid+1] < vec[mid]) return 1;
    else return 0;
}

int bs(vector<int> &vec,int st,int en,int k){
    int ans = 0;
    while(st<=en){
        int mid = st + (en-st)/2;
        if(vec[mid] <= k){
            ans = mid;
            en = mid-1;
        }else st = mid+1;
    }
    return ans;
}

int bs1(vector<int> &vec,int st,int en,int k){
    int ans = 0;
    while(st<=en){
        int mid = st + (en-st)/2;
        if(vec[mid] >= k){
            ans = mid;
            en = mid-1;
        }else st = mid+1;
    }
    return ans;
}

void solve()
{
    int n,q;
    cin>>n>>q;
    
    vector<int> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    int st = 0;
    int en = n-1;
    int ans = 0;

    while(st<=en){
        int mid = en + (st-en)/2;
        if(check(mid,vec)){
            ans = mid;
            en = mid-1;
        }else st = mid+1;
    }

    for(int i=0;i<q;i++){
        int k;
        cin>>k;

        int ind = bs1(vec,0,ans-1,k);
        int ind2 = bs(vec,ans,n-1,k);

        // cout<<ind<<" "<<ind2<<endl;

        set<int> s;
        if(ind < n && vec[ind] == k) s.insert(ind+1);
        if(ind2 < n && vec[ind2] == k) s.insert(ind2+1);

        for(auto it:s) cout<<it<<" ";
        cout<<endl;
    }
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}