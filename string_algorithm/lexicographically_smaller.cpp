//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

//Policy Based Data Structure Header Files
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using pbds_ordered_set = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using pbds_multi_set = tree<T, null_type, less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

bool lex_small(vector<int> vec,vector<int> vec2){
    int mn = 0;
    int mx = 0;
    for(int i=0;i<26;i++){
        if(vec[i]){
            mn = i;
            break;
        } 
    }
    for(int i=25;i>=0;i--){
        if(vec2[i]){
            mx = i;
            break;
        } 
    }
    bool b = 1;
    if(mn < mx) return true;
    else if(mn == mx && vec[mn] < vec2[mx]){
        for(int j = mn+1;j<26;j++){
            if(vec[j] > 0) {
                return false; 
            }
        }
        return true;
    } 
    return false;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
lex_small({},{});
return 0;
}