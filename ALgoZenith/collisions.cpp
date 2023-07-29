// There are N balls on the X-axis and M balls on the Y-axis. At the time, t=0, each ball on X-axis is thrown parallel 
// to the Y-axis in the positive Y direction. Similarly, each ball on Y-axis is thrown parallel to the X-axis in the 
// positive X direction. At any time, if two balls collide, they disappear. A collision can only happen between the 
// ball thrown from X-axis and the ball thrown from Y-axis. No two balls from X-axis or Y-axis can collide. A ball 
// can take part in at max one collision. You have to find the total number of collisions. 

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
    int n,m;
    cin>>n>>m;
    map<int,int> mp;
    map<int,int> mp2;

    for(int i=0;i<n;i++){
        int x,u;
        cin>>x>>u;
        int time = x*u;
        mp[time]++;
    }

    for(int i=0;i<m;i++){
        int y,v;
        cin>>y>>v;
        int time = y*v;
        mp2[time]++;
    }
    int cnt = 0;
    for(auto it:mp){
        if(mp2.count(it.first)){
            cnt += min(it.second,mp2[it.first]);
        }
    }
    cout<<cnt<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}