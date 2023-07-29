#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    string s;
    cin>>s;
    int n = s.size();

    int i=0;
    int j=n-1;
    while(i<j)
    {
        if(s[i] != s[j]) break;
        i++;
        j--;
    }

    string s1 = s.substr(0,i);
    s1+=s.substr(i+1);

    string s2 = s.substr(0,j);
    s2+=s.substr(j+1);

    string s3 = s1;
    string s4 = s2;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());

    string ans = "N";
    if(s1 == s3) ans = "Y";
    if(s2 == s4) ans = "Y";
    cout<<ans<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}