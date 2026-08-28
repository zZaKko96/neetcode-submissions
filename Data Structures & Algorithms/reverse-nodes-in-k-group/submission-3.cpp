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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k == 1) {
            return head;
        }

        int count = 0;
        ListNode* curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }

        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        curr = head;

        while (count >= k) {
            for (int i = 1; i < k; ++i) {
                ListNode* next = curr->next;
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
            }
            prev = curr;
            curr = curr->next;
            count -= k;
        }

        return dummy.next;
    }
};