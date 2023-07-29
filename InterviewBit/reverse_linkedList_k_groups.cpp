#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
	int data;
	ListNode* next;

	ListNode(int data) {
		this->data = data;
		this->next = NULL;
	}
};

pair<ListNode* ,ListNode*> reverse(ListNode* head){
	if(head == NULL || head->next == NULL) return {head,head};
	
	ListNode* newHead = head->next;
	ListNode* rev = reverse(head->next).first;
	newHead->next = head;
	head->next = NULL;
	return {rev,head};
}

ListNode* reverseLinkedListKGroup(ListNode* head, int k) {
	ListNode* curr = head;
	ListNode* temp = head;
	ListNode* prev = NULL;
	int c = k;
	while(temp && c--){
		prev = temp;
		temp = temp->next;
	}
	if(temp == NULL && c != 0) return curr;
	
	prev->next = NULL;
	pair<ListNode*,ListNode*> x = reverse(curr);
	ListNode* h = x.first;
	ListNode* t = x.second;
	
	t->next = reverseLinkedListKGroup(temp,k);
	
	return h;
}

ListNode* reverseLinkedListKGroup(ListNode* head, int k) {
	ListNode* curr = head;
	ListNode* gHead = head;
	ListNode* prev = NULL;
	int c = k;
	int i = 0;
	while(curr && c--)
		curr = curr->next;
	if(curr == NULL && c != 0) return gHead;
	while(i<k){
		ListNode* temp = head->next;
		head->next = prev;
		prev = head;
		head = temp;
		i++;
	}
	gHead->next = reverseLinkedListKGroup(head,k);
	return prev;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
	
	return 0;
}