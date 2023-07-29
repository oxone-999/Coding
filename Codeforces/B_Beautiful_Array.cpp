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
    int n,k,b,s;
    cin>>n>>k>>b>>s;

    vector<int> vec(n,0);

    vec[n-1] = min(s,k*b+k-1);
    int ele = (s-vec[n-1]);

    //edge case
    if(n == 1) {
        if(s/k != b) cout<<-1<<endl;
        else cout<<vec[n-1]<<endl;
        return;
    }else if(s/k < b){
        cout<<-1<<endl;
        return;
    }
    //edge case

    for(int i=n-2;i>=0;i--){
        if(ele >= k-1){
            vec[i] = k-1;
            ele -= k-1;
        }else{
            vec[i] = ele;
            ele = 0;
            break;
        } 
    }
    if(ele){
        cout<<-1<<endl;
        return;
    } 
    for(int i=0;i<n;i++) cout<<vec[i]<<" ";
    cout<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
int t=1;cin>>t;while(t--) solve();
return 0;
}