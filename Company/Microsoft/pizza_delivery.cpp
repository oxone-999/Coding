#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

double distance(pair<int,int> a,pair<int,int> b){
    double ans = sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
    return ans;
}

void solve()
{
    double s;
    int n;
    cin>>s>>n;

    vector<pair<int,double>> adj[n+1];
    vector<pair<int,int>> vec;

    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        vec.push_back({x,y});
    }
    double ans = -1e9;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double dist = distance(vec[i],vec[j]);
            double time = dist/s;
            ans = max(ans,time);
        }
    }
    cout<<fixed<<setprecision(6);
    cout<<ans<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    solve();
    return 0;
}