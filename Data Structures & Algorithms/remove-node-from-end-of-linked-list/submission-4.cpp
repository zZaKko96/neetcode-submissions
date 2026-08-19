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
        if (head->next == nullptr) return nullptr;
        size_t countSlow = 0, count = 0;
        ListNode* slow = head, * fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            countSlow++;

            fast = fast->next->next;
            count += 2;
        }
        if (fast != nullptr) count++;

        size_t newCount = count - n - 1;

        if (newCount == -1)
        {
            fast = head;
            head = fast->next;
            delete fast;
            return head;
        }
        else if (newCount > countSlow)
            for (; countSlow < newCount; countSlow++, slow = slow->next);
        else
            for (slow = head, countSlow = 0; countSlow < newCount;
                countSlow++, slow = slow->next);

        fast = slow->next;
        slow->next = fast->next;
        delete fast;

        return head;
    }
};