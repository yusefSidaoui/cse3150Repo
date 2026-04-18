#pragma once
#include <iostream>

class LinkedList {
private:
    struct Node{
        int value;
        Node* next;

        Node(int value) : value(value), next(nullptr) {}
    };

    Node* head_;
    Node* tail_;

public:
    LinkedList() : head_(nullptr), tail_(nullptr) {}
    ~LinkedList(){
        while(head_ != nullptr){
            Node* old = head_;
            head_ = head_->next;
            delete old;
            old = nullptr;
        }

    }


    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void push_back(int value) {
        Node* newNode = new Node(value);

        if(!head_){
            head_ = newNode;
            tail_ = newNode;
        }
        else{
            tail_->next = newNode;
            tail_ = newNode;
        }
    }
    void print(std::ostream& os) const {
        Node* curr = head_;
        while(curr){
            os << curr->value;
            if (curr->next) os << " --> ";
            curr = curr->next;
        }
    }



};
