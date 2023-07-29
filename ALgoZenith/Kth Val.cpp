//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using lli = long long;
const lli mod = 1e9+7;
const lli N = 1e5+5;

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
    lli n,m,q;
    cin>>n>>m>>q;
    
    map<lli,lli> mp1;
    map<lli,lli> mp2;

    vector<lli> vec(n,0);
    vector<lli> freq(n,0);
    map<lli,lli> mp3;

    for(auto &it:vec) cin>>it;

    set<lli> a(vec.begin(),vec.end());
    vector<lli> b{a.begin(),a.end()};

    for(lli i=0;i<m;i++){
        lli l,r;
        cin>>l>>r;
        l--;
        r--;
        mp1[l]++;
        mp2[r]++;
    }

    lli x = 0;
    for(lli i=0;i<n;i++){
        x += mp1[i];
        freq[i] = x;
        x -= mp2[i];
    }

    for(lli i=0;i<n;i++){
       mp3[vec[i]] += freq[i]; 
    }

    vector<pair<lli,lli>> v;

    for(auto it:b){
        v.push_back({it,mp3[it]});
    }

    sort(v.begin(),v.end());

    vector<lli> xv;
    vector<lli> y;

    for(auto it:v){
        xv.push_back(it.first);
        y.push_back(it.second);
    }
    lli size = y.size();
    for(lli i=1;i<size;i++){
        y[i] += y[i-1];
    }

    for(lli i=0;i<q;i++){
        lli k;
        cin>>k;

        lli ind = lower_bound(y.begin(),y.end(),k) - y.begin();
        if(ind == size) cout<<(-1)<<" ";
        else cout<<xv[ind]<<" ";
    }cout<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}