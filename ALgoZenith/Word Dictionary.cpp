#include <bits/stdc++.h>
using namespace std;

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

class WordDictionary {
    
    Node* root;

public:

	WordDictionary() {
        root = new Node();
	}

	void addWord(string word) {
		Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
	}

    bool solve(string word,int i,Node* node){
        if(i == word.size()){
            return node->flag;
        }

        bool ans = false;
        if(word[i] != '.'){
            if(node->containKey(word[i])) ans = solve(word,i+1,node->get(word[i]));
            else return false;
        }else{
            for(int j=0;j<26;j++){
                if(node->containKey(j+'a')){
                    ans |= solve(word,i+1,node->get(j+'a'));
                }
            }
        }
        return ans;
    }

	bool search(string word) {
		Node *node = root;
        return solve(word,0,root);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	WordDictionary* obj = new WordDictionary();

	int q;
	cin >> q;

	while (q--) {

		string op;
		cin >> op;

		if (op == "add") {
			string word;
			cin >> word;
			obj->addWord(word);
		}

		else {
			string word;
			cin >> word;
			if (obj->search(word))
				cout << "Yes\n";
			else
				cout << "No\n";
		}
	}
}