//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

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

lli par[200100];
lli dep[200100];
lli vec[200100];
vector<vector<lli>> adj(200100);
lli D = 0;

void dfs2(lli node,lli pp){
    lli num = 0;
    if(dep[node] == D){
        vec[node] = 1;
        return;
    } 
    for(auto it:adj[node]){
        if(it != pp){
            dfs2(it,node);
            num += vec[it];
        }
    }
    vec[node] = num;
}

void dfs(lli node,lli pp,lli dp){
    par[node] = pp;
    dep[node] = dp;
    for(auto it:adj[node]){
        if(it != pp){
            dfs(it,node,dp+1);
        }
    }
}

void solve()
{
    lli n;
    cin>>n;

    for(lli i=0;i<n-1;i++){
        lli u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(n == 1 || n == 2 || n == 3){
        cout<<1<<endl;
        return;
    }

    dfs(1,0,0);

    lli maxCh = 1;

    for(lli i=2;i<=n;i++){
        if(dep[i] > dep[maxCh]){
            maxCh = i;
        }
    }
    dfs(maxCh,0,0);

    for(lli i=1;i<=n;i++){
        if(dep[i] > dep[maxCh]){
            maxCh = i;
        }
    }
    lli maxDep = dep[maxCh];

    D = maxDep/2;
    lli ans = maxCh;
    while(D--){
        ans = par[ans];
    }
    D = maxDep/2;

    lli res = 0;

    if(maxDep % 2 == 0){
        vector<lli> v = adj[ans];

        dfs(ans,0,0);
        dfs2(ans,0);

        vector<lli> c;
        for(auto it:v){
            if(vec[it] != 0) c.push_back(vec[it]);
        }

        lli sum = 0;

        for(auto it:c){
            sum += it;
        }

        for(lli i=0;i<c.size();i++){
            sum -= c[i];
            res += c[i]*sum;
        }
        cout<<res<<endl;
    }else{
        // pr(ans,par[ans]);
        lli sec = par[ans];
        vector<lli> v = adj[ans];

        dfs(ans,sec,0);
        dfs2(ans,sec);

        lli c = 0;
        for(auto it:v){
            if(vec[it] != 0) c += vec[it];
        }

        memset(vec,0,sizeof(vec));

        vector<lli> v2 = adj[sec];

        dfs(sec,ans,0);
        dfs2(sec,ans);

        lli c2 = 0;
        for(auto it:v2){
            if(vec[it] != 0) c2 += vec[it];
        }

        lli res = c*c2;
        cout<<res<<endl;
    }
}

signed main(){
    IOS
    solve();
    return 0;
}