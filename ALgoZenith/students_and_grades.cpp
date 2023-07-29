// There are N students in section A. The i-th student got Ai marks. The class teacher of section B was absent so sections A 
// and B were merged. The students of section B did not want to humiliate themselves, so they decided to sit with students 
// having the same marks as them. You are given the marks of students of section B in order of their entry in the class. 
// You have to tell whether the i-th student of section B can sit with a student with the same marks as him. If there is at 
// least 1 person in the room with the same marks, print ‘YES’ else print ‘NO’. (without the quotes)

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

void solve()
{
    int n,m;
    cin>>n>>m;

    set<int> s;
    vector<int> B(m);

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.insert(x);
    }
    for(auto &it:B){
        cin>>it;
    }

    for(auto &it:B){
        auto v = s.lower_bound(it);
        if(*v != it) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
        } 
        s.insert(it);
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}