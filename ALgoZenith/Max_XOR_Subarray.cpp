//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

const lli BT = 64;
struct node{
    node *child[2];
    lli cnt;

    node(){
        cnt = 0;
        child[0] = NULL;
        child[1] = NULL;
    }
};

class Trie{
    private:
    node *root;

    public:
    Trie(){
        root = new node();
    }

    void insert(lli val){
        node* curNode = root;
        for(lli i=BT-1;i>=0;i--){
            lli x = (val & (1LL<<i)) ? 1 : 0;
            if(curNode->child[x] == NULL){
                curNode->child[x] = new node();
            }
            curNode = curNode->child[x];
            curNode->cnt++;
        }
    }

    void Delete(lli val){
        node* curNode = root;
        for(lli i=BT-1;i>=0;i--){
            lli x = (val & (1LL<<i)) ? 1 : 0;
            if(curNode->child[x] == NULL) return;
            curNode->child[x]->cnt--;
            curNode = curNode->child[x];
        }
    }

    lli maxXor(lli val){
        node *curNode = root;
        lli ans = 0;

        for(lli i=BT-1;i>=0;i--){
            lli x = (val & (1LL<<i)) ? 1 : 0;
            if(curNode->child[!x] != NULL && curNode->child[!x]->cnt > 0){
                curNode = curNode->child[!x];
                ans = ans | (1LL << i);
            }else{
                curNode = curNode->child[x];
            }
        }
        return ans;
    }
};

void solve()
{
    lli n;
    cin>>n;

    Trie trie;

    vector<lli> vec(n+1,0);
    for(lli i=1;i<=n;i++){
        cin>>vec[i];
    }

    vector<lli> pre(n+1,0);

    for(lli i=1;i<=n;i++){
        pre[i] = pre[i-1]^vec[i];
    }

    for(lli i=1;i<=n;i++){
        trie.insert(pre[i]);
    }
    lli ans = 0;
    for(lli i=0;i<=n;i++){
        ans = max(ans,trie.maxXor(pre[i]));
    }

    cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}