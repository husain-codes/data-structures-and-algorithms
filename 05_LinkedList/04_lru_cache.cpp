#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

/**
 * Implementation of LRU (Least Recently Used) Cache.
 *
 * Time Complexity:
 *  - get(key) : O(1)
 *  - put(key, value) : O(1)
 *
 * Space Complexity:
 *  - O(capacity) for storing keys in hash map and list.
 *
 * Approach:
 *  - We maintain:
 *      1. A doubly linked list (`list<int> lru_key`) to track usage order 
 *         (most recently used at front, least recently used at back).
 *      2. An unordered_map (`umap`) to store key → {value, iterator in list}.
 *
 *  - On `get(key)`:
 *      • If found, move the key to the front (MRU position).
 *      • Else, return -1.
 *
 *  - On `put(key, value)`:
 *      • If key exists, update value and move to front.
 *      • If key does not exist:
 *          - If capacity full, remove the LRU key (from back of list and map).
 *          - Insert new key at front of list and update map.
 */

class LRUCache {
    int cap;
    unordered_map<int, pair<int, list<int>::iterator>> umap; // key → {value, iterator}
    list<int> lru_key; // tracks usage order (front = most recent, back = least recent)

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    // Retrieve value for given key
    int get(int key) {
        auto it = umap.find(key);
        if (it != umap.end()) {
            // Move key to front (most recent)
            lru_key.erase(it->second.second);
            lru_key.push_front(key);
            it->second.second = lru_key.begin();
            return it->second.first;
        }
        return -1; // not found
    }

    // Insert or update key-value pair
    void put(int key, int value) {
        auto it = umap.find(key);
        if (it != umap.end()) {
            // Key already exists → update value and move to front
            lru_key.erase(it->second.second);
            lru_key.push_front(key);
            it->second = {value, lru_key.begin()};
        } else {
            // Key does not exist
            if (umap.size() >= cap) {
                // Evict least recently used key
                int oldkey = lru_key.back();
                lru_key.pop_back();
                umap.erase(oldkey);
            }
            // Insert new key at front
            lru_key.push_front(key);
            umap[key] = {value, lru_key.begin()};
        }
    }

    // Debug function: Print current cache state
    void printCache() {
        cout << "Cache state (MRU → LRU): ";
        for (int key : lru_key) cout << key << " ";
        cout << endl;
    }
};

// ---------------------- TEST CASES ----------------------
int main() {
    cout << "Creating LRUCache with capacity = 2\n";
    LRUCache lRUCache(2);

    cout << "\nPut(1, 1)";
    lRUCache.put(1, 1);
    lRUCache.printCache(); // {1}

    cout << "\nPut(2, 2)";
    lRUCache.put(2, 2);
    lRUCache.printCache(); // {2,1}

    cout << "\nGet(1) → " << lRUCache.get(1) << endl; // returns 1
    lRUCache.printCache(); // {1,2}

    cout << "\nPut(3, 3)  (evicts key 2)";
    lRUCache.put(3, 3);
    lRUCache.printCache(); // {3,1}

    cout << "\nGet(2) → " << lRUCache.get(2) << endl; // returns -1

    cout << "\nPut(4, 4)  (evicts key 1)";
    lRUCache.put(4, 4);
    lRUCache.printCache(); // {4,3}

    cout << "\nGet(1) → " << lRUCache.get(1) << endl; // returns -1
    cout << "Get(3) → " << lRUCache.get(3) << endl; // returns 3
    cout << "Get(4) → " << lRUCache.get(4) << endl; // returns 4
    lRUCache.printCache(); // {4,3}

    return 0;
}
