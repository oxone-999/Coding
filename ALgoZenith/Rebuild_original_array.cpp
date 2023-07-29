// Your class teacher wrote N integers on the board. One of your classmates was being mischievous, he replaced the N integers 
// with all possible subset sums of the array when the teacher was not in the class. 
// Suppose that the integers on the board were [2,1] then the subsets will be: {}, {2}, {1}, {2,1} and the subset sums will be: 
// {0,2,1,3}. 
// Your task is to rebuild the original array given by your teacher.

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

    if(n == 0) return;

    int m = (1<<n);
    vector<int> vec;
    set<int> s;

    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        if(i>1) s.insert(x);
        vec.push_back(x);
    }

    vector<int> ans;
    ans.push_back(vec[1]);

    int sum = vec[m-1];
    int st = vec[1];
    
    for(int j=2;j<m;j++){
        if(s.find(vec[j]-st) != s.end()){
            ans.push_back(vec[j]-st);
            s.erase(vec[j]);
            st = vec[j];
        }
    }

    sort(ans.begin(),ans.end());

    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}