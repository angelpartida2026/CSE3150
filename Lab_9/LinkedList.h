#pragma once
#include "Node.h"
#include <vector>
#include <memory>
#include <string>

class LinkedList {
private:
    std::shared_ptr<Node> root;

public:
    void SERVER_buildCircularLinkedList();
    void SERVER_deleteCircularLinkedList();
    void SERVER_printLinkedList();
    void CLIENT_printLinkedList();
};
