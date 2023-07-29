#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    map<int, vector<int>> mp;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x].push_back(i);
    }    

    // vector<int> v[n+1];
    // set<int> s;
    // for(int i=0;i<n;i++){
    //     v[vec[i]].push_back(i);
    //     s.insert(vec[i]);
    // }
    vector<vector<int>> v2;

    // for(auto it : v[2]){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    // for(auto it : v[3]){
    //     cout<<it<<" ";
    // }

    for(auto it:mp){
        vector<int> v3(it.first);
        for(int i=0;i<it.second.size();i++)
        {
            v3[i%it.first] = it.second[i];
            if(i%it.first == it.first-1)
                v2.push_back(v3);
        }
    }
    sort(v2.begin(),v2.end());
    int N = v2.size();
    for(int i=0;i<N;i++){
        for(auto it:v2[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}