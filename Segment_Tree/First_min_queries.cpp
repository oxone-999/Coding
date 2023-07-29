#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5+7;
int a[N],tree[4*N];

void build(int index,int l,int r){
    if(l == r){
        tree[index] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*index,l,mid);
    build(2*index+1,mid+1,r);
    tree[index] = max(tree[2*index],tree[2*index+1]);
}

void update(int index,int l,int r,int pos,int val){
    if(l == r){
        tree[index] -= val;
        return;
    }
    int mid = (l+r)/2;
    if(pos<=mid)
        update(2*index,l,mid,pos,val);
    else 
        update(2*index+1,mid+1,r,pos,val);
    tree[index] = max(tree[2*index],tree[2*index+1]);
}

int query(int index,int l,int r,int x){
    if(l == r){
        return (tree[index]<x) ? INT_MAX : l;
    }
    int mid = (l+r)/2;
    int left = INT_MAX;
    int right = INT_MAX;
    if(tree[index] >= x)
    {
        if(tree[2*index] >= x)
            left = query(2*index,l,mid,x);
        else if(tree[2*index+1] >= x) 
            right = query(2*index+1,mid+1,r,x);
    }
    return min(left,right);
}

void solve()
{
    int n,k;
    cin>>n>>k;

    for(int i=0;i<n;i++)
        cin>>a[i];

    build(1,0,n-1);

    for(int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        int ind = query(1,0,n-1,x);
        if(ind == INT_MAX) cout<<0<<" ";
        else {
            cout<<ind+1<<" ";
            update(1,0,n-1,ind,x);
        }  
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t = 1;
    while(t--)
    {
        solve();
    }
    return 0;
}