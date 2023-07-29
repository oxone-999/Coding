// A message containing letters from A-Z is being encoded to numbers using the following mapping:

//  'A' -> 1
//  'B' -> 2
//  ...
//  'Z' -> 26
// Given an encoded message A containing digits, determine the total number of ways to decode it modulo 109 + 7.

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9
#define MOD 1000000007

int numDecodings(string A) {
    int dp[A.size()];
    if(A.size() == 0) return 0;
    else if(A[0] == '0') return 0;
    dp[0] = 1;

    for(int i=1;i<A.size();i++)
    {
        if(A[i-1] == '0' && A[i] == '0') // 00 -> there is no way to decode it
        {
            dp[i] = 0;
        }
        else if(A[i-1] == '0' && A[i] != '0') // 0? -> remains same as before, example -> 10 to 103 , (J) - > (JC)
        {
            dp[i] = (dp[i-1])%MOD;
        }
        else if(A[i-1] != '0' && A[i] == '0') // ?0 -> (? <= 2) -> remains same for i<=2 else 1, (?>2) -> 0, 12->(AB,L), 120 -> (AB,L)  
        {
            if(A[i-1] == '1' || A[i-1] == '2') dp[i] = (i>=2 ? dp[i-2] : 1)%MOD;
            else dp[i] = 0;
        }
        else // ?? if(?? <= 26) : 12 -> (AB,L) -> 125 -> (ABE,LE,AY)
        {
            string s;
            s.push_back(A[i-1]);
            s.push_back(A[i]);
            if(stoi(s)<=26)
            {
                dp[i] = (dp[i-1] + (i>=2 ? dp[i-2] : 1))%MOD;
            }
            else dp[i] = dp[i-1]%MOD;
        }
    }
    return dp[A.size()-1];
}


void solve()
{
    string A;
    cin>>A;
    cout<<numDecodings(A)<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
