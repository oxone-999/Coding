//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

void solve()
{
    int a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;

    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    bool Ain = false;
    bool Bin = false;

    if((x1 < a1 < x2) && (y1 < a2 < y2)){
        Ain = true;
    }

    if((x1 < b1 < x2) && (y1 < b2 < y2)){
        Bin = true;
    }

    if((Ain & Bin) == 0){
        cout<<(-1)<<endl;
        return;
    }

    if(((x1 < a1 < x2) && (x1 < b1 < x2) && ((a2 > y2 && b2 < y1) || (a2 < y1 && b2 > y2))) || ((y1 < a2 < y2) && ())))
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}