#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
private:
    // Helper function to add a node right after head
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
    // Helper function to remove a node from the linked list
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    // Helper function to move a node to front (most recently used)
    void moveToFront(Node* node) {
        removeNode(node);
        addNode(node);
    }

public:
    LRUCache(int capacity) {
        cp = capacity;
        head = new Node(0, 0); // Dummy head
        tail = new Node(0, 0); // Dummy tail
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) override {
        auto it = mp.find(key);
        if (it == mp.end()) {
            return -1; // Key not found
        }
        // Move to front (most recently used)
        Node* node = it->second;
        moveToFront(node);
        return node->value;
    }
    
    void set(int key, int value) override {
        auto it = mp.find(key);
        if (it != mp.end()) {
            // Key exists, update value and move to front
            Node* node = it->second;
            node->value = value;
            moveToFront(node);
        } else {
            // Create new node
            Node* newNode = new Node(key, value);
            mp[key] = newNode;
            addNode(newNode);
            
            // Check if cache exceeds capacity
            if (mp.size() > cp) {
                // Remove least recently used item (node before tail)
                Node* lru = tail->prev;
                removeNode(lru);
                mp.erase(lru->key);
                delete lru;
            }
        }
    }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
