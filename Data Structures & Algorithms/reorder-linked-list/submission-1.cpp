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
    void reorderList(ListNode* head) {
        ListNode* slow = head, * fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = slow->next;
        slow->next = nullptr;

        slow = nullptr;
        while (fast != nullptr)
        {
            ListNode* nextNode = fast->next;
            fast->next = slow;
            slow = fast;
            fast = nextNode;
        }

        fast = head->next;

        ListNode* current = head;
        
        while (fast != nullptr && slow != nullptr)
        {
            current->next = slow;
            current = slow;
            slow = slow->next;

            current->next = fast;
            current = fast;
            fast = fast->next;
        }
    }
};
