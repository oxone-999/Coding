//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

// Manacher Algorithm
struct manacher{
    vector<int> p;

    void run_manacher(string s){
        int n = s.size();
        //setting every element to one as atleast one length 
        //pallindrome is always possible
        p.assign(n,1);
        int l = 1, r = 1;
        for(int i=1;i<n;i++){
            //                            r - i
            //                              ^
            //                              |
            //                  ____________|_____________
            //                  |                       |
            // assume - > l ----i----mid----(i+r-i)---- r
            // copying the value from l+r-i top i as that 
            // is the least value it can have            
            p[i] = max(0,min(r-i,p[l+r-i]));
            while(i+p[i] < n && i-p[i] >= 0 && s[i-p[i]] == s[i+p[i]]){
                p[i]++;
            }
            if(i+p[i] > r){
                l = i-p[i];
                r = i+p[i];
            }
        }
    }

    void build(string s){
        string t;
        for(auto it:s){
            t += string("#") + it;
        }

        run_manacher(t + "#");
    }

    int getLongest(int cen,bool odd){
        int pos = 2*cen + 1 + (!odd);
        return p[pos] - 1;
    }

    bool checkPallindrome(int l ,int r){
        if((r-l+1) <= getLongest((l+r)/2,l%2 == r%2)) return 1;
        else return 0;
    }
}m;

void solve()
{
    string s;
    cin>>s;

    m.build(s);

    int n = s.size();
    int ans = 0;
    int ind = 0;
    int g = 0;
    for(int i=0;i<n;i++){
        if(ans < max(m.getLongest(i,0),m.getLongest(i,1))){
            ans = max(ans,max(m.getLongest(i,0),m.getLongest(i,1)));
            g = i;
            if(m.getLongest(i,0) > m.getLongest(i,1)){
                ind = 0;
            }else ind = 1;
        }
    }

    if(ind == 0){
        int c = ans/2;
        int l = g-c+1;
        string d{s.begin()+l,s.begin()+l+ans};
        cout<<d<<endl;
        return;
    }else{
        int c = ans/2;
        int l = g-c;
        string d{s.begin()+l,s.begin()+l+ans};
        cout<<d<<endl;
        return;
    }
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}