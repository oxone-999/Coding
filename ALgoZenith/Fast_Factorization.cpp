#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

void solve()
{
    int q;
    cin>>q;

    vector<int> sp(1e6+1);

    for(int i=2;i<=1e6;i++){
        sp[i] = i;
    }

    for(int i=2;i<=1e6;i++){
        if(sp[i] == i){
            for(int j=2*i;j<=1e6;j+=i){
                if(sp[j] == j) sp[j] = i; 
            }
        }
    }

    while(q--){
        int n;
        cin>>n;
        while(n > 1){
            cout<<sp[n]<<" ";
            n /= sp[n];
        }cout<<endl;
    }	
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
solve();
return 0;
}