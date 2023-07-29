//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define MOD 1e9
#define all(a) (a).begin(), (a).end()

int solve(int n)
{
    int x = n;
    set<int> vec;
    for(int i=2;i*i<=n;i++){
        if(n%i == 0){
            vec.insert(i);
            while(n%i == 0){
                n /= i;
            }
        }
    }
    if(n > 2) vec.insert(n);
    
    for(auto it:vec){
        x -= x/it;
    }
    return x;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    if(n == 2) cout<<1;
    else cout<<solve(n);
    return 0;
}