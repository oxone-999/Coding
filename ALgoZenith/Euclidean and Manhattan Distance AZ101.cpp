//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
using lli = long long;
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const int mod = 1e9+7;

//Power
int power(int x,int y){
  int ans = 1;
  while(y--) ans*=x;
  return ans;
}

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

lli div(lli a,lli b){
  return mul(a,inv(b));
}


void solve()
{
  	int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    cout<<fixed<<setprecision(7);

    double e = sqrt(power(x1-x2,2) + power(y1-y2,2));
    double m = abs(x1-x2) + abs(y1-y2);

    cout<<e<<" "<<m<<endl;
    cout<<fixed<<setprecision(7);
    long double a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<a<<endl;
    cout<<sqrt(binpow(abs(a-c),2)+binpow(abs(b-d),2))<<" ";
    cout<<abs(a-c)+abs(b-d);
    cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}