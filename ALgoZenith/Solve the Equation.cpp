//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

vector<string> split(string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        if (item.length() > 0) {
            elems.push_back(item);  
        }
    }
    return elems;
}

lli mod = 1e9+7;

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

void solve()
{
    lli a,b,c,p;
    string s;
    getline(cin,s);

    for(int i=0;i<(int)s.size();i++){
        if(s[i] == '(') s.erase(i,1);
    }

    for(int i=0;i<(int)s.size();i++){
        if(s[i] == ')') s.erase(i,1);
    }

    vector<string> vec = split(s,' ');

    string A = vec[0];
    string B = vec[2];
    string C = vec[4];
    string P = vec[6];

    string op1 = vec[1];
    string op2 = vec[3];

    stringstream ss;
    stringstream ss1;
    stringstream ss2;
    stringstream ss3;

    ss<<A;
    ss>>a;
    ss1<<B;
    ss1>>b;
    ss2<<C;
    ss2>>c;
    ss3<<P;
    ss3>>p;

    mod = p;

    a %= p;
    b %= p;
    c %= p;

    lli x,y;

    if((op1 == "*" && op2 == "/") || (op1 == "/" && op2 == "*")){
        if(op1 == "*"){
            x = mul(a,b);
            y = div2(x,c);
        }else{
            x = div2(a,b);
            y = mul(x,c);
        }
    }else if((op1 == "+" && op2 == "-") || (op1 == "-" && op2 == "+")){
        if(op1 == "+"){
            x = add(a,b);
            y = sub(x,c);
        }else {
            x = sub(a,b);
            y = add(x,c);
        }
    }else if(op1 == "+" && op2 == "+"){
        y = add(add(a,b),c);
    }else if(op1 == "-" && op2 == "-"){
        y = sub(sub(a,b),c);
    }else if(op1 == "*"  && op2 == "*"){
        x = mul(a,b);
        y = mul(x,c);
    }else if(op1 == "/" && op2 == "/"){
        x = div2(a,b);
        y = div2(x,c);
    }else{
        if(op1 == "*" || op1 == "/"){
            if(op2 == "+" && op1 == "*"){
                x = mul(a,b);
                y = add(x,c);
            }else if(op2 == "-" && op1 == "*"){
                x = mul(a,b);
                y = sub(x,c);
            }else if(op2 == "+" && op1 == "/"){
                x = div2(a,b);
                y = add(x,c);
            }else if(op2 == "-" && op1 == "/"){
                x = div2(a,b);
                y = sub(x,c);
            }
        }else if(op2 == "*" || op2 == "/"){
            if(op2 == "*" && op1 == "+"){
                x = mul(b,c);
                y = add(x,a);
            }else if(op2 == "/" && op1 == "+"){
                x = div2(b,c);
                y = add(x,a);
            }else if(op2 == "*" && op1 == "-"){
                x = mul(b,c);
                y = sub(a,x);
            }else if(op2 == "/" && op1 == "-"){
                x = div2(b,c);
                y = sub(a,x);
            }
        }
    }
    y %= p;
    if(y < 0) y += p;
    if(y >= p) y -= p;
    cout<<y<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;
    string s;
    getline(cin,s);
    while(t--) solve();
    return 0;
}