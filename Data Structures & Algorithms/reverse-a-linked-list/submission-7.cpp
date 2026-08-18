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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        // Обробка по 2 вузли за ітерацію
        while (curr != nullptr && curr->next != nullptr) {
            ListNode* next1 = curr->next;
            ListNode* next2 = next1->next;

            curr->next = prev;
            next1->next = curr;

            prev = next1;
            curr = next2;
        }

        if (curr != nullptr) {
            curr->next = prev;
            prev = curr;
        }

        return prev;
    }
};
