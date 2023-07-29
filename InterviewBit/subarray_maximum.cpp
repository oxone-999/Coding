#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

vector<int> slidingMaximum(const vector<int> &A, int B) {
    deque<int> q;
    int i=0;
    int j=0;
    int n = A.size();
    vector<int> vec;
    while(j<n)
    {   
        while(q.size()>0 && A[j]>q.back())
        {
            q.pop_back();
        }
        q.push_back(A[j]);
        
        if(j-i+1<B) j++;
        else if(j-i+1 == B)
        {
            vec.push_back(q.front());
            if(A[i] == q.front()) q.pop_front();
            i++;
            j++;
        }
    }
    return vec;
}

void solve()
{
    int n,B;
    cin>>n>>B;
    vector<int> A(n);
    for(auto &it:A){
        cin>>it;
    }

    A = slidingMaximum(A,B);

    for(auto it:A){
        cout<<it<<" ";
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    solve();
    return 0;
}