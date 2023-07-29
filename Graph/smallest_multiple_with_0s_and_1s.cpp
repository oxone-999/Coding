#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl

long long rem(string num, int m)
{
    long long mod = 0;
    
    for (int i = 0; i < num.size(); i++) {
        int digit = num[i] - '0';
        mod = ((mod*10)%m + digit)%m;    
    }
    return mod;
}

void solve(int A) {

    string B = to_string(A);
    int n = B.size();
    
    queue<string> q;
    q.push("1");
    
    set<long long> mp;
    
    mp.insert(1);
    
    while(!q.empty())
    {
        string num = q.front();
        q.pop();
        
        string num1 = num;
        string num2 = num;
        
        num1 += "0";
        num2 += "1";
        
        long long rem1,rem2;
        rem1 = rem(num1,A);
        rem2 = rem(num2,A);
        
        if(rem1 == 0) 
        {
            cout<<num1;
            return;            
        }
        else if(rem2 == 0)
        {
            cout<<num2;
            return;
        }
            
        if(mp.find(rem1) == mp.end())
        {
            mp.insert(rem1);
            q.push(num1);
        }
        if(mp.find(rem2) == mp.end())
        {
            mp.insert(rem2);
            q.push(num2);
        }
    }
    cout<<"-1";
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t = 1;
    while(t--)
    {
        int n;
        cin>>n;
        // cout<<rem("111011111101111111011",n);
        solve(n);
    }
    return 0;
}