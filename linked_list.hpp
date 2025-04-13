#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

class Node {
public:
    int key;
    double value;
    Node* next;

    Node();
    Node(int key, double value);
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    ~LinkedList();

    Node* get_head();
    void push_front(int key, double value);
    void push_back(int key, double value);
    void insert(int key, double value, int index);
    double search(int key);
    Node* at(int index);
    int size();
    bool remove(int index);
    bool remove_key(int key);
    bool remove_value(double value);
    void print();
    void selection_sort();
    void bubble_sort();
};

#endif