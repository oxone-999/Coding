// Alice read N books. The i-th book has Ai pages. After every book Alice reads, you have to tell the largest integer B such 
// that Alice has read B books that have at least B pages.

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

char* solve()
{
    // int n;
    // cin>>n;

    // int b = 1;
    // multiset<int> s;

    // for(int i=0;i<n;i++){
    //     int num;
    //     cin>>num;

    //     s.insert(num);

    //     while(!s.empty() && (*s.begin()) <= b){
    //         s.erase(*s.begin());
    //     }

    //     if(s.size() > b){
    //         b++;
    //     }
    //     cout<<b<<" ";
    // }
    // cout<<endl;

    string str = "abcde";
    str.c_str();
    return str;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    cout<<solve()<<endl;
    return 0;
}