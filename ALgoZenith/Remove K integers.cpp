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

void solve()
{
    lli n,k;
    cin>>n>>k;

    vector<lli> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    vector<lli> v(n-1);

    for(lli i=0;i<n-1;i++){
        v[i] = vec[i+1]-vec[i];
    }

    // pr(v);

    lli i=0;
    lli j=0;
    lli ans = LLONG_MAX;
    deque<lli> q;

    while(j < n-1){
        while(!q.empty() && q.back() < v[j]){
            q.pop_back();
        }
        q.push_back(v[j]);
        if(j-i+1 == n-k-1){
            ans = min(ans,q.front());
            if(v[i] == q.front()){
                q.pop_front();
            }
            i++;
        }
        j++;
    }

    cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}