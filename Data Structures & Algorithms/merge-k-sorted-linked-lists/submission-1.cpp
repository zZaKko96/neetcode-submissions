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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* newNode = &dummy;

        auto cmp = [](const ListNode* a, const ListNode* b) {
            return a->val > b->val;
            };

        priority_queue < ListNode*, vector<ListNode*>, decltype(cmp) > MyQueue;

        for (ListNode* it : lists)
            if(it)
                MyQueue.push(it);

        while (!MyQueue.empty())
        {
            newNode->next = MyQueue.top();
            MyQueue.pop();
            newNode = newNode->next;
            if (newNode->next)
                MyQueue.push(newNode->next);
        }

        return dummy.next;
    }
};
