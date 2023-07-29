// You are given an integer N. You have to find all the permutations of N in lexicographic order.

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

void func(int i,vector<int> &vec,vector<vector<int>> &A){
    int n = vec.size();
    if(i == n){
        A.push_back(vec);
        return;
    }

    for(int j=i;j<n;j++){
        swap(vec[i],vec[j]);
        func(i+1,vec,A);
        swap(vec[i],vec[j]);
    }
}

// STL trick

void func2(vector<int> &vec,vector<vector<int>> &A){
    do{
        A.push_back(vec);
    }while(next_permutation(vec.begin(),vec.end()));
}

void solve()
{
    int n;
    cin>>n;

    vector<int> vec;
    for(int i=0;i<n;i++){
        vec.push_back(i+1);
    }
    vector<vector<int>> A;

    // func(0,vec,A);
    func2(vec,A);

    sort(A.begin(),A.end());

    for(int i=0;i<A.size();i++){
        for(auto &it:A[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    solve();
    return 0;
}



