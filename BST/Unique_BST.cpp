struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(), right() {}
};
 
#include<bits/stdc++.h>
using namespace std;

//main code
vector<TreeNode *> constructTrees(int start, int end)
{
    vector<TreeNode *> list;
 
    if (start > end)
    {
        list.push_back(NULL);
        return list;
    }
 
    for (int head = start; head <= end; head++)
    {
        vector<TreeNode *> leftSubtree  = constructTrees(start, head - 1);
        vector<TreeNode *> rightSubtree = constructTrees(head + 1, end);
 
        for (int j = 0; j < leftSubtree.size(); j++)
        {
            TreeNode* left = leftSubtree[j];
            for (int k = 0; k < rightSubtree.size(); k++)
            {
                TreeNode* right = rightSubtree[k];
                TreeNode* node = new TreeNode(head);
                node->left = left;            
                node->right = right;           
                list.push_back(node);          
            }
        }
    }
    return list;
}

//Practice code
// vector<TreeNode*> constructTrees(int start,int end){
//     vector<TreeNode*> vec;

//     if(start>end){
//         return {};
//     }

//     for(int head = start ; head < end ;head++){
//         vector<TreeNode*> leftTree = constructTrees(start,head-1);
//         vector<TreeNode*> rightTree = constructTrees(head+1,end);

//         for(int j = start;j < head-1;j++){
//             TreeNode* left = leftTree[j];
//             for(int k = head+1;k<end;k++){
//                 TreeNode* right = rightTree[k];

//                 TreeNode* node = new TreeNode(head);
//                 node->left = left;
//                 node->right = right;
//                 vec.push_back(node);
//             }
//         }
//     }
// }

vector<TreeNode*> generateTrees(int A) {
    return constructTrees(1,A);
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--)
    {
        int A;
        cin>>A;
        vector<TreeNode *> vec = generateTrees(A); 
    }
    return 0;
}
