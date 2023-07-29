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
    vector<int> sgt;
    SGT(int n){
        sgt.assign(4*n,0);
    }

    void build(int index,int low,int high,vector<int> &arr, int orr){
        if(low == high){
            sgt[index] = arr[low];
            return;
        }

        int mid = (low + high) >> 1;
        build(2*index + 1, low, mid, arr , !orr);
        build(2*index + 2, mid+1,high, arr , !orr);

        if(orr){
            sgt[index] = sgt[2*index + 1] | sgt[2*index + 2];
        }else sgt[index] = sgt[2*index + 1] ^ sgt[2*index + 2];
    }

    void update(int index,int low,int high, int ind, int val, int orr){
        if(low == high){
            sgt[index] = val;
            return;
        }

        int mid = (low + high) >> 1;
        if(mid < ind){
            update(2*index+2, mid+1,high, ind, val, !orr);
        }else update(2*index+1, low ,mid, ind ,val, !orr);

        if(orr){
            sgt[index] = sgt[2*index+1] | sgt[2*index+2];
        }else sgt[index] = sgt[2*index + 1] ^ sgt[2*index + 2];
    }
};

void solve()
{
    int n,q;
    cin>>n>>q;

    int N = (1LL<<n);

    SGT sgt(N);

    vector<int> arr(N,0);
    for(auto &it:arr){
        cin>>it;
    }

    int orr = 0;

    if(n % 2 == 0){
        orr = 0; // xor
    }else orr = 1; // or

    sgt.build(0,0,N-1,arr,orr);

    for(int i=0;i<q;i++){
        int x,val;
        cin>>x>>val;
        sgt.update(0,0,N-1,x-1,val,orr);
        cout<<sgt.sgt[0]<<endl;
    }
}

signed main(){
    IOS
    solve();
    return 0;
}