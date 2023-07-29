//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;
lli n;
const lli N = 100;
const lli M = 25;

int primes[N];
int power[M];
lli ans = 0;
int marked[N];

void func(lli last,lli m,int par){
    if(!m){
        if(primes[last+1]) ans++;
        return;
    }
    for(lli i=1+par;i<=n;i+=2){
        if(!marked[i] && primes[last + i]){
            marked[i] = 1;
            func(i,m-1,1-par);
            marked[i] = 0;
        }
    }
}

void solve()
{   
    memset(primes,true,sizeof(primes));
    memset(marked,false,sizeof(marked));
    power[0] = 1;
    for(int i=1;i<M;i++){
        power[i] = power[i-1]*2;
    }
    for(int i=2;i<N;i++){
        if(primes[i]){
            for(int j=i*i;j<N;j+=i){
                primes[j] = 0;
            }
        }
    }

    cin>>n;
    if(n % 2){
        cout<<0<<endl;
        return;
    }
    marked[1] = 1;
    func(1,n-1,1);
    cout<<ans<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}