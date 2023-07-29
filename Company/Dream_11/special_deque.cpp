// There is a special deque which is open from both the ends and always is in sorted order. To insert an 
// element, its position is determined, then each of the elements to the left or right of that position 
// is removed. Now, the new element is inserted, then the removed elements are added back. Each removal 
// or insertion is an operation.

// Determine the minimum number of operations required to insert an integer in the given sorted list of 
// integers stored in the special deque..

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fori(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>b;i--)
#define endl "\n"

void solve()
{
    vector<int> vec;

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        vec.push_back(x);
    }

    int q;
    cin>>q;

    for(int i=0;i<q;i++)
    {
        int y;
        cin>>y;
        int a(1e9),b(1e9);
        int ind1 = lower_bound(vec.begin(),vec.end(),y) - vec.begin();
        int ind2 = n-(upper_bound(vec.begin(),vec.end(),y) - vec.begin());
        cout<<1+2*(min(ind1,ind2))<<endl;
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