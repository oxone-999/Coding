#include<bits/stdc++.h>
using namespace std;

int MOD = 1e9+7;

unsigned long binomialCoeff(unsigned int &n,unsigned int k){
    unsigned long res = 1;
    if (k > n - k) k = n - k;
 
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
        res %= MOD;
    }
    res %= MOD;
    return res;
}
 
unsigned long catalan(int &n){
    int k=n;
    int nn=n*n;
    unsigned long res = 1;
    if (k > nn - k) k = nn - k;
 
    for (int i = 0; i < k; ++i) {
        res *= (nn - i);
        res /= (i + 1);
        res %= MOD;
    }
    res %= MOD;
    int p= res;


    unsigned long c =p;
    c /= (n + 1);
    return c;
}

int rec(vector<int> &A,int N){
    if(N == 0) return 0;
    return max((rec(A,N-1)^A[N-1]),(rec(A,N-1)));
}

int MXC(int N,int& K,vector<int> &A){
    int x = rec(A,N);
    unsigned long ans = (catalan(x) * K)%MOD;
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;

    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<MXC(n,k,A)%MOD<<endl;
    return 0;
}