//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

const lli BT = 32;

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

    lli Xor(lli val,int k){
        node *curNode = root;
        lli count = 0;

        for(lli i=BT-1;i>=0;i--){
            if(curNode == NULL) break;

            lli bit = (val & (1LL<<i)) ? 1 : 0;
            lli kbit = (k & (1LL<<i)) ? 1 : 0;

            if(bit == kbit){
                if(kbit){
                    if(curNode->child[1]) count += curNode->child[1]->cnt; 
                }
                curNode = curNode->child[0];    
            }
            else{
                if(kbit){
                    if(curNode->child[0]) count += curNode->child[0]->cnt;
                }
                curNode = curNode->child[1];
            }
        }
        return count;
    }
};

void solve()
{
    lli n,k;
    cin>>n>>k;

    Trie trie;

    vector<lli> vec(n+1,0);
    for(lli i=1;i<=n;i++){
        cin>>vec[i];
    }
    trie.insert(0);

    lli ans = 0;
    lli pre = 0;
    for(lli i=1;i<=n;i++){
        pre ^= vec[i];
        ans += trie.Xor(pre,k);
        trie.insert(pre);
    }

    cout<<ans<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}