#include "LinkedList.h"
#include <iostream>

using namespace std;

void LinkedList::SERVER_buildCircularLinkedList() {
    vector<string> names = { "zero", "one", "two", "three", "four", "five" };
    shared_ptr<Node> node = make_shared<Node>(names[0]);
    root = node;
    for (int i = 1; i < names.size(); ++i) {
        node->next = make_shared<Node>(names[i]);
        node = node->next;
    }
    node->next = root;
    node = root;
    do {
        node->weak_next = node->next;
        node = node->next;
    } while (node != root);
}

void LinkedList::SERVER_printLinkedList() {
    cout << "Server (shared_ptr):\n";
    auto node = root;
    if (!node) return;
    do {
        cout << "[" << node->name << "] : use_count: " << node.use_count()
             << " address: " << node.get();
        if (node->next)
            cout << " next (from shared_ptr): " << node->next.get() << endl;
        else
            cout << " next: nullptr\n";
        node = node->next;
    } while (node != root);
}

void LinkedList::CLIENT_printLinkedList() {
    cout << "Client (weak_ptr):\n";
    auto node = root;
    if (!node) return;
    shared_ptr<Node> start = node;
    do {
        cout << "[" << node->name << "] : use_count: " << node.use_count()
             << " address: " << node.get();
        auto next = node->weak_next.lock();
        if (next)
            cout << " next (from weak_ptr): " << next.get() << endl;
        else {
            cout << " next: nullptr (shared_ptr not available)\n";
            break;
        }
        node = next;
    } while (node != start);
}

void LinkedList::SERVER_deleteCircularLinkedList() {
    cout << "Server is deleting the shared_ptrs (step 4)\n";
    root = nullptr;
}
