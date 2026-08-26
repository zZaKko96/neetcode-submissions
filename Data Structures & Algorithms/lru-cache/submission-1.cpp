class LRUCache {
private:
    struct Node
    {
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr) {};
    };
    int size, capacity;
    Node* start;
    Node* end;
    unordered_map<int, Node*> table;
public:
    LRUCache(int capacity) : size(0), capacity(capacity), start(new Node(0,0)), end(start) {
    }

    int get(int key) {
        if (table.contains(key))
        {
            Node* node = table[key];

            if (node != end)
            {
                node->prev->next = node->next;
                node->next->prev = node->prev;

                end->next = node;

                node->prev = end;
                node->next = nullptr;

                end = node;
            }

            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (table.contains(key))
        {
            Node* node = table[key];
            node->value = value;

            if (end != node)
            {
                node->prev->next = node->next;
                node->next->prev = node->prev;

                end->next = node;

                node->prev = end;
                node->next = nullptr;

                end = node;
            }

            return;
        }

        end->next = new Node(key, value);
        end->next->prev = end;
        end = end->next;

        size++;
        if (size > capacity)
        {
            Node* node = start->next;
            start->next = node->next;
            node->next->prev = start;
            table.erase(node->key);
            delete node;
            size--;
        }

        table[key] = end;
    }
};