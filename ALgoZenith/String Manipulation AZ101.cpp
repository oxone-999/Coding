//Standard Header Files
// You are given a string S of lowercase alphabets. You are given Q queries and have to perform the following operations: (0-indexing is used)

// print a b - print S from a-th to b-th character
// reverse a b - reverse S from a-th to b-th character
// replace a b p - replace a-th to b-th character with string p, |p| = b-a+1
// rotate k - right rotate the array by k

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const int MOD = 1e9+7;

void solve()
{
    string s;
    cin>>s;

    int q;
    cin>>q;

    while(q--){
        string ch;
        cin>>ch;

        if(ch == "print"){
            int x,y;
            cin>>x>>y;
            cout<<s.substr(x,y-x+1)<<endl;
        }else if(ch == "reverse"){
            int x,y;
            cin>>x>>y;
            reverse(s.begin()+x,s.begin()+y+1);
        }else if(ch == "replace"){
            int x,y;
            cin>>x>>y;
            string c;
            cin>>c;
            int j = 0;
            for(int i=x;i<=y;i++){
                s[i] = c[j++];
            }
        }else if(ch == "rotate"){
            int x;
            cin>>x;
            string a = s.substr(0,s.size()-x);
            string b = s.substr(s.size()-x);
            s = b+a;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}