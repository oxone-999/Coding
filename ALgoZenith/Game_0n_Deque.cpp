// You recently learnt to use the C++ STL deque and decided to play a game on it. You are given a deque with N elements. You take the first two 
// elements of the deque, pop them and push the larger of the two in the front and the smaller at the back of the deque. You are given Q queries, 
// asking the first two elements of the deque you will take on the X-th operation. 

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
    int n,q;
    cin>>n>>q;

    vector<int> vec(n);
    deque<int> dq;

    for(auto &it:vec){
        cin>>it;
        dq.push_back(it);
    }
    int ind = 0;
    int mx = INT_MIN;
    for(int i=0;i<n;i++){
        if(mx < vec[i]){
            ind = i;
            mx = vec[i];
        }
    }
    vector<pair<int,int>> v;

    for(int i=0;i<=ind;i++){
        int n1 = dq.front();
        dq.pop_front();
        int n2 = dq.front();
        dq.pop_front();
        v.push_back({n1,n2});
        dq.push_front(max(n1,n2));
        dq.push_back(min(n1,n2));
    }
    vector<int> v2;
    while(!dq.empty()){
        v2.push_back(dq.front());
        dq.pop_front();
    }

    for(int i=0;i<n-1;i++){
        v.push_back({mx,v2[i+1]});
    }

    // pr(v);

    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        x--;
        if(x<ind) x %= ind;
        else x = (x-ind) % (n-1) + ind;
        cout<<v[x].first<<" "<<v[x].second<<endl;
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}