//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const int MOD = 1e9+7;

void solve()
{
    int n,m,p;
    cin>>n>>m>>p;

    vector<vector<int>> vec1(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec1[i][j];
        }
    }

    vector<vector<int>> vec2(m,vector<int>(p,0));

    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            cin>>vec2[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            vector<int> a = vec1[i];
            vector<int> b;

            for(int k=0;k<m;k++){
                b.push_back(vec2[k][j]);
            }
            
            int sum = 0;
            for(int k=0;k<m;k++){
                sum += a[k]*b[k];
            }
            cout<<sum<<" ";
        }cout<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}