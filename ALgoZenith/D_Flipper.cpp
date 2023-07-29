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
    int n;
    cin>>n;
    
    vector<int> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }   

    int mx = INT_MIN;
    int ind = 0;
    for(int i=1;i<n;i++){
        if(mx < vec[i]){
            mx = vec[i];
            ind = i;
        }
    }

    if(ind == n-1){
        int c = n-1;
        for(int i=n-2;i>=0;i--){
            if(vec[i] < vec[0]){
                break;
            }
            c--;
        }

        vector<int> v1;
        for(int i=c;i<=ind;i++){
            v1.push_back(vec[i]);
        }

        // pr(v1);

        reverse(all(v1));

        vector<int> v2;
        for(int i=0;i<c;i++){
            v2.push_back(vec[i]);
        }

        for(auto it:v2){
            v1.push_back(it);
        }

        for(auto it:v1){
            cout<<it<<" ";
        }
        cout<<endl;
    }else {
        vector<int> v2;

        for(int i=ind;i<n;i++){
            v2.push_back(vec[i]);
        }

        int d = ind-1;
        for(int i=ind-2;i>=0;i--){
            if(vec[i] <= vec[0]){
                break;
            }
            d = i;
        }

        vector<int> v;
        for(int i=d;i<ind;i++){
            v.push_back(vec[i]);
        }

        // pr(d,v);
        reverse(all(v));

        vector<int> v1;
        for(int i=0;i<d;i++){
            v1.push_back(vec[i]);
        }
        // pr(v1);

        for(auto it:v){
            v2.push_back(it);
        }

        for(auto it:v1){
            v2.push_back(it);
        }

        for(auto it:v2){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}