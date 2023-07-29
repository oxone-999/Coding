//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

#define debarr(a,n) cout<<#a<<" : ";for(lli i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(lli i=0;i<row;i++) {for(lli j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {lli idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}

const lli mod = 1e9+7;
lli n,m;

void solve()
{
    cin>>n>>m;

    vector<lli> adj[n+1];

    for(lli i=0;i<m;i++){
        lli u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vector<lli> indegree(n+1,0);

    for(lli i=1;i<=n;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }

    lli dp[n+1];

    for(lli i=1;i<=n;i++){
        dp[i] = 0;
    }

    dp[1] = 1;

    queue<lli> q;

    for(lli i=1;i<=n;i++){
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        lli node = q.front();
        q.pop();

        for(auto it:adj[node]){
            indegree[it]--;
            dp[it] += dp[node];
            dp[it] %= mod;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }

    cout<<dp[n]%mod<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}