// Design a Data Structure which can support the following queries:

// 1 x: Add x in structure
// 2 x: Remove x from the structure if present in the structure. If x doesn't present in the structure, do nothing. 
// If there are multiple occurrences of x, delete only one occurrence of x.
// 3 ?: Print the minimum number present in the structure. If the structure is empty, print -1.
// 4 ?: Print the maximum number present in the structure. If the structure is empty, print -1.
// 5 ?: Print the sum of all numbers present in the structure. If the structure is empty, print 0.


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
    int sum = 0;
    map<int,int> s;

    for(int i=0;i<q;i++){
        int ch;
        cin>>ch;
        if(ch == 1){
            int num;
            cin>>num;
            sum += num;
            s[num]++;
        }else if(ch == 2){
            int num;
            cin>>num;
            if(s.empty()) continue;
            if(s.count(num)){
            	sum -= num;
                s[num]--;
                if(s[num] == 0) s.erase(num);    
            }
        }else if(ch == 3){
            char s1;
            cin>>s1;
            if(s.empty()){
                cout<<(-1)<<endl;
                continue;
            } 
            auto it = s.begin();
            cout<<it->first<<endl;
        }else if(ch == 4){
            char s1;
            cin>>s1;
            if(s.empty()){
                cout<<(-1)<<endl;
                continue;
            } 
            auto it = s.end();
            it--;
            cout<<it->first<<endl;
        }else if(ch == 5){
            char s1;
            cin>>s1;
            cout<<sum<<endl;
        }
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    solve();
    return 0;
}