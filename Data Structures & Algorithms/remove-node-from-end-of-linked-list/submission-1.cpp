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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        size_t count = 0;
        ListNode* node = head;

        for (; node != nullptr; count++, node = node->next);

        size_t newCount = count - n - 1;

        node = head;

        if (newCount == -1)
        {
            head = head->next;
            delete node;
            return head;
        }

        for (size_t i = 0; i < newCount; i++, node = node->next);

        ListNode* temp = node->next;
        node->next = temp->next;
        delete temp;

        return head;
    }
};