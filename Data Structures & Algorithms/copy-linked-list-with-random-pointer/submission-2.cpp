/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        unordered_map<Node*, Node*> myMap;

        myMap.emplace(nullptr, nullptr);

        Node* newHead = new Node(head->val);
        myMap.emplace(head, newHead);

        Node* oldNode = head->next;
        Node* newNode = newHead;

        while (oldNode != nullptr)
        {
            newNode->next = new Node(oldNode->val);
            newNode = newNode->next;

            myMap.emplace(oldNode, newNode);
            oldNode = oldNode->next;
        }

        oldNode = head;
        newNode = newHead;
        while (oldNode != nullptr)
        {
            newNode->random = myMap[oldNode->random];
            newNode = newNode->next;
            oldNode = oldNode->next;
        }

        return newHead;
    }
};