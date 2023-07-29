// Given a binary tree T, find the maximum path sum.

// The path may start and end at any node in the tree.

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

int solve(TreeNode* A,int &res)
{
    if(A == NULL) return 0;
    int left = solve(A->left,res);
    int right = solve(A->right,res);

    int temp = max(max(left,right)+A->val,A->val);
    int ans = max(temp,left+right+A->val);
    res = max(res,ans);
    return temp;
}

int maxPathSum(TreeNode* A) {
    int res = INT_MIN;
    solve(A,res);
    return res;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    TreeNode* A = new TreeNode(1);
    maxPathSum(A);
    return 0;
}
