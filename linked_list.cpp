#include "linked_list.hpp"
#include <iostream>

Node::Node() : key(0), value(0.0), next(nullptr) {}

Node::Node(int k, double v) : key(k), value(v), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

Node* LinkedList::get_head() {
    return head;
}

void LinkedList::push_front(int key, double value) {
    Node* new_node = new Node(key, value);
    new_node->next = head;
    head = new_node;
}

void LinkedList::push_back(int key, double value) {
    Node* new_node = new Node(key, value);
    if (!head) { // if list is empty
        head = new_node;
        return;
    }
    Node* current = head;
    while (current->next) { // go to the last node
        current = current->next;
    }
    current->next = new_node;
}

void LinkedList::insert(int key, double value, int index) {
    if (index == 0) {
        push_front(key, value);
        return;
    }
    Node* prev = at(index - 1); // get node before insert point
    if (!prev) return; // index out of bounds
    Node* new_node = new Node(key, value);
    new_node->next = prev->next;
    prev->next = new_node;
}

double LinkedList::search(int key) {
    Node* current = head;
    while (current) {
        if (current->key == key) return current->value;
        current = current->next;
    }
    return -1.0; // key not found
}

Node* LinkedList::at(int index) {
    Node* current = head;
    int i = 0;
    while (current && i < index) {
        current = current->next;
        ++i;
    }
    return current; // nullptr if index out of bounds
}

int LinkedList::size() {
    int count = 0;
    Node* current = head;
    while (current) {
        ++count;
        current = current->next;
    }
    return count;
}

bool LinkedList::remove(int index) {
    if (!head) return false; // list is empty
    if (index == 0) { // remove head
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    Node* prev = at(index - 1);
    if (!prev || !prev->next) return false; // invalid index
    Node* to_delete = prev->next;
    prev->next = to_delete->next;
    delete to_delete;
    return true;
}

bool LinkedList::remove_key(int key) {
    if (!head) return false;
    if (head->key == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    Node* current = head;
    while (current->next && current->next->key != key) {
        current = current->next;
    }
    if (!current->next) return false; // key not found
    Node* to_delete = current->next;
    current->next = to_delete->next;
    delete to_delete;
    return true;
}

bool LinkedList::remove_value(double value) {
    if (!head) return false;
    if (head->value == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    Node* current = head;
    while (current->next && current->next->value != value) {
        current = current->next;
    }
    if (!current->next) return false; // value not found
    Node* to_delete = current->next;
    current->next = to_delete->next;
    delete to_delete;
    return true;
}

void LinkedList::print() {
    Node* current = head;
    while (current) {
        std::cout << "(" << current->key << ", " << current->value << ") -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

void LinkedList::selection_sort() {
    for (Node* i = head; i && i->next; i = i->next) {
        Node* min = i;
        for (Node* j = i->next; j; j = j->next) {
            if (j->key < min->key) min = j;
        }
        std::swap(i->key, min->key);
        std::swap(i->value, min->value);
    }
}

void LinkedList::bubble_sort() {
    if (!head) return;
    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current->next) {
            if (current->key > current->next->key) {
                std::swap(current->key, current->next->key);
                std::swap(current->value, current->next->value);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}
