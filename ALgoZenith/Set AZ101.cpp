//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const int MOD = 1e9+7;

void solve()
{
    int n;
    cin>>n;

    set<int> st;

    while(n--){
        string s;
        cin>>s;

        if(s == "add"){
            int x;
            cin>>x;
            st.insert(x);
        }else if(s == "print"){
            for(auto it:st){
                cout<<it<<" ";
            }cout<<endl;
        }else if(s == "find"){
            int x;
            cin>>x;
            if(st.find(x) != st.end()) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }else if(s == "erase"){
            int x;
            cin>>x;
            if(st.find(x) != st.end()) st.erase(x);
        }else if(s == "empty"){
            st.clear();
        }
    }
}