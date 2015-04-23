#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
	//Set a node pointer as a probe n posistions ahead
	ListNode *probe = head;
	for(int i=0; i<n; ++i){
		//if(probe == NULL) break; //Use this line if verification is needed
		probe = probe->next;
	}

	//Use the probe to move pointer to the right position
	ListNode *current = head;
	ListNode *previous = NULL;
	while(probe != NULL){
		previous = current;
		current = current->next;
		probe = probe->next;
	}
	//Delete target node
	if(previous != NULL){
		previous->next = current->next;
	}
	else //If the head node was deleted
		head = current->next;
	delete current;

	return head;
}
