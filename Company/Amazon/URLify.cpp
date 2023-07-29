#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    string s;
    getline(cin,s);

    while(s.back() == ' ')
        s.pop_back();
    reverse(s.begin(),s.end());
    while(s.back() == ' ')
        s.pop_back();
    reverse(s.begin(),s.end());

    string str = "";

    int n = s.size();
    for(int i=0;i<n;i++){
        if(s[i] != ' ') str.push_back(s[i]);
        else str += "%20";
    }
    cout<<str<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t = 1;
    cin>>t;
    string s;
    getline(cin,s);
    while(t--)
    {
        solve();
    }
    return 0;
}