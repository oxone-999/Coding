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

    //even and odd
    vector<pair<lli,lli>> seg;
    SGT(lli n){
        seg.assign(n,{0,0});
    }

    pair<lli,lli> merge(const pair<lli,lli> &a,const pair<lli,lli> &b){
        lli even = a.first + b.first;
        lli odd = a.second + b.second;
        return {even,odd};
    }

    void build(lli index,lli low ,lli high,vector<lli> &arr){
        if(low == high){
            if(arr[low] % 2 == 0){
                seg[index].first = 1;
            }else seg[index].second = 1;
            return;
        }

        lli mid = (low + high) >> 1;
        build(2*index+1,low,mid,arr);
        build(2*index+2,mid+1,high,arr);
        seg[index] = merge(seg[2*index+1], seg[2*index+2]);
    }

    void update(lli index,lli low ,lli high,lli ind, lli val){
        if(low == high){
            if(val % 2 == 0){
                seg[index].first = 1;
                seg[index].second = 0;
            }else{
                seg[index].first = 0;
                seg[index].second = 1;
            }
            return;
        }

        lli mid = (low + high) >> 1LL;
        if(mid < ind){
            update(2*index+2,mid+1,high,ind,val);
        }else update(2*index+1,low ,mid,ind,val);
        seg[index] = merge(seg[2*index+1], seg[2*index+2]);
    }

    pair<lli,lli> query(lli index,lli low,lli high,lli l,lli r){
        if(high < l || r < low) return {0,0};

        if(low >= l && high <= r){
            return seg[index];
        }

        lli mid = (low + high) >> 1LL;
        return merge(query(2*index+1,low ,mid,l,r),query(2*index+2,mid+1,high,l,r));
    }
};

void solve()
{
    lli n;
    cin>>n;

    vector<lli> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    SGT sgt(4*n);
    sgt.build(0,0,n-1,vec);

    lli q;
    cin>>q;

    for(lli i=0;i<q;i++){
        lli type;
        cin>>type;

        if(type == 0){
            lli x,y;
            cin>>x>>y;
            x--;
            sgt.update(0,0,n-1,x,y);
        }else if(type == 1){
            lli l,r;
            cin>>l>>r;
            l--;
            r--;
            cout<<sgt.query(0,0,n-1,l,r).first<<endl;
        }else{
            lli l,r;
            cin>>l>>r;
            l--;
            r--;
            cout<<sgt.query(0,0,n-1,l,r).second<<endl;
        }
    }
}

signed main(){
    IOS
    solve();
    return 0;
}