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
    ListNode* reverseList(ListNode *&head)
{
    ListNode* prev = NULL;
    ListNode* cur = head;

    while(cur != NULL)
    {
        ListNode* temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }

    return prev;
}
};