#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        if (head == NULL) return NULL;

        ListNode* cur = head;
        while (cur != NULL && cur->next != NULL) {
            if (cur->next->val == val) {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};
