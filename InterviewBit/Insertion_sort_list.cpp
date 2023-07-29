#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* A) {
    ListNode* dummy = new ListNode(0);
    
    while(A)
    {
        int num = A->val;
        ListNode* temp = dummy;
        while(temp->next && temp->next->val < num)
        {
            temp = temp->next;
        }
        ListNode* node = temp->next;
        temp->next = new ListNode(num);
        temp = temp->next;
        temp->next = node;
        A = A->next;
    }
    return dummy->next;
}

void solve()
{
    ListNode* A;

    A = new ListNode(3);
    A->next = new ListNode(1);
    A->next->next = new ListNode(5);
    A->next->next->next = new ListNode(4);
    A = insertionSortList(A);
    while(A){
        cout<<A->val<<" ";
        A = A->next;
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}