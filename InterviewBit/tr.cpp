#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    bool containsKey(char ch){
        return children[ch - 'a'] != NULL;
    }

    TrieNode* next(char ch){
        return children[ch - 'a'];
    }

    void new_node(char ch,TrieNode* node){
        children[ch - 'a'] = node;
    }

    bool isEndOfWord(){
        return isEnd;
    }

    void setEnd(){
        isEnd = true;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string &key) {
        TrieNode* cur = root;
        for(int i = 0; i < key.length(); i++) {
            if(!cur->containsKey(key[i])) {
                cur->new_node(key[i], new TrieNode());
            }
            cur = cur->next(key[i]);
        }
        cur->setEnd();
    }

    int count_numberOfNodes(TrieNode* node) {
        if(node == NULL) return 0;
        int count = 0;
        for(int i = 0; i < 26; i++) {
            if(node->children[i] != NULL) {
                count += count_numberOfNodes(node->children[i]);
            }
        }
        return count + 1;
    }
};

string common_string(string A,string B){
    set<char> s2;
    for(auto it:B){
        s2.insert(it);
    }
    string C;
    for(auto it:A){
        if(s2.find(it) != s2.end()){
            C.push_back(it);
            s2.erase(it);
        }
    }
    return C;
}

void solve()
{
    string A,B,C,D;
    cin>>A>>B>>C>>D;

    string E = common_string(B,C);
    string F = common_string(A,D);

    set<char> s;

    for(auto it:E){
        s.insert(it);
    }
    set<char> s2 = s;

    set<char> s3;

    for(auto it:F){
        s3.insert(it);
    }
    set<char> s4 = s3;

    string A1;
    string B1;
    string C1;
    string D1;

    for(auto it:A){
        if(s3.find(it) != s3.end()){
            s3.erase(it);
        }
        else A1.push_back(it);
    }

    s3 = s4;

    for(auto it:B){
        if(s.find(it) != s.end()){
            s.erase(it);
        }
        else B1.push_back(it);
    }

    s = s2;

    for(auto it:C){
        if(s.find(it) != s.end()){
            s.erase(it);
        }
        else C1.push_back(it);
    }

    s = s2;

    for(auto it:D){
        if(s3.find(it) != s3.end()){
            s3.erase(it);
        }
        else D1.push_back(it);
    }

    sort(A1.begin(),A1.end());
    sort(B1.begin(),B1.end());
    sort(C1.begin(),C1.end());
    sort(D1.begin(),D1.end());

    sort(E.begin(),E.end());
    sort(F.begin(),F.end());
    A = F + A1;
    B = E + B1;
    C = E + C1;
    D = F + D1;

    cout<<A<<endl<<B<<endl<<C<<endl<<D<<endl;

    Trie trie;

    trie.insert(A);
    trie.insert(B);
    trie.insert(C);
    trie.insert(D);

    cout<<trie.count_numberOfNodes(trie.root)<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--) solve();
    return 0;
}