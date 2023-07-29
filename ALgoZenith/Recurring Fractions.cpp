// //Standard Header Files
// #include<bits/stdc++.h>
// using namespace std;

// #define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define endl "\n"

// string func(int n1,int n2){
//     map<int,int> mp;
//     bool neg = false;
//     if(n1 < 0 && n2 < 0);
//     else if(n1 < 0 || n2 < 0) neg = true;
//     n1 = abs(n1);
//     n2 = abs(n2);
//     string s = to_string(n1/n2);
//     if(n1%n2 == 0){
//         if(neg && n1 != 0) s.insert(0,"-");
//         return s;  
//     } 
//     s.push_back('.');
//     string str;
//     int repeat = -1;
//     n1 = (n1%n2)*10;
//     int i = 0;

//     while(n1){
//         int d = n1/n2;
//         int r = n1%n2;
//         if(mp.count(n1)){
//             repeat = mp[n1];
//             break;
//         }
//         str += to_string(d);
//         mp[n1] = i;
//         n1 = (n1%n2)*10;
//         i++;
//     }
//     if(repeat != -1){
//         str.insert(repeat,"(");
//         s += str + ')';
//     }else s += str;

//     if(neg) s.insert(0,"-");
//     return s;
// }

// void solve()
// {
//     int n,d;
//     cin>>n>>d;

//     cout<<func(n,d)<<endl;
// }

// signed main(){
//     IOS
//     int t=1;cin>>t;while(t--) solve();
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

string solve2(int r, int d){
    //Map to store the remainders
    unordered_map<int, int> m;
    string t = "";
    int digit = 0;
    int i = 0;
    //if remainder == 0 or remainder repeats which means the fraction is repeated.
    while(r && !m[r]){
        m[r] = i;
        r *= 10;
        digit = r/d;
        t += to_string(digit);
        r = r%d;
        i++;
    }
    if(m[r] != 0){
        r *= 10;
        digit = r/d;
        string ms = "";
        ms = t.substr(m[r]-1);
        
        int x = (int)t.size()-m[r]+1;

        while(!t.empty() && x--){
            t.pop_back();
        }

        t.push_back('(');
        t += ms;
        t.push_back(')');
    }
    return t;
}

void solve(){
    string s = "", t;
    int n, d;
    cin>>n>>d;
    
    int q = 0, r = 0, flag1 = 0, flag2 = 0;

    if(n*d < 0){
        flag2 = 1;
    }
    n = abs(n), d = abs(d);
    q = n/d;
    r = n%d;

    if(flag2){
        s.push_back('-');
    }
    s += to_string(q);
    if(r != 0){
        t = solve2(r, d);
        s.push_back('.');
        s += t;
    }
    cout<<s<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}