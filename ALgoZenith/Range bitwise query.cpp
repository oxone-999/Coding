//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

lli add(lli a,lli b){
    lli ans = (a+b)%mod;
    if(ans<0) ans += mod;
    return ans;
}

lli sub(lli a,lli b){
    lli ans = (a-b)%mod;
    if(ans<0) ans += mod;
    return ans;
}

lli mul(lli a,lli b){
    lli ans = (a*b)%mod;
    if(ans<0) ans += mod;
    return ans;
}
lli binpow(lli a,lli b){
    if(b==0)return 1;
    if(b==1)return a;
    if((b%2)!=0){
        return mul(a,binpow(a,b-1));
    }else{
        lli temp = binpow(a,b/2);
        return mul(temp,temp);
    }
}

lli inv(lli a){
    return binpow(a,mod-2);
}

lli neg_pow(lli a,lli p){
    return binpow(a,mod-1+p);
}

lli div2(lli a,lli b){
    return mul(a,inv(b));
}

lli pow1[40];

void solve()
{
    int n;
    cin>>n;

    vector<int> vec(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>vec[i];
    }

    vector<vector<int>> pre(n+1,vector<int>(32,0));

    for(int i=1;i<=n;i++){
        for(int j=0;j<32;j++){
            pre[i][j] = pre[i-1][j] + ((vec[i] & (1<<j))?1:0);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<32;j++){
            cout<<pre[i+1][j]<<" ";
        }cout<<endl;
    }

    int q;
    cin>>q;

    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;

        vector<int> p(32,0);

        for(int j=0;j<32;j++){
            p[j] = pre[r][j] - pre[l-1][j];
        }

        int sumXor = 0;
        int subsetXor = 0;
        int sumAnd = 0;
        int subsetAnd = 0;

        for(int j=0;j<32;j++){
            sumXor = add(sumXor,pow1[i]*(p[j]*(l-r+1-p[j])));
            subsetXor = add(subsetXor,pow1[i]*((pow1[p[j]-1] - 1)*pow1[l-r+1-p[j]]));
            sumAnd = add(sumAnd,p[j]*(p[j]-1)/2);
            subsetAnd = add(subsetAnd,pow1[j]-1);
        }
        cout<<sumXor<<" "<<subsetXor<<" "<<sumAnd<<" "<<subsetAnd<<endl;
    }
}

signed main(){
    IOS
    pow1[0] = 1;
    for(int i=1;i<40;i++){
        pow1[i] = (pow1[i-1] * 2)%mod;
    }

    lli t=1;cin>>t;while(t--) solve();
    return 0;
}