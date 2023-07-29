//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

struct Node {
    Node *links[26];
    bool flag = false;

    bool containKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }
    Node *get(char ch) {
        return links[ch - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    void dfs(Node* node, vector<string> &vec, string &str,int k){
        if(vec.size() >= k) return;
        if(node->isEnd()){
            vec.push_back(str);
        }
        
        for(int i=0;i<26;i++){
            if(node->containKey(i+'a')){
                str.push_back(i+'a');
                Node* cur = node->get(i+'a');
                dfs(cur,vec,str,k);
                str.pop_back();
            }
        }
    }

    vector<string> search(string &word,int k) {
        vector<string> ans;
        string str;
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containKey(word[i])) {
                return ans;
            }
            str.push_back(word[i]);
            node = node->get(word[i]);
        }

        dfs(node,ans,str,k);

        return ans;
    }
};

void solve()
{
    int n,maxlen,q;
    cin>>n>>maxlen>>q;

    Trie trie;

    map<string,int> mp;

    for(int i=0;i<n;i++){
        int m;
        string word;
        cin>>m>>word;
        mp[word]++;
        trie.insert(word);
    }

    for(int i=0;i<q;i++){
        int m;
        string word;
        int k;
        cin>>m>>word>>k;

        string s;
        for(int j=0;j<m;j++){
            s.push_back(word[j]);
            vector<string> ans = trie.search(s,k);
            int c = 0;
            bool f = true;
            for(auto it:ans){
                for(int t=0;t<mp[it];t++){
                    cout<<it<<" ";
                    c++;
                    if(c >= k){
                        f = false;
                        break;
                    }
                }
                if(f == false) break;
            }
            cout<<endl;
        }
    }
}

signed main(){
    IOS
    solve();
    return 0;
}