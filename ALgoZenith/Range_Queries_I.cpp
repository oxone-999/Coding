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

    void build (lli index,lli low,lli high,vector<lli> &arr){
        if(low == high){
            seg[index] = arr[low]; 
            return;
        }

        lli mid = (low + high) >> 1;
        build(2*index+1,low,mid,arr);
        build(2*index+2,mid+1,high,arr);
        seg[index] = seg[2*index+1] + seg[2*index + 2];
    }

    void update(lli index,lli low,lli high,lli ind,lli val){
        if(low == high){
            seg[index] = val;
            return;
        }

        lli mid = (low+high) >> 1;
        if(mid < ind){
            update(2*index+2,mid+1,high,ind, val);
        }else update(2*index+1,low,mid,ind,val);

        seg[index] = seg[2*index+1] + seg[2*index+2];
    }

    lli query(lli index,lli low,lli high,lli l, lli r){
        if(r < low || high < l){
            return 0;
        }

        if(low >= l && high <= r){
            return seg[index];
        }
        lli mid = (low + high) >> 1;
        return query(2*index+1,low,mid,l,r) + query(2*index+2,mid+1,high,l,r);
    }
};

void solve()
{
    lli n,q;
    cin>>n>>q;

    vector<lli> vec(n,0);

    for(auto &it:vec){
        cin>>it;
    }

    SGT sgt(4*n);
    sgt.build(0,0,n-1,vec);

    for(lli i=0;i<q;i++){
        lli type,x,val;
        cin>>type>>x>>val;
        x--;

        if(type == 1){
            sgt.update(0,0,n-1,x,val);
        }else{
            cout<<sgt.query(0,0,n-1,x,val-1)<<endl;
        }
    }
}

signed main(){
    IOS
    solve();
    return 0;
}