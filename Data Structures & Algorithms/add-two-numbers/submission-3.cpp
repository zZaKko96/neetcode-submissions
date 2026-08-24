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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);

        ListNode* node1 = l1, * node2 = l2, * node3 = &dummy;

        int additionalAdd = 0;
        while (node1 && node2)
        {
            int sum = node1->val + node2->val + additionalAdd;
            node3->next = new ListNode(sum % 10);
            additionalAdd = sum / 10;
            node1 = node1->next;
            node2 = node2->next;
            node3 = node3->next;
        }

        while (node1)
        {
            int sum = node1->val + additionalAdd;
            node3->next = new ListNode(sum % 10);
            additionalAdd = sum / 10;
            node1 = node1->next;
            node3 = node3->next;
        }

        while (node2)
        {
            int sum = node2->val + additionalAdd;
            node3->next = new ListNode(sum % 10);
            additionalAdd = sum / 10;
            node2 = node2->next;
            node3 = node3->next;
        }

        if (additionalAdd) node3->next = new ListNode(additionalAdd);

        return dummy.next;
    }
};