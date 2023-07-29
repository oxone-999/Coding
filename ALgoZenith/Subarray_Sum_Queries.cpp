//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

struct Node{
    lli lSum,rSum,sum,maxi;
};

class SGT{
    public:
    vector<Node> seg;

    SGT(lli n){
        seg.assign(n,{0,0,0,0});
    }

    Node merge(const Node &a,const Node &b){
        lli lSum = max(a.lSum,a.sum + b.lSum);
        lli rSum = max(b.rSum,b.sum + a.rSum);
        lli sum = a.sum + b.sum;
        lli maxi = max({a.maxi,b.maxi,a.rSum+b.lSum});
        return {lSum,rSum,sum,maxi};
    }

    void build(lli index,lli low ,lli high,vector<lli> &vec){
        if(low == high){
            seg[index] = {vec[low],vec[low],vec[low],vec[low]};
            return;
        }

        lli mid = (low + high) >> 1LL;
        build(2*index+1,low,mid,vec);
        build(2*index+2,mid+1,high,vec);
        seg[index] = merge(seg[2*index+1],seg[2*index+2]);
    }

    void update(lli index,lli low,lli high,lli ind,lli val){
        if(low == high){
            seg[index] = {max(val,0LL),max(val,0LL),val,max(val,0LL)};
            return;
        }

        lli mid = (low + high) >> 1LL;
        if(mid < ind) update(2*index+2,mid+1,high,ind,val);
        else update(2*index+1,low,mid,ind,val);
        seg[index] = merge(seg[2*index+1], seg[2*index+2]);
    }
};

void solve()
{
    lli n,m;
    cin>>n>>m;

    vector<lli> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    SGT sgt(4*n);
    sgt.build(0,0,n-1,vec);

    for(lli i=0;i<m;i++){
        lli x,val;
        cin>>x>>val;
        x--;
        sgt.update(0,0,n-1,x,val);
        lli lSum = sgt.seg[0].lSum;
        lli rSum = sgt.seg[0].rSum;
        lli sum = sgt.seg[0].sum;
        lli maxi = sgt.seg[0].maxi;
        lli ans = max({lSum,rSum,sum,maxi});
        cout<<ans<<endl;
    }
}

signed main(){
    IOS
    solve();
    return 0;
}