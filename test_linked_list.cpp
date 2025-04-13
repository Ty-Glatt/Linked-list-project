#include "linked_list.hpp"
#include <iostream>

bool test_push_front();
bool test_push_back();
bool test_insert();
bool test_search();
bool test_size();
bool test_remove();
bool test_remove_key();
bool test_remove_value();
bool test_print();
bool test_selection_sort();
bool test_bubble_sort();


// Main for printing the results of the tests
int main() {
	std::cout << "Test Push Front: " << (test_push_front() ? "Passed" : "Failed") << std::endl;
	std::cout << "Test Push Back: " << (test_push_back() ? "Passed" : "Failed") << std::endl;	
	std::cout << "Test Insert: " << (test_insert() ? "Passed" : "Failed") << std::endl;	
	std::cout << "Test Search: " << (test_search() ? "Passed" : "Failed") << std::endl;	
	std::cout << "Test Size: " << (test_size() ? "Passed" : "Failed") << std::endl; 
	std::cout << "Test Remove: " << (test_remove() ? "Passed" : "Failed") << std::endl; 
	std::cout << "Test Remove Key: " << (test_remove_key() ? "Passed" : "Failed") << std::endl; 
	std::cout << "Test Remove Value: " << (test_remove_value() ? "Passed" : "Failed") << std::endl; 
	std::cout << "Test Print: " << (test_print() ? "Passed" : "Failed") << std::endl; 
	std::cout << "Test Selection Sort: " << (test_selection_sort() ? "Passed" : "Failed") << std::endl; 
	std::cout << "Test Bubble Sort: " << (test_bubble_sort() ? "Passed" : "Failed") << std::endl; 
}


bool test_push_front(){
    LinkedList l;
    
    // Uses push_front to add values to the front of the list while also adding keys to each node.
    l.push_front(3, 3);
    l.push_front(2, 2);
    l.push_front(1, 1);
    
    Node* l_head = l.get_head();

    // Deterimines if the values stored in the nodes are equal to what they should be.
    bool av1 = l_head->value == 1;
    bool av2 =  l_head->next->value == 2;
    bool av3 = l_head->next->next->value == 3 && l_head->next->next->next == nullptr;

    return av1 && av2 && av3;
}

bool test_push_back(){
    LinkedList l;

    // Uses push_back to add values to the back of the list while adding keys to each node.
    l.push_back(1, 1);
    l.push_back(2, 2);
    l.push_back(3, 3);


    Node* l_head = l.get_head();

    // Deterimines if the values stored in the nodes are equal to what they should be.
    bool av1 = l_head->value == 1;
    bool av2 = l_head->next->value == 2;
    bool av3 = l_head->next->next->value == 3 && l_head->next->next->next == nullptr;

    return av1 && av2 && av3;
}

bool test_insert(){
    LinkedList l;
    // Inserts a value at the front of the list(Like A push_front call)
    l.insert(1, 1, 0);
    // Inserts values at the back of the list(Like A push_back call)
    l.insert(2, 2, 1);
    l.insert(3, 3, 2);

    Node* l_head = l.get_head();

    // Deterimines if the values stored in the nodes are equal to what they should be.
    bool av1 = l_head->value == 1;
    bool av2 = l_head->next->value == 2;
    bool av3 = l_head->next->next->value == 3 && l_head->next->next->next == nullptr;
    return av1 && av2 && av3;
}

bool test_search(){
    LinkedList l;
    
    // Fills the list with values.
    l.push_front(1,1);
    l.push_front(2,2);
    l.push_front(3,3);

    // Determines if the values stored in the nodes are equal to what they should be.
    bool av1 = l.search(1) == 1;
    bool av2 = l.search(2) == 2;
    bool av3 = l.search(3) == 3;

    // Determines if the function returns -1 when the key is not found.
    bool av4 = l.search(4) == -1;
    return av1 && av2 && av3 && av4;
}

bool test_size(){
    LinkedList l1,l2,l3;

    // Fills list 1 and 3 while leaving list 2 empty.
    l1.push_front(1,1);
    l3.push_front(1,2);
    l3.push_front(2,3);

    // Determines if the size of each list is equal to what it should be.
    bool av1 = l1.size() == 1;
    bool av2 = l2.size() == 0;
    bool av3 = l3.size() == 2;

    return av1 && av2 && av3;
}

bool test_remove(){
    LinkedList l;

    // Puts values in the list using insert.
    l.insert(1, 1, 0);
    l.insert(2, 2, 1);
    l.insert(3, 3, 2);

    // Removes the nodes by index.
    bool rv1 = l.remove(0);
    bool rv2 = l.remove(0);
    bool rv3 = l.remove(0);

    // Tries to remove a node that doesn't exist.
    bool rv4 = l.remove(1);

    Node* l_head = l.get_head();


    bool av1 = rv1 == true;
    bool av2 = rv2 == true;
    bool av3 = rv3 == true && l_head == nullptr;
    bool av4 = rv4 == false;
    return av1 && av2 && av3 && av4;
}

bool test_remove_key(){
    LinkedList l;

    // Puts values in the list using insert.
    l.insert(1, 1, 0);
    l.insert(2, 2, 1);
    l.insert(3, 3, 2);
    
    // Removes the nodes by the key.
    bool rv1 = l.remove_key(1);
    bool rv2 = l.remove_key(2);
    bool rv3 = l.remove_key(3);

    // Tries to remove a node that doesn't exist.
    bool rv4 = l.remove_key(5);

    Node* l_head = l.get_head();

    // Determines if the removal was successful by seeing if the list is empty, and if the rv1 returned true(true = successful removal).
    bool av1 = rv1 == true;
    bool av2 = rv2 == true;
    bool av3 = rv3 == true && l_head == nullptr;
    bool av4 = rv4 == false;
    return av1 && av2 && av3 && av4;
}

bool test_remove_value(){
    LinkedList l;

    // Puts values in the list using insert.
    l.insert(1, 1, 0);
    l.insert(2, 2, 1);
    l.insert(3, 3, 2);

    // Removes the nodes by the value.
    bool rv1 = l.remove_value(1);
    bool rv2 = l.remove_value(2);
    bool rv3 = l.remove_value(3);

    // Tries to remove a node that doesn't exist.
    bool rv4 = l.remove_value(5);

    Node* l_head = l.get_head();

    // Determines if the removal was successful by seeing if the list is empty, and if the rv1 returned true(true = successful removal).
    bool av1 = rv1 == true;
    bool av2 = rv2 == true;
    bool av3 = rv3 == true && l_head == nullptr;
    bool av4 = rv4 == false;
    return av1 && av2 && av3 && av4;
}

bool test_print(){
    LinkedList l;

    // Puts a value in the list using push_front.
    l.push_front(1, 1);

    // Prints the list.
    l.print();

    // If the function doesn't crash, the test passes.
    return true;
}


bool test_selection_sort(){
    LinkedList l;

    // Puts value with assigned keys in the list using push_front.
    l.push_front(5,5);
    l.push_front(3,3);
    l.push_front(1,1);
    l.push_front(4,4);
    l.push_front(2,2);

    // Sorts the list.
    l.selection_sort();

    Node* l_head = l.get_head();

    // Determines if the list is sorted by seeing if each nodes key is equal to whats expected.
    bool av1 = l_head->key == 1 && l_head->value == 1;
    bool av2 = l_head->next->key == 2 && l_head->next->value == 2;
    bool av3 = l_head->next->next->key == 3 && l_head->next->next->value == 3;
    bool av4 = l_head->next->next->next->key == 4 && l_head->next->next->next->value == 4;
    bool av5 = l_head->next->next->next->next->key == 5 && l_head->next->next->next->next->value == 5;

    return av1 && av2 && av3 && av4 && av5;
}

bool test_bubble_sort(){
    LinkedList l;

    // Puts value with assigned keys in the list using push_front.
    l.push_front(5,5);
    l.push_front(3,3);
    l.push_front(1,1);
    l.push_front(4,4);
    l.push_front(2,2);

    // Sorts the list.
    l.bubble_sort();

    Node* l_head = l.get_head();

    // Determines if the list is sorteed by seeing if each nodes key is equal to whats expected.
    bool av1 = l_head->key == 1 && l_head->value == 1;
    bool av2 = l_head->next->key == 2 && l_head->next->value == 2;
    bool av3 = l_head->next->next->key == 3 && l_head->next->next->value == 3;
    bool av4 = l_head->next->next->next->key == 4 && l_head->next->next->next->value == 4;
    bool av5 = l_head->next->next->next->next->key == 5 && l_head->next->next->next->next->value == 5;

    return av1 && av2 && av3 && av4 && av5;
}

