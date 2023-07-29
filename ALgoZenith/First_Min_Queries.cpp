//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

class SGT{
    public:
    vector<lli> seg;
    SGT(lli n){
        seg.assign(n,0);
    }

    void build(lli index,lli low,lli high,vector<lli> &arr){
        if(low == high){
            seg[index] = arr[low];
            return;
        }

        lli mid = (low + high) >> 1LL;
        build(2*index+1,low,mid,arr);
        build(2*index+2,mid+1,high,arr);
        seg[index] = max(seg[2*index+1], seg[2*index+2]);
    }

    void update(lli index,lli low ,lli high,lli ind,lli x){
        if(low == high){
            seg[index] -= x;
            return;
        }

        lli mid = (low + high) >> 1LL;
        if(mid < ind) update(2*index+2,mid+1,high,ind,x);
        else update(2*index+1,low,mid,ind,x);
        seg[index] = max(seg[2*index+1], seg[2*index+2]);
    }

    lli query(lli index,lli low ,lli high, lli x){
        if(seg[index] < x) return -1;
        if(low == high){
            return low;
        }

        lli mid = (low + high) >> 1LL;
        if(seg[2*index+1] >= x) return query(2*index+1,low ,mid, x);
        else return query(2*index+2, mid+1,high,x);
    }
};

void solve()
{
    lli n,q;
    cin>>n>>q;

    SGT sgt(4*n);
    
    vector<lli> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    sgt.build(0,0,n-1,vec);

    for(lli i=0;i<q;i++){
        lli x;
        cin>>x;

        lli ans = sgt.query(0,0,n-1,x);
        if(ans >= 0) sgt.update(0,0,n-1,ans,x);
        cout<<ans+1<<" ";
    }
}

signed main(){
    IOS
    solve();
    return 0;
}