#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

map<int,int> mp;

void printAllSubsequences(vector<string> &vec, string ip, string op){
    if(ip.size() == 0){
        vec.push_back(op);
        return "";
    }

    string dp;
    dp += ip + "_" + op;
    
    // if(mp.count(dp)) return mp[dp];

    string op1 = op;

    op1.push_back(ip.back());
    ip.pop_back();

    printAllSubsequences(vec,ip,op);
    printAllSubsequences(vec,ip,op1);
}

void solve()
{
    string ip;
    cin>>ip;
    reverse(ip.begin(),ip.end());

    vector<string> vec;

    string op = "";
    printAllSubsequences(vec,ip,op);

    sort(vec.begin(),vec.end());
    
    for(auto it:vec){
        cout<<it<<endl;
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    solve();
    return 0;
}