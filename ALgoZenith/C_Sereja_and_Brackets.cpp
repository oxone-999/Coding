//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

struct Node{
    lli open,close,full;
};

class SGT{
    public:

    vector<Node> seg;
    SGT(lli n){
        seg.assign(n,{0,0,0});
    }

    Node merge(const Node &a, const Node &b){
        lli full = a.full + b.full + min(a.open,b.close);
        lli open = a.open + b.open - min(a.open,b.close);
        lli close = a.close + b.close - min(a.open, b.close);
        Node c = {open,close,full};
        return c;
    }

    void build(lli index,lli low ,lli high, string &str){
        if(low == high){
            if(str[low] == '(') seg[index].open = 1;
            else seg[index].close = 1;
            return;
        }

        lli mid = (low + high) >> 1LL;
        build(2*index + 1, low , mid, str);
        build(2*index + 2, mid+1, high, str);
        seg[index] = merge(seg[2*index + 1],seg[2 * index + 2]);
    }

    Node query(lli index,lli low ,lli high,lli l ,lli r){
        if(r < low || high < l) return {0,0,0};
        if(low >= l && high <= r) return seg[index];
        lli mid = (low + high) >> 1LL;
        return merge(query(2*index + 1,low,mid,l,r), query(2*index + 2,mid+1,high,l,r));
    }
};

void solve()
{
    string s;
    cin>>s;
    lli n = s.size();

    lli q;
    cin>>q;

    SGT st(4*n);
    st.build(0,0,n-1,s);
    // cerr<<"sdfsd"<<endl;

    for(lli i=0;i<q;i++){
        lli l,r;
        cin>>l>>r;
        l--;
        r--;
        Node ans = st.query(0,0,n-1,l,r);
        cout<<2*ans.full<<endl;
    }
}

signed main(){
    IOS
    solve();
    return 0;
}