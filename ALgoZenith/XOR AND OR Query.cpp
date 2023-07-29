//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}

void solve()
{
    lli n;
    cin>>n;

    vector<lli> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    vector<vector<pair<lli,lli>>> pre(n+1,vector<pair<lli,lli>>(31));

    for(lli i=1;i<n+1;i++){
        for(lli j=0;j<31;j++){
            lli ones = pre[i-1][j].first;
            lli zeros = pre[i-1][j].second;
            if(vec[i-1] & (1<<j)) ones++;
            else zeros++;
            pre[i][j] = {ones,zeros};
        }
    }

    // pr(pre);

    lli q;
    cin>>q;

    for(lli i=0;i<q;i++){
        lli l,r;
        cin>>l>>r;

        vector<pair<lli,lli>> p(31);
        for(lli j=0;j<31;j++){
            p[j] = {pre[r][j].first - pre[l-1][j].first, pre[r][j].second - pre[l-1][j].second};
        }

        // pr(p);

        lli x1(0),x2(0),x3(0);

        for(lli j=0;j<31;j++){
            if(p[j].first < p[j].second){
                x1 |= (1<<j);
            }
            if(p[j].first != 0){
                x2 |= (1<<j);
            }
            if(p[j].second != 0){
                x3 |= (1<<j);
            }
        }

        cout<<x1+x2+x3<<endl;
    }
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}