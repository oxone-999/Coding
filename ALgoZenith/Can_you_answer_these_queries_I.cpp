//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;
const lli N = -1e9;

struct Node{
    lli lSum,rSum,sum,maxi;
};

class SGT{
    public:
    vector<Node> seg;

    SGT(lli n){
        seg.resize(n);
    }

    Node merge(const Node &a,const Node &b){
        lli lSum = max(a.lSum,a.sum + b.lSum);
        lli rSum = max(b.rSum,b.sum + a.rSum);
        lli sum = a.sum + b.sum;
        lli maxi = max({a.maxi,b.maxi,a.rSum+b.lSum});
        return {lSum,rSum,sum,maxi};
    }

    void update(lli index,lli low,lli high,lli ind,lli val){
        if(low == high){
            // seg[index] = {max(val,0LL),max(val,0LL),val,max(val,0LL)};
            seg[index] = {val,val,val,val};
            return;
        }

        lli mid = (low + high) >> 1LL;
        if(mid < ind) update(2*index+2,mid+1,high,ind,val);
        else update(2*index+1,low,mid,ind,val);
        seg[index] = merge(seg[2*index+1], seg[2*index+2]);
    }

    Node query(lli index,lli low ,lli high, lli l, lli r){
        if(r < low || high < l) return {N,N,N,N};
        if(low >= l && high <= r){
            return seg[index];
        }

        lli mid = (low + high) >> 1LL;
        return merge(query(2*index+1,low ,mid,l,r), query(2*index+2,mid+1,high,l,r));
    }
};

void solve()
{
    lli n,m;
    cin>>n;

    SGT sgt(4*n);

    vector<lli> vec(n,0);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        sgt.update(0,0,n-1,i,x);
    }

    cin>>m;

    for(lli i=0;i<m;i++){
        lli l,r;
        cin>>l>>r;
        l--;r--;
        Node ans = sgt.query(0,0,n-1,l,r);
        cout<<ans.maxi<<endl;
    }
}

signed main(){
    IOS
    solve();
    return 0;
}