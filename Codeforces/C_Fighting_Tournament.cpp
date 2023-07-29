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
    int n,q;
    cin>>n>>q;

    vector<int> vec(n+1);
    vector<int> vec2;
    deque<pair<int,int>> dq;

    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        vec2.push_back(x);
        dq.push_back({i,x});
    }

    vector<pair<pair<int,int>,int>> vec3;
    for(int i=0;i<q;i++){
        int j,k;
        cin>>j>>k;
        vec3.push_back({{k,j},i});
    }
    sort(vec3.begin(),vec3.end());
    int i = 0;
    vector<pair<int,int>> ans;

    int cnt = 0;
    while(dq.front().second != n){
        int i_f = dq.front().first;
        int f = dq.front().second;
        dq.pop_front();
        int i_s = dq.front().first;
        int s = dq.front().second;
        dq.pop_front();
        if(f > s) {
            vec[i_f]++;
            dq.push_front({i_f,f});
            dq.push_back({i_s,s});
        }else {
            vec[i_s]++;
            dq.push_front({i_s,s});
            dq.push_back({i_f,f});
        }
        cnt++;
        if(vec3[i].first.first == cnt){
            ans.push_back({vec[vec3[i].first.second],vec3[i].second});
            i++;
        }
    }
    for(int j = i;j<vec3.size();j++){
        if(vec[vec3[j].first.second] == n) ans.push_back({vec[vec3[j].first.second]+vec3[j].first.first-cnt,vec3[j].second});
        else ans.push_back({vec[vec3[j].first.second],vec3[j].second});
    }
    sort(ans.begin(),ans.end(),[](pair<int,int> &a,pair<int,int> &b)->bool{
        if(a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    });
    for(auto it:ans){
        cout<<it.first<<endl;
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
int t=1;cin>>t;while(t--) solve();
return 0;
}