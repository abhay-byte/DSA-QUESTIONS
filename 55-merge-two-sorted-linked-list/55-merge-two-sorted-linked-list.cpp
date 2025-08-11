#include <iostream>
#include <cmath>

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
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *head1, ListNode *head2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy;

        while (head1 != NULL && head2 != NULL)
        {
            if (head1->val < head2->val)
            {
                temp->next = head1;
                temp = temp->next;
                head1 = head1->next;
            }
            else
            {
                temp->next = head2;
                temp = temp->next;
                head2 = head2->next;
            }
        }

        if (head1 != NULL)
        {
            temp->next = head1;
        }

        if (head2 != NULL)
        {
            temp->next = head2;
        }

        return dummy->next;
    }
};