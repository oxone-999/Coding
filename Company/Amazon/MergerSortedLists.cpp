#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeSortedLists(ListNode* A,ListNode* B) {
    	ListNode* l1 = A;
    	ListNode* l2 = B;

        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(l1->val > l2->val) swap(l1,l2);
        
        ListNode* res = l1;
        
        while(l1 && l2)
        {
            ListNode* temp = l1;
            while(l1 && l1->val < l2->val)
            {
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;
            
            swap(l1,l2);
        }
        return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ListNode* A;
    ListNode* B;

    ListNode* ans = mergeSortedLists(A,B);
    
    return 0;
}