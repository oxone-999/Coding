#include <bits/stdc++.h>

using namespace std;
struct Node {
  Node * links[26];
  bool flag = false;

  bool containsKey(char ch) {
    return (links[ch - 'a'] != NULL);
  }
  Node * get(char ch) {
    return links[ch - 'a'];
  }
  void put(char ch, Node * node) {
    links[ch - 'a'] = node;
  }
  void setEnd() {
    flag = true;
  }
  bool getEnd() {
    return flag;
  }
};
class Trie {
  private:
    Node * root;

  public:
    Trie() {
      root = new Node();
    }

  void insert(string word) {
    Node * node = root;
    Node* nn = root;
    for (int i = 0; i < word.length(); i++) {
      if (!node -> containsKey(word[i])) {
        node -> put(word[i], new Node());
      }
      nn = node;
      node = node->get(word[i]);
    }
    node->setEnd();
  }

  void dfs(Node* head,string str,int &cnt){
    if(head->getEnd()) cnt++;
    
    for(int i=0;i<26;i++)
    {
        Node* node = head;
        string s = str;
        if(node->containsKey(i+'a'))
        {
          s.push_back(i+'a');
          node = node->get(i+'a');
          dfs(node,s,cnt);
        }
    }
  }

  int wordsStartingWith(string &word) {
    Node* node = root;
    int cnt = 0;
    string s;

    for (int i = 0; i < word.length(); i++) {
      if (node -> containsKey(word[i])) {
        node = node -> get(word[i]);
        s.push_back(word[i]);
      } else break;
    } 
    dfs(node,s,cnt);
    return cnt;
  }
};

int main(){
  Trie T;

  ifstream myfile;
  myfile.open("dictionary.txt");
  
  string myline;

  if ( myfile.is_open() ) {
    while ( myfile ) {
      getline (myfile, myline);
      cout << myline << '\n';
    }
  }
  else {
    cout << "Couldn't open file\n";
  }

  T.insert("apple");
  T.insert("apekjh");
  T.insert("apkhpslkblkk");
  T.insert("ap");
  T.insert("apdfsdgf");
  T.insert("aksdgsdg");
  T.insert("adafadf");
  T.insert("ap");
  
  int n;
  cin>>n;

  for(int i=0;i<n;i++)
  {
    vector<string> vec;
    string s;
    cin>>s;
    cout<<T.wordsStartingWith(s);
  }
  return 0;
}