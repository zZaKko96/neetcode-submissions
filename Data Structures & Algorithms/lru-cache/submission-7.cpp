class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> table;
    Node* head;
    Node* tail;

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToTail(Node* node) {
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }

    void moveToTail(Node* node) {
        removeNode(node);
        addToTail(node);
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    int get(int key) {
        auto it = table.find(key);
        if (it == table.end()) {
            return -1;
        }

        moveToTail(it->second);
        return it->second->value;
    }

    void put(int key, int value) {
        auto it = table.find(key);
        if (it != table.end()) {
            it->second->value = value;
            moveToTail(it->second);
            return;
        }

        if (table.size() >= capacity) {
            Node* lru = head->next;
            removeNode(lru);
            table.erase(lru->key);
            delete lru;
        }

        Node* newNode = new Node(key, value);
        addToTail(newNode);
        table[key] = newNode;
    }
};