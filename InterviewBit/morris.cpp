#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

struct Tree{
    int val;
    Tree *left, *right;
    Tree(int v): val(v), left(NULL), right(NULL){}
};

Tree* morris(Tree* root){
    Tree *curr = root, *prev = NULL;
    while(curr){
        if(!curr->left){
            cout<<curr->val<<" ";
            curr = curr->right;
        }
        else{
            prev = curr->left;
            while(prev->right && prev->right != curr){
                prev = prev->right;
            }
            if(!prev->right){
                prev->right = curr;
                curr = curr->left;
            }
            else{
                prev->right = NULL;
                cout<<curr->val<<" ";
                curr = curr->right;
            }
        }
    }
    return root;
}

stack<pair<Tree*,int>> s;
vector<int> preorder;
vector<int> inorder;
vector<int> postorder;

void preorder_inorder_postorder(stack<pair<Tree*,int>> &s){
    if(s.empty()) return;
    Tree* node = s.top().first;
    int num = s.top().second;
    s.pop();
    if(num == 1){
        preorder.push_back(node->val);
        num++;
        s.push({node,num});
        if(node->left) s.push({node->left,1});
    }else if(num == 2){
        inorder.push_back(node->val);
        num++;
        s.push({node,num});
        if(node->right) s.push({node->right,1});
    }else{
        postorder.push_back(node->val);
    }
    preorder_inorder_postorder(s);
}

void vector_print(vector<int> &vec){
    for(auto &it:vec){
        cout<<it<<" ";
    }
    cout<<endl;
}

void print_tree(Tree* head){
    if(head == NULL) return;
    print_tree(head->left);
    cout<<head->val<<" ";
    print_tree(head->right);
}

void solve()
{
    Tree* node = new Tree(1);
    node->left = new Tree(2);
    node->right = new Tree(3);
    node->left->left = new Tree(4);
    node->left->right = new Tree(5);
    node->right->left = new Tree(6);
    node->right->right = new Tree(7);
    // print_tree(node);
    s.push({node,1});
    preorder_inorder_postorder(s);

    vector_print(preorder);
    vector_print(inorder);
    vector_print(postorder);
    // return morris(head);
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;while(t--) solve();
    return 0;
}