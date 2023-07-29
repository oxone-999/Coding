//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

int ans = 0;

struct Node {
    Node *links[26];
    bool flag = false;
    //checks if the reference trie is present or not
    bool containKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }
    //creating reference trie
    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }
    //to get the next node for traversal
    Node *get(char ch) {
        return links[ch - 'a'];
    }
    //setting flag to true at the end of the word
    void setEnd() {
        flag = true;
    }
    //checking if the word is completed or not
    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
public:
    
    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(string word,int n,int st) {
        int x = 0;
        Node *node = root;
        for (int i = st; i < n; i++) {
            if (!node->containKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    void count(Node* node, int k ,string t){
        for(int i=0;i<26;i++){
            if(node->containKey(i+'a')){
                if(k-(t[i]=='0') >= 0){
                    ans++;
                    count(node->get(i+'a'),k-(t[i]=='0'),t);
                }
            }
        }
    }
};

void solve()
{
    Trie trie;

    string s;
    cin>>s;

    string t;
    cin>>t;

    int k;
    cin>>k;

    int n = s.size();

    for(int i=0;i<n;i++){
        trie.insert(s,n,i);
    }
    Node* node = trie.root;
    trie.count(node,k,t);
    cout<<ans<<endl;
}

signed main(){
    solve();
    return 0;
}