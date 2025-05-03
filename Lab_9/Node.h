#pragma once
#include <iostream>
#include <memory>
#include <string>

struct Node {
    std::string name;
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> weak_next;

    Node(std::string name) : name{name} {}
    ~Node() { std::cout << "Node [" << name << "] destructor\n"; }
};
