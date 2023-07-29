//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

void solve()
{
    lli a,b;
    cin>>a>>b;
    lli d = sqrt(b);

    vector<lli> prime(d+1,1);

    for(lli i=2;i<=d;i++){
        if(prime[i]){
            for(lli j=1LL*i*i;j<=d;j += i){
                prime[j] = 0;
            }
        }
    }

    lli m = b-a+1;
    lli is_prime[m];
    for(lli i=0;i<m;i++){
        is_prime[i] = 1;
    }

    for(lli i=2;i<=d;i++){
        if(prime[i]){
            lli curMul = ((a+i-1)/i) * i;

            while(curMul <= b){
                if(curMul != i){
                    is_prime[curMul-a] = 0;    
                }
                curMul += i;
            }
        }
    }
    lli x = 0;
    vector<lli> v;

    for(lli i=0;i<m;i++){
        if(is_prime[i]){
            x++;
            v.push_back(i+a);
        }
    }
    if(v[0] == 1) cout<<x-1<<endl;
    else cout<<x<<endl;
    for(auto it:v){
        if(it > 1) cout<<it<<" ";
    }
}

signed main(){
    IOS
    solve();
    return 0;
}