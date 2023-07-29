#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;

struct node{
    int sum,maxr,lazy;
    node(){
        sum = 0;
        maxr = 0;
        lazy = 0;
    }
};
node tree[4*N];

node merge(node a, node b){
    node temp;
    temp.sum = a.sum+b.sum;
    temp.maxr = max(a.maxr,b.maxr);
    return temp;
}

void push(int index,int l ,int r)
{
    if(tree[index].lazy)
    {
        tree[index].sum = tree[index].lazy * (r-l+1);
        tree[index].maxr = tree[index].lazy;
        if(l!=r)
        {
            tree[2*index].lazy = tree[index].lazy;
            tree[2*index+1].lazy = tree[index].lazy;
        }
        tree[index].lazy = 0;
    }
    else return;
}

void update(int index,int l,int r,int lq,int rq,int v)
{
    if(lq>r || rq<l) return;
    if(lq<=l && rq>=r)
    {
        tree[index].lazy = v;
        push(index,l,r);
        return;
    }
    int mid = (l+r)/2;
    update(2*index,l,mid,lq,rq,v);
    update(2*index+1,mid+1,r,lq,rq,v);
    tree[index] = merge(tree[2*index],tree[2*index+1]);
}

node queries(int index,int l,int r,int lq,int rq)
{
    push(index,l,r);
    if(lq>=r || rq<=l) return node();
    if(lq<=l && rq>=r)
    {
        return tree[index];
    }
    int mid = (l+r)/2;
    return merge(queries(2*index,l,mid,lq,rq),queries(2*index+1,mid+1,r,lq,rq));
}

void solve()
{
    update(1,0,9,0,5,3);
    update(1,0,9,6,9,4);
    node x = queries(1,0,9,3,6);
    cout<<x.sum<<" "<<x.maxr;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}