// //Standard Header Files
#include<bits/stdc++.h>
// using namespace std;

// #define int long long
// #define endl "\n"
// #define all(a) (a).begin(), (a).end()

// const int MOD = 1e9+7;

// void solve()
// {
//     int M,F,R;
//     cin>>M>>F>>R;

//     int T = M+F;

//     if(M == -1 || F == -1) cout<<"F"<<endl;
//     else if(T >= 80) cout<<"A"<<endl;
//     else if(T >= 65 && T < 80) cout<<"B"<<endl;
//     else if(T >= 50 && T < 65) cout<<"C"<<endl;
//     else if(T >= 30 && T < 50){
//         if(R >= 50) cout<<"C"<<endl;
//         else cout<<"D"<<endl;
//     }else cout<<"F"<<endl;
// }

// signed main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);cout.tie(0);
//     int t=1;cin>>t;while(t--) solve();
//     return 0;
// }

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    IOS
    long long int t;
    long long int n;
    cin>>t;
    long long int count;
    long long int k;
    for(long long int k=0;k<t;k++){
        cin>>n;
        long long int arr[n];
        for(long long int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(long long int i=0;i<n;i++){
            count=0;
            for(long long int j=0;j<n;j++){
                if((arr[i]^arr[j])==0){
                    count++;
                }
            }  
            if((count%2)!=0){
                cout<<arr[i]<<"\n";
            }
        }
    }
}