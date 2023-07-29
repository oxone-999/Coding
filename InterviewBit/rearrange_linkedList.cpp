#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

struct LinkedListNode {
    int val;
    LinkedListNode *next;
    LinkedListNode(int x) : val(x), next(NULL) {}
};

LinkedListNode* reverse_linkedList(LinkedListNode* head) {
    LinkedListNode* prev = NULL;
    LinkedListNode* curr = head;
    LinkedListNode* next;
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

LinkedListNode* reorder_linkedList(LinkedListNode* head) {
    if(!head || !head->next) return head;
    LinkedListNode *slow = head, *fast = head;
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    LinkedListNode *mid = slow->next;
    slow->next = NULL;
    mid = reverse_linkedList(mid);
    LinkedListNode *curr = head;
    while(curr && mid) {
        LinkedListNode *temp = curr->next;
        curr->next = mid;
        mid = mid->next;
        curr->next->next = temp;
        curr = temp;
    }
    return head;
}

struct treeNode {
    int val;
    treeNode *left, *right;
    treeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder_iterative(treeNode* root) {
    stack<treeNode*> st;
    treeNode* curr = root;
    while(curr || !st.empty()) {
        while(curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout<<curr->val<<" ";
        curr = curr->right;
    }
}

void print_linkedList(LinkedListNode* head) {
    while(head) {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

void solve()
{
    LinkedListNode* head = new LinkedListNode(1);
    head->next = new LinkedListNode(2);
    head->next->next = new LinkedListNode(3);
    head->next->next->next = new LinkedListNode(4);
    head->next->next->next->next = new LinkedListNode(5);
    head->next->next->next->next->next = new LinkedListNode(6);
    head->next->next->next->next->next->next = new LinkedListNode(7);
    print_linkedList(head);
    head = reorder_linkedList(head);
    print_linkedList(head);
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}