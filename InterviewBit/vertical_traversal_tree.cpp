#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9
#define fori(i,a,b) for(int i=a;i<b;i++)

struct treeNode {
    int val;
    treeNode *left, *right;
    treeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void verticalTraversal(treeNode* root, int hd, map<int, vector<int>>& m) {
    if(!root) return;
    m[hd].push_back(root->val);
    verticalTraversal(root->left, hd-1, m);
    verticalTraversal(root->right, hd+1, m);
}

void solve()
{
    treeNode* node = new treeNode(1);
    node->left = new treeNode(2);
    node->right = new treeNode(3);
    node->left->left = new treeNode(4);
    node->left->right = new treeNode(5);
    node->right->left = new treeNode(6);
    node->right->right = new treeNode(7);
    map<int, vector<int>> m;
    verticalTraversal(node, 0, m);

    for(auto it : m) {
        cout << it.first << ": ";
        fori(i,0,it.second.size()) cout << it.second[i] << " ";
        cout << endl;
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}