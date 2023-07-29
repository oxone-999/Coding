#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

vector<int> func(int M,int N){
    if(M <= 1) M = 2;
    vector<int> is_Prime(N-M+1,1);
    vector<int> v(sqrt(N)+1,1);
    v[0] = 0;
    v[1] = 0;

    for(int i=2;i<=sqrt(N);i++){
        if(v[i]){
            for(int j = i*i;j<=sqrt(N);j+=i){
                v[j] = 0;       
            }    
        }
    }

    for(int i=2;i<=sqrt(N);i++){
        if(v[i]){
            int fm = (M/i)*i;
            if(fm < M) fm += i;
            for(int j = max(fm,i*i);j<=N;j+=i){
                is_Prime[j-M] = 0;
            }
        }
    }

    vector<int> vec;
    for(int i=M;i<=N;i++){
        if(is_Prime[i-M]) vec.push_back(i);
    }
    return vec;
}

void solve() {
	int M,N;
    cin>>M>>N;
    
    vector<int> vec = func(M,N);
    for(auto it:vec){
        cout<<it<<" ";
    }
    cout<<endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}