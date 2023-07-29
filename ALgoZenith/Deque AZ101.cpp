//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const int MOD = 1e9+7;

void solve()
{
    int n;
    cin>>n;

    deque<int> d;
    stack<int> s;

    while(n--){
        string st;
        cin>>st;

        if(st == "insertback"){
            int x;
            cin>>x;
            d.push_back(x);
        }else if(st == "printback"){
            if(d.empty()) cout<<0<<endl;
            else cout<<d.back()<<endl;
        }else if(st == "print"){
            int x;
            cin>>x;
            if(d.empty()) cout<<0<<endl;
            else {
                while(x--){
                    s.push(d.front());
                    d.pop_front();
                }
                if(d.empty()) cout<<0<<endl;
                else cout<<d.front()<<endl;
                while(!s.empty()){
                    d.push_front(s.top());
                    s.pop();
                }   
            }
        }else if(st == "eraseback"){
            if(!d.empty()) d.pop_back();
        }else if(st == "insertfront"){
            int x;
            cin>>x;
            d.push_front(x);
        }else if(st == "erasefront"){
            if(!d.empty()) d.pop_front();
        }else if(st == "printfront"){
            if(d.empty()) cout<<0<<endl;
            else cout<<d.front()<<endl;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}