//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
 
signed main(){
    IOS
    int n;cin>>n;
    map<int,int> mp;
    int sum(0),ans(0),x;
    while(cin>>x){
        sum += x;
        ans += mp[((sum%n)+n)%n]++;
    }
    cout<<(ans+mp[0])<<endl;
    return 0;
}