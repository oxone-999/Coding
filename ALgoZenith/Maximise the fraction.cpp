//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

bool check(long double mid,int n,int k,vector<long double> &A, vector<long double> &B){
    priority_queue<long double> pq;

    for(int i=0;i<n;i++){
        pq.push(A[i]-mid*B[i]);
    }

    long double sum = 0;
    while(k--){
        sum += pq.top();
        pq.pop();
    }
    if(sum > 0) return 1;
    else return 0;
}

void solve()
{
    int n,k;
    cin>>n>>k;

    vector<long double> A(n,0);
    vector<long double> B(n,0);

    for(auto &it:A){
        cin>>it;
    }

    for(auto &it:B){
        cin>>it;
    }

    long double eps = 1e-9;
    long double l = 0;
    long double r = 1e10;

    while(abs(l-r) >= eps){
        long double mid = (l+r)/2;
        if(check(mid,n,k,A,B)){
            l = mid;
        }else r = mid;
    }

    long double ans = (l+r)/2;
    cout<<fixed<<setprecision(6)<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}