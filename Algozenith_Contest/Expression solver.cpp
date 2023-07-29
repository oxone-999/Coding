//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

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

void solve()
{
    string s;
    cin>>s;

    lli i = 0;
    lli n = s.size();

    vector<string> vec = split(s,'=');

    string a = vec[0];
    string b = vec[1];
    
    bool left = true;

    for(auto it:b){
        if(it == 'X'){
            left = false;
        }
    }

    bool neg = false;
    if(left){
        for(lli i=0;i<a.size();i++){
            if(a[i] == 'X'){
                if(i > 0){
                    if(a[i-1] == '-') neg = true;
                    a.erase(i-1,2);
                }else a.erase(i,1);
            }
        }
    }else{
        for(lli i=0;i<b.size();i++){
            if(b[i] == 'X'){
                if(i > 0){
                    if(b[i-1] == '-') neg = true;
                    b.erase(i-1,2);
                }else b.erase(i,1);
            }
        }
    }

    if(!a.empty() && isdigit(a[0])){
        a.insert(0,"+");
    }
    if(!b.empty() && isdigit(b[0])){
        b.insert(0,"+");
    }
    // cerr<<a<<" "<<b<<endl;

    lli x = 0;
    for(int i=0;i<a.size();i++){
        lli num = 0;
        bool ng = (a[i] == '-')?true:false;
        // cout<<a[i]<<" "<<ng<<" ";
        i++;
        while(i < a.size() && isdigit(a[i])){
            num = num*10 + (a[i]-'0');
            i++;
        }
        i--;
        if(ng) x -= num;
        else x += num;
    }

    lli y = 0;
    for(int i=0;i<b.size();i++){
        lli num = 0;
        bool ng = (b[i] == '-')?true:false;
        i++;
        while(i < b.size() && isdigit(b[i])){
            num = num*10 + (b[i]-'0');
            i++;
        }
        i--;
        if(ng) y -= num;
        else y += num;
    }
    // cout<<x<<" "<<y<<endl;
    lli ans = 0;
    if(left){
        ans = y-x;
    }else ans = x-y;
    if(neg) ans = -ans;

    cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}