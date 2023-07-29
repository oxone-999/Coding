//Standard Header Files

#include <bits/stdc++.h>
using namespace std;

using lli = long long;

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

class ProductOfKNumbers {
public:
    lli c;
    lli pos;
    vector<lli> vec;

	ProductOfKNumbers() {
        c = 0;
        pos = 0;
        vec.assign(100005,1);
	}

	void add(int x) {
		c++;
        if(x == 0) pos = c;
        if(x != 0) vec[c] = mul(vec[c-1],x)%mod;
        else vec[c] = vec[c-1];
	}

	int getProduct(int x) {
		if(pos <= c-x) return div2(vec[c],vec[c-x])%mod;
        else return 0;
	}
};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int Q;
	cin >> Q;

	ProductOfKNumbers productOfKNumbers;

	while(Q--) {
		string op;
		cin >> op;

		if(op == "add"){
			int num;
			cin >> num;
			productOfKNumbers.add(num);
		}
		else{
			int k;
			cin >> k;
			cout << productOfKNumbers.getProduct(k) << "\n";
		}
	}
	return 0;
}