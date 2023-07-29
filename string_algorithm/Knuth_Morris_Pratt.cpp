#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) for(int i=0;i<vec.size();i++) cout<<vec[i]<<" "
#define debarr(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" "
#define MOD 1e9

vector<int> computeLPS(string pat,int m){
    vector<int> lps(m,0);
    int len = 0;
    int i = 1;
    lps[0] = 0;
    while(i<m){
        if(pat[i] == pat[len]){
            lps[i] = len+1;
            len++;
            i++;
        }else{
            if(len != 0) len = lps[len-1];
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    for(auto it:lps){
        cout<<it<<" ";
    }
    cout<<endl;
    return lps;
}

void solve()
{
    string str,pat;
    cin>>str>>pat;

    int n = str.size();
    int m = pat.size();
    vector<int> lps = computeLPS(pat,m);

    int i=0,j=0;
    int cnt = 0;
    while(i<n){
        if(str[i] == pat[j]){
            cnt++;
            if(cnt == m) break;
            i++;
            j++;
        }else{
            if(j) j = lps[j-1];
            else i++;
            cnt = 0;
        }
        if(j == m){
            j = lps[j-1];
            cnt = j;
        }
    }

    if(cnt != m) cout<<"pattern not matched !!";
    else cout<<"pattern matched !!"<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
solve();
return 0;
}