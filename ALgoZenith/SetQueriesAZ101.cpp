// You have an empty set and can perform the following operations on it:

//     1 x - Add integer x to the set
//     2 x - Find the smallest integer that is not present in the set, which is greater than or equal to x.

// You have an empty set and can perform the following operations on it:

//     1 x - Add integer x to the set
//     2 x - Find the smallest integer that is not present in the set, which is greater than or equal to x.

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
    int q;
    cin>>q;

    set<int> s;
    set<int> s2;
    for(int i=0;i<q;i++)
    {
        int t,x;
        cin>>t>>x;

        if(t == 1)
        {
            s.insert(x);
            if(!s2.empty()) s2.erase(x);
            if(s.find(x+1) == s.end())
	            s2.insert(x+1);
        }
        else
        {
            if(s.find(x) != s.end())
            {
                auto it = s2.lower_bound(x);
                cout<<*it<<endl;
            }
            else
            {
                cout<<x<<endl;
            }
        }
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}