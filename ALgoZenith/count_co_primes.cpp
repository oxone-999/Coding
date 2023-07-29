#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    vector<int> isPrime(1e6+1,1);
    vector<int> phi(1e6+1,0);

    for(int i=1;i<=1e6;i++){
        phi[i] = i;
    }

    for(int i=2;i<=1e6;i++){
        if(isPrime[i]){
            for(int j = i*i;j<=1e6;j+=i){
                isPrime[j] = 0;
            }
        }
    }

    for(int i=2;i<=1e6;i++){
        if(isPrime[i]){
            for(int j = i;j<=1e6;j+=i){
                phi[j] -= phi[j]/i;
            }
        }
    }
    for(int i=1;i<100;i++){
        cout<<phi[i]<<endl;
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
solve();
return 0;
}