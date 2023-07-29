//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

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

lli div2(lli a,lli b){
    return mul(a,inv(b));
}

class Solution{
    public:

    //mode
    map<lli,lli> mp;
    set<pair<lli,lli>> st;
    lli sum;
    lli n;

    //median
    multiset<lli> s1,s2;

    Solution(){
        sum = 0;
        n = 0;
        mp.clear();
        st.clear();
        s1.clear();
        s2.clear();
    }

    void insert(lli x){
        //mode
        if(st.find({mp[x],-x}) != st.end())
            st.erase({mp[x],-x});
        mp[x]++;
        st.insert({mp[x],-x});
        
        //mean
        sum += x;
        sum %= mod;
        n++;
        
        //median
        if(!s1.empty() && x <= *s1.rbegin()) s1.insert(x);
        else s2.insert(x);

        //balancing
        if(s1.size() - s2.size() == 2){
            lli x = *s1.rbegin();
            s1.erase(s1.find(x));
            s2.insert(x);
        }else if(s2.size() > s1.size()){
            lli y = *s2.begin();
            s2.erase(s2.find(y));
            s1.insert(y);
        }
    }

    void remove(lli x){
        //mode
        if(st.find({mp[x],-x}) != st.end())
            st.erase({mp[x],-x});
        mp[x]--;
        if(mp[x] == 0) mp.erase(x);
        else st.insert({mp[x],-x});

        //mean
        sum -= x;
        sum %= mod;
        n--;

        //median
        if(s1.find(x) != s1.end()){
            s1.erase(s1.find(x));
        }else s2.erase(s2.find(x));

        //balancing
        if(s1.size() - s2.size() == 2){
            lli x = *s1.rbegin();
            s1.erase(s1.find(x));
            s2.insert(x);
        }else if(s2.size() > s1.size()){
            lli y = *s2.begin();
            s2.erase(s2.find(y));
            s1.insert(y);
        }
    }

    lli getMode(){
        if(st.empty()) return (-1);
        else return -(*st.rbegin()).second;
    } 

    lli getMedian(){

        //balancing
        if(s1.size() - s2.size() == 2){
            lli x = *s1.rbegin();
            s1.erase(s1.find(x));
            s2.insert(x);
        }else if(s2.size() > s1.size()){
            lli y = *s2.begin();
            s2.erase(s2.find(y));
            s1.insert(y);
        }
        
        // for(auto it:s1) cout<<it<<" ";
        // cout<<endl;
        // for(auto it:s2) cout<<it<<" ";
        // cout<<endl;

        if(n % 2 != 0) return *s1.rbegin();
        else{
            if(n == 0) return -1;
            else return div2((*s1.rbegin() + *s2.begin()),2);
        } 
    }

    lli getMean(){
        if(sum < 0) sum += mod;
        else if(sum >= mod) sum -= mod;
        if(n == 0) return -1;
        else return mul(sum,inv(n))%mod;
    }
};

void solve()
{
    Solution ob1;

    lli n;
    cin>>n;

    while(n--){
        string ch;
        cin>>ch;

        if(ch == "insert"){
            lli x;
            cin>>x;
            ob1.insert(x);
        }else if(ch == "remove"){
            lli x;
            cin>>x;
            ob1.remove(x);
        }else if(ch == "getMean"){
            cout<<ob1.getMean()<<endl;
        }else if(ch == "getMode"){
            cout<<ob1.getMode()<<endl;
        }else if(ch == "getMedian"){
            cout<<ob1.getMedian()<<endl;
        }else cout<<"Error"<<endl;
    }
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}