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

    void update(lli index,lli low,lli high,lli l,lli r,lli val){
        if(r < low || high < l){
            return;
        }

        if(low >= l && high <= r){
            seg[index] += val;
        }else{
            lli mid = (low + high) >> 1LL;
            update(2*index+1,low, mid,l,r,val);
            update(2*index+2,mid+1,high,l,r,val);
        }
    }

    lli query(lli index,lli low ,lli high, lli ind){
        if(low == high){
            return seg[index];
        }
        lli mid = (low+high) >> 1LL;
        if(mid < ind){
            return seg[index] + query(2*index+2,mid+1,high,ind);
        }   
        return seg[index] + query(2*index+1,low, mid,ind);
    }
};

void solve()
{
    lli n,q;
    cin>>n>>q;

    SGT sgt(4*n);

    for(lli i=0;i<n;i++){
        lli x;
        cin>>x;
        sgt.update(0,0,n-1,i,i,x);
    }


    for(lli i=0;i<q;i++){
        lli type;
        cin>>type;

        if(type == 1){
            lli l,r,x;
            cin>>l>>r>>x;
            l--;
            r--;
            sgt.update(0,0,n-1,l,r,x);
        }else{
            lli x;
            cin>>x;
            x--;
            cout<<sgt.query(0,0,n-1,x)<<endl;
        }
    }
}

signed main(){
    IOS
    solve();
    return 0;
}