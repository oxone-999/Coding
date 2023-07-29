#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
int a[N];
int tree[4*N];

void build(int index,int l,int r)
{
    if(l == r)
    {
        tree[index] = 1;
        return;
    }
    int mid = (l+r)/2;
    build(2*index,l,mid);
    build(2*index+1,mid+1,r);
    tree[index] = tree[2*index] + tree[2*index+1];
}

int query(int index,int l,int r,int k)
{
    if(l == r)
    {
        return a[l+1];
    }
    int mid = (l+r)/2;
    if(k <= tree[index])
        return query(2*index,l,mid,k);
    else 
        return query(2*index+1,mid+1,r,k-tree[index]);
}

void solve()
{
    int n,q;
    cin>>n>>q;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    build(1,0,n-1);

    for(int i=0;i<q;i++)
    {
        int ch;
        cin>>ch;
        if(ch = 1)
        {
            int l,r,k;
            cin>>l>>r>>k;
            cout<<query(1,l,r,k)<<endl;   
        }
    }
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