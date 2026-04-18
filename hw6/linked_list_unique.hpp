#pragma once
#include <iostream>
#include <memory>

class LinkedList {
private:
    struct Node {
        int value;
        std::unique_ptr<Node> next;
        Node(int value) : value(value), next(nullptr) {}
    };

    std::unique_ptr<Node> head_;
    Node* tail_;

public:
    LinkedList() : head_(nullptr), tail_(nullptr) {}
    ~LinkedList() = default;

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void push_back(int value) {

        if(head_ == nullptr){
            head_ = std::make_unique<Node>(value);
            tail_ = head_.get();
        }
        else{
            tail_->next = std::make_unique<Node>(value);
            tail_ = tail_->next.get();

        }

    }

    void print(std::ostream& os) const {
        Node* curr = head_.get();
        while (curr){
            os << curr->value;
            if(curr->next) os << " --> ";
            curr = curr->next.get();
        }

    }
};
