#include <bits/stdc++.h>
using namespace std;

vector<int> v(6,0);
void swap1(int a,int b,int c,int d) {
    int temp = v[a];
    v[a] = v[b];
    v[b] = v[c];
    v[c] = v[d];
    v[d] = temp;
}
void solve()
{
    for(int i = 0;i<6;i++) cin>>v[i];
    string s;
    cin>>s;
    for(int i = 0;i<s.size();i++) {
        if(s[i] == 'N') swap1(0,1,5,4);
        if(s[i] == 'S') swap1(0,4,5,1);
        if(s[i] == 'E') swap1(0,3,5,2);
        if(s[i] == 'W') swap1(0,2,5,3);
    }
    cout<<v[0]<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;while(t--)solve();
    return 0;
}