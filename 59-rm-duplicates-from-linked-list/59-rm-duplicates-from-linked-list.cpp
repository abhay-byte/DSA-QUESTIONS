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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode *head) {
        if (!head || !head->next) // empty or single-node list
            return head;

        ListNode* prev = head;
        ListNode* cur = head->next;

        while (cur != nullptr) {
            if (cur->val != prev->val) {
                prev->next = cur;
                prev = cur;
            }
            cur = cur->next;
        }

        prev->next = nullptr;
        return head;
    }
};
