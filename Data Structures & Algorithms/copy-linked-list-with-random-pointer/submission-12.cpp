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

        Node* nodeToGo = head;
        Node* newNode;
        while (nodeToGo)
        {
            newNode = new Node(nodeToGo->val);
            newNode->next = nodeToGo->next;
            nodeToGo->next = newNode;
            nodeToGo = newNode->next;
        }

        nodeToGo = head;
        while (nodeToGo)
        {
            if (nodeToGo->random)
                nodeToGo->next->random = nodeToGo->random->next;
            nodeToGo = nodeToGo->next->next;
        }

        Node dummy(0);
        nodeToGo = head;
        newNode = &dummy;
        while (nodeToGo)
        {
            newNode->next = nodeToGo->next;
            nodeToGo->next = nodeToGo->next->next;
            newNode = newNode->next;
            nodeToGo = nodeToGo->next;
        }

        return dummy.next;
    }
};
