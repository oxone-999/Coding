// //Standard Header Files
// #include<bits/stdc++.h>
// using namespace std;

// #define int long long
// #define endl "\n"
// #define all(a) (a).begin(), (a).end()

// const int MOD = 1e9+7;

// void solve()
// {
//     int n;
//     cin>>n;
//     int sum = 0;
//     for(int i=0;i<n;i++){
//         int x;cin>>x;
//         sum += x;
//     }
//     int sum2 = 0;
//     for(int i=0;i<n-1;i++){
//         int x;cin>>x;
//         sum2 += x;
//         sum -= x;
//     }
//     cout<<sum<<" ";

//     for(int i=0;i<n-2;i++){
//         int x;cin>>x;
//         sum2 -= x;
//     }
//     cout<<sum2<<endl;
// }

// signed main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);cout.tie(0);
//     int t=1;cin>>t;while(t--) solve();
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n,a[n],b[n-1],c[n-2];
    cin>>n;
    long long int s1=0,s2=0,s3=0;
    int i;
    for( i=0;i<n;i++){
        cin>>a[i];
        s1+=a[i];
    }
    for(i=0;i<n-1;i++){
        cin>>b[i];
        s2+=b[i];
    }
    for(i=0;i<n-2;i++){
        cin>>c[i];
        s3+=c[i];
    }
    cout<<s1-s2<<endl;
    cout<<s2-s3<<endl;
}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
int _t;cin>>_t;while(_t--)
solve();
}