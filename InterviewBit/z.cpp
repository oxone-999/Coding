#include<bits/stdc++.h>
using namespace std;

#define INT_SIZE 32

struct TrieNode{
    int value;
    TrieNode *arr[2];
};

TrieNode* newNode(){
    TrieNode *temp = new TrieNode;
    temp->value = 0;
    temp->arr[0] = temp->arr[1] = NULL;
    return temp;
}

void insert(TrieNode *root, int pre_xor){
    TrieNode *temp = root;
    for(int i=INT_SIZE-1;i>=0;i--){
        bool val = pre_xor & (1<<i);
        if(temp->arr[val] == NULL){
            temp->arr[val] = newNode();
        }
        temp = temp->arr[val];
    }
    temp->value = pre_xor;
}

int query(TrieNode* root, int pre_xor){
    TrieNode *temp = root;
    for(int i=INT_SIZE-1;i>=0;i--){
        bool val = pre_xor & (1<<i);
        if(temp->arr[1-val] != NULL){
            temp = temp->arr[1-val];
        }
        else if(temp->arr[val] != NULL){
            temp = temp->arr[val];
        }
    }
    return pre_xor^(temp->value);
}

int maxSubarrayXOR(vector<int> arr,int start,int end){
    TrieNode* root = newNode();
    insert(root,0);

    int result = INT_MIN, pre_xor = 0;
    for(int i=start;i<=end;i++){
        pre_xor ^= arr[i];
        insert(root,pre_xor);
        result = max(result,query(root,pre_xor));
    }
    return result;
}

int maxSum(int N,vector<int> &A){
    int ans = 0;
    for(int i=0;i<N-1;i++){
        ans = max(ans,maxSubarrayXOR(A,0,i) + maxSubarrayXOR(A,i+1,N-1));
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxSum(n,arr)<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    solve();
    return 0;
}