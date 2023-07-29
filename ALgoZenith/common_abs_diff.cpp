// You are given an array A of N integers and an integer K. Find the number of pairs (i, j) such that i < j and abs(Ai - Aj) = K

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

void solve()
{
    int n,k;
    cin>>n>>k;

    map<int,int> mp;
    vector<int> vec(n);
    for(auto &it:vec){
        cin>>it;
        mp[it]++;
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        mp[vec[i]]--;
        if(mp[vec[i]] == 0) mp.erase(vec[i]);
        // pr(mp);       
        if(mp.count(vec[i]+k))
            cnt += mp[vec[i]+k];
        if(mp.count(vec[i]-k))
            cnt += mp[vec[i]-k];
    }
    cout<<cnt<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}