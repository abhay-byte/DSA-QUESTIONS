#include <iostream>
#include <cmath>

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

void insertAtHead(ListNode *&head, int value)
{
    ListNode *n = new ListNode(value);
    n->next = head; // Point the new node to the current head
    head = n;       // Update the head to the new node
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head)
{
	ListNode* slow = head;
	ListNode* fast = head;

	while (fast != NULL and fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			// you've found a cycle
			return true;
		}
	}

	// no cycle found
	return false;

}
};