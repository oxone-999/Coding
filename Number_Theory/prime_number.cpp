#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

bool isPrime(int n){
    for(int i=2;i*i <= n;i++)
        if(n%i == 0) return 0;
    return 1;
}

void solve()
{
    int n;
    cin>>n;
    if(isPrime(n)) cout<<"prime"<<endl;
    else cout<<"Not Prime"<<endl;	
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
int t=1;cin>>t;while(t--) solve();
return 0;
}