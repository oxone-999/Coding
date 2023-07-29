//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

void solve()
{
    string s;
	cin>>s;
	bool pos= 1;
	bool flag=0;
	int cur = 0;
	int i = 0;
	map<lli,lli> ans;
	while(i<s.length()){
		if(s[i]=='f'){
			flag=1;
			cur++;
			i+=3;
		}else{
			if(flag)ans[cur]++;
			flag=0;i+=6;
			cur--;
			if(cur<0){
				pos=0;break;
			}
		}
	}

	if(pos&&cur==0){
		bool fs = 0;
		for(auto it = ans.rbegin();it!=ans.rend();it++){
			if(fs){
				cout<<" + ";
			}
			if(it->second!=1)cout<<it->second;
			cout<<"n";
			if(it->first!=1){
				cout<<"^"<<it->first;
			}
			fs=1;
		}
		cout<<endl;
	}else{
		cout<<"Compile Error"<<endl;
	}
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}