#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool search(TreeNode* root,int x){
    if(root == NULL) return false;
    if(root->val == x) return true;

    bool l(false),r(false);
    if(x > root->val) l = search(root->right,x);
    else if(x < root->val) r = search(root->left,x);
    return l | r;
}

void insert(TreeNode* root,int x){
    if(root->val == x) return; 
    if(x > root->val) {
        if(root->right) insert(root->right,x);
        else {
            root->right = new TreeNode(x);
            return;
        } 
    }
    else {
        if(root->left) insert(root->left,x);
        else {
            root->left = new TreeNode(x);
            return;
        } 
    }
    return;
}

void inorder(TreeNode* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void insertNode(TreeNode* root,int x){
    if(root == NULL) {
        root = new TreeNode(x);
        return;
    }
    if(x > root->val) {
        if(root->right) insertNode(root->right,x);
        else {
            root->right = new TreeNode(x);
            return;
        } 
    }
    else {
        if(root->left) insertNode(root->left,x);
        else {
            root->left = new TreeNode(x);
            return;
        } 
    }
    return;
}

TreeNode* insert_Node(TreeNode* root,int x){
    if(root == NULL) {
        root = new TreeNode(x);
        return root;
    }
    if(x > root->val) {
        if(root->right) root->right = insert_Node(root->right,x);
        else {
            root->right = new TreeNode(x);
            return root->right;
        } 
    }
    else {
        if(root->left) root->left = insert_Node(root->left,x);
        else {
            root->left = new TreeNode(x);
            return root->left;
        } 
    }
    return root;
}

void delete_Node(TreeNode* &root,int x){ // delete node with value x
    if(root == NULL) return;
    if(root->val == x) {
        if(root->left == NULL && root->right == NULL) {
            root = NULL;
        }
        else if(root->left == NULL) root = root->right;
        else if(root->right == NULL) root = root->left;
        else {
            TreeNode* node = root->right;
            TreeNode* temp = root->left;
            while(temp->left || temp->right){
                if(temp->right) temp = temp->right;
                else temp = temp->left;
            }
            temp->right = node;
            root = temp;
        }
        return;
    }
    if(x > root->val) delete_Node(root->right,x);
    if(x < root->val) delete_Node(root->left,x);
}

void inorder_tree(TreeNode* root,vector<int> &vec){
    if(root == NULL) return;
    inorder_tree(root->left,vec);
    vec.push_back(root->val);
    inorder_tree(root->right,vec);
}

void tree_to_bst(TreeNode* root,vector<int>& vec,int &x){
    if(root == NULL) return;
    tree_to_bst(root->left,vec,x);
    x++;
    root->val = vec[x];
    tree_to_bst(root->right,vec,x);
}

//4
//2 6
//1 3 5 7

void print_level_order(TreeNode* root){
    if(root == NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        if(temp){
            cout<<temp->val<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }else{
            if(!q.empty()){
                q.push(NULL);
                cout<<endl;
            } 
        }
    }
}

void solve()
{
    int n;
    cin>>n;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    // cout<<search(root,n)<<endl;
    // insert(root,n);
    // delete_Node(root,n);
    vector<int> vec;
    inorder_tree(root,vec);
    sort(vec.begin(),vec.end());
    // for(auto x:vec) cout<<x<<" ";
    int x = -1;
    tree_to_bst(root,vec,x);
    print_level_order(root);
    // inorder(root);
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    solve();
    return 0;
}