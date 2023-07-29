//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define MOD 1e9
#define all(a) (a).begin(), (a).end()

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

void func(string str,multiset<char> st){
    if(str.empty() || str.back() != *st.begin()){
        str.push_back(*st.begin());
        st.erase(st.begin());
    }else{
        auto it = st.upper_bound(str.back());
        if(it == st.end())
        str.push_back(*it);
        st.erase(it);
    }
}


void solve()
{
    string s;
    cin>>s;

    int n = s.size();

    multiset<char> st;
    for(auto it:s){
        st.insert(it);
    }

    string str;

    func(str,st);
    


    cout<<str<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
return 0;
}