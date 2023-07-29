// You are given Q queries and have to perform the following operations:

//     add x - add element x at the top of Priority Queue
//     remove - delete top element of the Priority Queue, if Priority Queue is not empty
//     print - print the element at top of the Priority Queue, if Priority Queue is not empty, otherwise print 0

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
    int n;
    cin>>n;
    priority_queue<int> pq;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s == "add"){
            int x;
            cin>>x;
            pq.push(x);
        }else if(s == "print"){
            if(!pq.empty()) cout<<pq.top()<<endl;
            else cout<<0<<endl;
        }else if(s == "remove"){
            if(!pq.empty()) pq.pop();
        }
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}