#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

void func(set<vector<int>> &s,vector<int> v,int k,int n,int prev){
    if(k*n < 0) return;
    if(n == 0 && k == 0){
		s.insert(v);
        return;
    }
    if(n == 0 || k == 0) return;

    for(int i=prev+1;i<10;i++)
    {
    	v.push_back(i);
    	func(s,v,k-1,n-i,i);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum(int k, int n) {
    vector<vector<int>> vec;
    set<vector<int>> s;
	vector<int> v;
    func(s,v,k,n,0);
    
    for(auto &it:s){
        vec.push_back(it);
    }
    
    return vec;
}

void checker() {
    int k, n;
    cin >> k >> n;
    vector<int> t;
    auto v = combinationSum(k, n);
    for (auto &x : v) {
        sort(x.begin(), x.end());
    }
    sort(v.begin(), v.end());
    for (auto x : v) {
        for (auto y : x)cout << y << " ";
        cout << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        checker();
        // i++;
    }
    return 0;
}