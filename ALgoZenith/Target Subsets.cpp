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
lli n,x;

void func(vector<lli> &vec,lli j,vector<lli> &s,lli &sum,lli par){
    s.push_back(sum);

    for(lli i=j+1;i<(n+par)/2;i++){
        sum += vec[i];
        func(vec,i,s,sum,par);
        sum -= vec[i];
    }
}

void solve()
{
    cin>>n>>x;

    vector<lli> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }
    vector<lli> v1;
    vector<lli> v2;

    for(lli i=0;i<n/2;i++){
        v1.push_back(vec[i]);
    }

    for(lli i=n/2;i<n;i++){
        v2.push_back(vec[i]);
    }
    // pr(v1);
    // pr(v2);

    vector<lli> s1;
    vector<lli> s2;

    lli i = -1;
    lli sum = 0;
    func(v1,i,s1,sum,0);
    sum = 0;
    i = -1;
    func(v2,i,s2,sum,1);

    sort(all(s1));
    sort(all(s2));

    lli ans = 0;
    for(lli i=0;i<s1.size();i++){
        lli target = x-s1[i];
        lli ind = upper_bound(all(s2),target) - s2.begin();
        ans += ind;
    }

    cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}