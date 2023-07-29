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
    lli q;
    cin>>q;

    Trie trie;
    trie.insert(0);

    for(lli i=0;i<q;i++){
        char c;
        cin>>c;
        lli n;
        cin>>n;
        if(c == '+'){
            trie.insert(n);
        }else if(c == '-'){
            trie.Delete(n);
        }else{
            lli ans = trie.maxXor(n);
            cout<<ans<<endl;
        }   
    }
}

signed main(){
    IOS
    solve();
    return 0;
}