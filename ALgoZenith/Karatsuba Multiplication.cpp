//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;
const lli base = 1000*1000*1000;

int func(int x,int y){
    if(x < 10 && y < 10){
        return x * y;
    }
    
}

void solve()
{
    int n;
    cin>>n;

    vector<int> a(n,0);
    vector<int> b(n,0);

    for(auto &it:a){
        cin>>it;
    }

    for(auto &it:b){
        cin>>it;
    }

    // vector<int> c = func(0,n,a,b);

    vector<int> c (a.size()+b.size());
    for (size_t i=0; i<a.size(); ++i)
        for (int j=0, carry=0; j<(int)b.size() || carry; ++j) {
            long long cur = c[i+j] + a[i] * 1ll * (j < (int)b.size() ? b[j] : 0) + carry;
            c[i+j] = int (cur % base);
            carry = int (cur / base);
        }
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();

    for(auto it:c){
        cout<<it<<" ";
    }cout<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}