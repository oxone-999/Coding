#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

struct Node{
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

Node* reverse_iterative(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* curr = head;
    Node* prev = NULL;
    
    while(curr){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

Node* reverse_recursive(Node* head){
    if(head->next == NULL){
        return head;
    }
    Node* node = head->next;
    Node* rev = reverse_recursive(head->next);
    node->next = head;
    head->next = NULL;
    return rev;
}

void solve()
{
    int n;
    cin>>n;
    Node* A = new Node(0);
    Node* res = A;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        A->val = x;
        A->next = new Node(0);
        A = A->next;
    }
    A = NULL;

    // res = reverse_iterative(res);
    res = reverse_recursive(res);

    res = res->next;
    while(res){
        cout<<res->val<<" ";
        res = res->next;
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    solve();
    return 0;
}