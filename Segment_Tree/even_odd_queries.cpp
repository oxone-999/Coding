#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5+7;
int a[N];

struct node{
    int even,odd,maxr;
    node(){
        even=0;
        odd=0;
        maxr=0;
    }
};

node merge(node a,node b){
    node temp;
    temp.even = a.even + b.even;
    temp.odd = a.odd + b.odd;
    temp.maxr = a.maxr + b.maxr;
    return temp;
}

node tree[4*N];

void build(int index,int l,int r){
    if(l == r){
        if(a[l] % 2 == 0){
            tree[index].even = 1;
            tree[index].odd = 0;
        }
        else{
            tree[index].odd = 1;
            tree[index].even = 0;
        } 
        tree[index].maxr = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*index,l,mid);
    build(2*index+1,mid+1,r);
    tree[index] = merge(tree[2*index],tree[2*index+1]);
}

void update(int index,int l,int r,int pos,int val){
    if(l == r)
    {
        if(val % 2 == 0)
        {
            tree[index].even = 1;
            tree[index].odd = 0;
        } 
        else 
        {
            tree[index].even = 0;
            tree[index].odd = 1;
        }
        tree[index].maxr = val;
        return;
    }
    int mid = (l+r)/2;
    if(pos<=mid){
        update(2*index,l,mid,pos,val);
    }else{
        update(2*index+1,mid+1,r,pos,val);
    }
    tree[index] = merge(tree[2*index],tree[2*index+1]);
}

node queries(int index,int l,int r,int lq,int rq){
    if(lq>r || rq<l) return node();
    if(lq<=l && rq>=r){
        return tree[index];
    }
    int mid = (l+r)/2;
    return merge(queries(2*index,l,mid,lq,rq),queries(2*index+1,mid+1,r,lq,rq));
}

void solve()
{
    int n,k;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    build(1,0,n-1);

    // cout<<tree[1].even<<endl;
    // cout<<tree[2].even<<""<<tree[3].even<<endl;
    // cout<<tree[4].odd<<""<<tree[5].odd<<""<<tree[6].odd<<""<<tree[7].odd<<endl;
    // cout<<tree[8].odd<<""<<tree[9].odd<<""<<tree[12].odd<<""<<tree[13].odd<<endl;

    // update(1,0,n-1,4,4);

    // cout<<tree[1].even<<endl;
    // cout<<tree[2].even<<""<<tree[3].even<<endl;
    // cout<<tree[4].even<<""<<tree[5].even<<""<<tree[6].even<<""<<tree[7].even<<endl;
    // cout<<tree[8].even<<""<<tree[9].even<<""<<tree[12].even<<""<<tree[13].even;


    // return;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int ch;
        cin>>ch;
        if(ch == 0){
            int pos,val;
            cin>>pos>>val;
            update(1,0,n-1,pos-1,val);
        }else{
            int l,r;
            cin>>l>>r;
            node ans = queries(1,0,n-1,l-1,r-1);
            // cout<<ans.odd<<" "<<ans.even<<" "<<ans.sum;
            (ch == 1) ? cout<<ans.even<<endl : cout<<ans.odd<<endl;
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