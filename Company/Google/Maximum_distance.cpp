// You are given an array of binary strings ‘arr’ of size ‘N’. Your task is to find out the maximum distance between 
// the pair of strings.
// The distance between two binary strings is defined as the sum of their lengths after removing the common prefix.

struct Node{
    Node* list[2];
    
    bool containsKey(char ch){
        return list[ch-'0'] != NULL;
    }
    
    Node* next(char ch){
        return list[ch-'0'];
    }
    
    void new_node(char ch,Node* node){
        list[ch-'0'] = node;
    }
};

class Trie{
    Node* root;
    public: 
    
    Trie(){
        root = new Node();  
    }
    
    void insert(string words){
        Node* node = root;
        for(int i=0;i<words.size();i++)
        {
            if(!node->containsKey(words[i])){
                node->new_node(words[i],new Node());
            }
            node = node->next(words[i]);
        }
    }
    
    int rec(int &ans){
        Node* node = root;
        return diameter(node,ans);
    }
    
    int diameter(Node* node,int &ans){
        if(node == NULL) return 0;
        
        int left = 0;
        int right = 0;
        left = diameter(node->list[0],ans);
        right = diameter(node->list[1],ans);
        if(left>0 && right>0)
            ans = max(left+right,ans);
        return max(left,right)+1;
    }
};

int maximumDistance(vector<string> &arr)
{
    Trie trie;
    int n = arr.size();
    for(int i=0;i<n;i++)
        trie.insert(arr[i]);
    int ans = 0;
    trie.rec(ans);
    return ans;
}
