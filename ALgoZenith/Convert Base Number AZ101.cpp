//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const int MOD = 1e9+7;
//never use pow() function
int power(int x,int y){
    int ans = 1;
    while(y--) ans *= x;
    return ans;
}

void solve()
{
    string s;
    int A,B;
    cin>>s>>A>>B;

    int dec = 0;
    int n = s.size()-1;

    for(auto it:s){
        int p = power(A,n);
        if(isdigit(it)) dec += p*(it-'0');
        else dec += p*(it-'A'+10);
        n--;
    }
    string ans = "";
    while(dec){
        int num = dec%B;
        if(num < 10) ans.push_back(num+'0');
        else ans.push_back(num+'A'-10);
        dec/=B;
    }

    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}