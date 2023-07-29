#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9+7

int findValue(long long N, long long Y){
    return min(N, Y + 1 - N);
}

vector<int> retrieveArray(int N, long long K)
{
    vector<int> ans(N);
    set<int> s;
 
    for (int i = 1; i <= N; i++) 
        s.insert(i);

    for (int i = 0; i < N; i++) {
        int len = N - i;
        int val = findValue(len, K);
        ans[i] = val;
        K -= val;
        if (s.find(val) != s.end()) s.erase(val);
    }
 
    for (int i = N - 1; i > 0; i--) {
        if (ans[i] == ans[i - 1]) {
            ans[i] = *s.begin();
            s.erase(ans[i]);
        }
    }
    return ans;
}

void solve()
{
    int n,k;
    cin>>n>>k;

    vector<int> vec = retrieveArray(n,k);

    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    solve();
    return 0;
}