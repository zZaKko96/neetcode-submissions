class LRUCache {
private:
    struct Node {
        int key;
        int value;
        int prev;
        int next;
    };

    int cap;
    int head;
    int tail;
    int freeHead;
    vector<Node> nodes;
    unordered_map<int, int> table;

    void removeNode(int idx) {
        nodes[nodes[idx].prev].next = nodes[idx].next;
        nodes[nodes[idx].next].prev = nodes[idx].prev;
    }

    void addToTail(int idx) {
        int realTailPrev = nodes[tail].prev;
        nodes[idx].prev = realTailPrev;
        nodes[idx].next = tail;
        nodes[realTailPrev].next = idx;
        nodes[tail].prev = idx;
    }

    void moveToTail(int idx) {
        removeNode(idx);
        addToTail(idx);
    }

public:
    LRUCache(int capacity) : cap(capacity) {
        table.reserve(capacity);
        nodes.resize(capacity + 2); 

        head = 0;
        tail = 1;
        nodes[head].next = tail;
        nodes[tail].prev = head;

        for (int i = 2; i < capacity + 2; ++i) {
            nodes[i].next = (i + 1 < capacity + 2) ? (i + 1) : -1;
        }
        freeHead = 2;
    }

    int get(int key) {
        auto it = table.find(key);
        if (it == table.end()) {
            return -1;
        }
        int idx = it->second;
        moveToTail(idx);
        return nodes[idx].value;
    }

    void put(int key, int value) {
        auto it = table.find(key);
        if (it != table.end()) {
            int idx = it->second;
            nodes[idx].value = value;
            moveToTail(idx);
            return;
        }

        int idx;
        if (freeHead != -1) {
            idx = freeHead;
            freeHead = nodes[freeHead].next;
        }
        else {
            idx = nodes[head].next;
            removeNode(idx);
            table.erase(nodes[idx].key);
        }

        nodes[idx].key = key;
        nodes[idx].value = value;
        addToTail(idx);
        table[key] = idx;
    }
};