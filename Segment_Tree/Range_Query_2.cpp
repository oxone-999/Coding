#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5+7;

int a[N],tree[4*N];

void build(int index,int l,int r)
{
    if(l == r){
        tree[index] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*index,l,mid);
    build(2*index+1,mid+1,r);
    tree[index] = max(tree[2*index],tree[2*index+1]);
}

void update(int index,int l,int r,int lq,int rq,int val)
{
    if(lq>r || rq<l) return;
    if(lq<=l && rq>=r){
        tree[index] += val;
        return;
    }
    int mid = (l+r)/2;
    update(2*index,l,mid,lq,rq,val);
    update(2*index+1,mid+1,r,lq,rq,val);
    tree[index] = max(tree[2*index],tree[2*index+1]);
}

int queries(int index,int l,int r,int pos)
{
    if(l == r) return tree[index];
    int mid = (l+r)/2;
    if(pos<=mid)
        return queries(2*index,l,mid,pos);
    else
        return queries(2*index+1,mid+1,r,pos);
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

    cout<<tree[1]<<endl;
    cout<<tree[2]<<" "<<tree[3]<<endl;
    cout<<tree[4]<<" "<<tree[5]<<" "<<tree[6]<<" "<<tree[7]<<endl;
    cout<<tree[8]<<" "<<tree[9]<<" "<<tree[10]<<" "<<tree[11]<<" "<<tree[12]<<" "<<tree[13]<<" "<<tree[14]<<" "<<tree[15]<<endl;

    update(1,0,7,1,4,1);

    cout<<tree[1]<<endl;
    cout<<tree[2]<<" "<<tree[3]<<endl;
    cout<<tree[4]<<" "<<tree[5]<<" "<<tree[6]<<" "<<tree[7]<<endl;
    cout<<tree[8]<<" "<<tree[9]<<" "<<tree[10]<<" "<<tree[11]<<" "<<tree[12]<<" "<<tree[13]<<" "<<tree[14]<<" "<<tree[15]<<endl;
    return;

    for(int i=0;i<k;i++)
    {
        int ch;
        cin>>ch;
        if(ch == 1)
        {
            int l,r,val;
            cin>>l>>r>>val;
            update(1,0,n-1,l-1,r-1,val);
        }
        else if(ch == 2)
        {
            int x;
            cin>>x;
            int ans = queries(1,0,n-1,x-1);
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