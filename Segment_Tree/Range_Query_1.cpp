#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5+7;
int a[N],tree[4*N];

void build(int index,int l,int r)
{
    if(l == r)
    {
        tree[index] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*index,l,mid);
    build(2*index+1,mid+1,r);
    tree[index] = tree[2*index]+tree[2*index+1]; // merge logic, depends on question and query;
}

void update(int index,int l,int r,int pos,int val){
    if(pos<l || pos>r) return;
    if(l==r){
        tree[index] = val;
        a[l] = val;
        return;
    }
    int mid = (l+r)/2;
    update(2*index,l,mid,pos,val);
    update(2*index+1,mid+1,r,pos,val);
    tree[index] = tree[2*index] + tree[2*index+1];
}

long long queries(int index,int l,int r,int lq,int rq){
    if(lq>r || rq<l) return 0;
    if(lq<=l && rq>=r)
    {
        return tree[index];
    }
    int mid = (l+r)/2;
    return queries(2*index,l,mid,lq,rq) + queries(2*index+1,mid+1,r,lq,rq);
}

void solve()
{
    int n,k;
    cin>>n>>k;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    build(1,0,n-1);
    for(int i=0;i<k;i++)
    {
        int ch;
        cin>>ch;
        if(ch == 1){
            int pos,val;
            cin>>pos>>val;
            update(1,0,n-1,pos-1,val);
        }else{
            int l,r;
            cin>>l>>r;
            long long ans = queries(1,0,n-1,l-1,r-1);
            cout<<ans<<endl;
        }
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}