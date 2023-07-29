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

    vector<pair<lli,lli>> sgt;

    SGT(lli n){
        sgt.resize(4*n);
    }

    pair<lli,lli> merge(const pair<lli,lli> &a,const pair<lli,lli> &b){
        vector<lli> v;
        v.push_back(a.first);
        v.push_back(a.second);
        v.push_back(b.first);
        v.push_back(b.second);
        sort(all(v),greater<lli>());
        return {v[0],v[1]};
    }

    void build(lli index,lli low,lli high,vector<lli> &arr){
        if(low == high){
            sgt[index] = {arr[low],arr[high]};
            return;
        }

        lli mid = (low + high) >> 1LL;
        build(2*index+1,low , mid,arr);
        build(2 * index+2,mid+1,high,arr);
        sgt[index] = merge(sgt[2*index+1],sgt[2*index+2]); 
    }

    void update(lli index, lli low, lli high, lli i, lli val){
        if(low == high){
            sgt[index] = {val,val};
            return;
        }

        lli mid = (low + high) >> 1LL;
        if(mid < i){
            update(2*index+2,mid+1,high,i,val);
        }else update(2*index+1, low, mid,i, val);

        sgt[index] = merge(sgt[2*index+1], sgt[2*index+2]);
    }

    pair<lli,lli> query(lli index,lli low ,lli high,lli l,lli r){
        if(r < low || high < l){
            return {INT_MIN,INT_MIN};
        }

        if(low >= l && high <= r){
            return sgt[index];
        }
        lli mid = (low + high) >> 1LL;
        return merge(query(2*index+1,low,mid,l,r), query(2*index+2,mid+1,high,l,r));
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

    lli q;
    cin>>q;

    SGT sgt(n);
    sgt.build(0,0,n-1,vec);

    for(lli i=0;i<q;i++){
        char ch;
        lli l,r;
        cin>>ch>>l>>r;
        l--;
        r--;

        if(ch == 'U'){
            sgt.update(0,0,n-1,l,r);       
        }else{
            pair<lli,lli> ans = sgt.query(0,0,n-1,l,r);
            cout<<(ans.first+ans.second)<<endl;
        }
    }
}

signed main(){
    IOS
    solve();
    return 0;
}