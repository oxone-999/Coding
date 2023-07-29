/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* merge(ListNode* A,ListNode* B)
{
    if(A == NULL) return B;
    else if(B == NULL) return A;
    
    if(A->val > B->val)
    {
        ListNode* temp = A;
        A = B;
        B = temp;
    }
    
    ListNode* res = A;
    
    while(A && B)
    {
        ListNode* temp = NULL;
        while(A && A->val <= B->val)
        {
            temp = A;
            A = A->next;
        }
        temp->next = B;
        
        ListNode* node = B;
        B = A;
        A = node;
    }
    return res;
} 

ListNode* mergeSort(ListNode* A)
{
    if(A && A->next)
    {
        ListNode* slow = A;
        ListNode* fast = A;
        
        //finding the middle node
        while(fast)
        {
            fast = fast->next;
            if(fast)
                slow = slow->next, fast = fast->next;
        }
        
        //dividing the list
        ListNode* curr = A;
        while(curr->next != slow)
            curr = curr->next;
        curr->next = NULL;
        curr = A;
        //calling for both halfs
        ListNode* X = mergeSort(A);
        ListNode* Y = mergeSort(slow);
        
        //merging two sorted lists
        return merge(X, Y);
    }
    else return A;
}
 
ListNode* Solution::sortList(ListNode* A) {
    return mergeSort(A);
}
