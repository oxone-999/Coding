//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

long long add(long long a,long long b){
    long long ans = (a+b)%mod;
    if(ans<0) ans += mod;
    return ans;
}

long long sub(long long a,long long b){
    long long ans = (a-b)%mod;
    if(ans<0) ans += mod;
    return ans;
}

long long mul(long long a,long long b){
    long long ans = (a*b)%mod;
    if(ans<0) ans += mod;
    return ans;
}
long long binpow(long long a,long long b){
    if(b==0)return 1;
    if(b==1)return a;
    if((b%2)!=0){
        return mul(a,binpow(a,b-1));
    }else{
        long long temp = binpow(a,b/2);
        return mul(temp,temp);
    }
}

long long inv(long long a){
    return binpow(a,mod-2);
}

long long neg_pow(long long a,long long p){
    return binpow(a,mod-1+p);
}

long long div(long long a,long long b){
    return mul(a,inv(b));
}

void solve(){
    long long N;
	long double M;
	cin>>N>>M;
	long long X = N;
	long long Y = floor(M);
	long double dotZ = M - (long double)Y;
    cout<<fixed<<setprecision(9);
    cout<<"M : "<<M<<endl;
    cout<<"dotZ : "<<dotZ<<endl;
	stringstream sso;
	sso<<dotZ;
	string stringdotZ;
	sso>>stringdotZ;
    cout<<"stringdotz : "<<stringdotZ<<endl;
	long long digitsZ = stringdotZ.length()-2;
	long long Z = dotZ*pow(10,digitsZ);
    cout<<"Z : "<<Z<<endl;
	cout<<(Z+X)<<'.'<<(Y+X)<<"\n";
}

// void solve()
// {
//     long long n;
//     cin>>n;
//     string m;
//     cin>>m;

//     long long size = m.size()-1;
//     long long i = 0;
//     for(i=0;i<size+1;i++){
//         if(m[i] == '.'){
//             break;
//         }
//     }
//     long long y = stolong long(m.substr(0,i));
//     long long z = stolong long(m.substr(i+1));

//     cout<<(z+n)<<"."<<(y+n)<<endl;
// }

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t=1;cin>>t;while(t--) solve();
    return 0;
}