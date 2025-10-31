#ifndef CIRCULARTEMPLATEDLIST_LINKEDLIST_H
#define CIRCULARTEMPLATEDLIST_LINKEDLIST_H
#include "Media.h"
#include <iostream>

// Created template with struct Node with it along updating build in data!
template <typename T> struct Node {
    // Data is now hard-coded to the BASE CLASS pointer: Media*
    T data;
    Node<T>* next;

    // Constructor initializes data and pointer
    Node(T media) : data(media), next(nullptr) {}
};


// === 5. Hard-coded LinkedList Class (Singly, Non-Circular) ===
// This list is only capable of managing Media* objects (Song*, Podcast*, etc.) and is forward-only.
//
// Created template with class LinkedList with it along updating build in data!
template <typename T> class LinkedList {
private:
    Node<T>* head; // Header
    Node<T>* tail; // Tail
    Node<T>* current; // Current
public:
    // Constructor: Initializes an empty list
    LinkedList() : head(nullptr) {}

    // Destructor: Cleans up all nodes and the Media objects they point to.
    ~LinkedList() {

        // Checking to see if head is not a nullptr otherwise result in error message. (Option for destructor...)
        if (head != nullptr)
        {
            Node<T>* curr = head;
            Node<T>* next_node = nullptr;
            // Traverse the list until the end (nullptr) is reached
            do
            {
                next_node = curr->next;
                delete curr->data; // Delete the Media object stored in the node's data pointer (polymorphic deletion)
                delete curr; // Delete the node itself
                curr = next_node;
            } while (curr != head);
            std::cout << "\n[Playlist cleanup complete. All memory deallocated.]" << std::endl;
        }
        else {
            std::cout << "\n[There was no memory to be cleared due to a null pointer.]" << std::endl;
            return;
        }
    }

    // Insertion: Adds a new Media pointer to the end of the list.
    void insert(T newMedia) {
        Node<T>* newNode = new Node<T>(newMedia); // Create newNode

        if (head != nullptr)
        {
            // Case: Traverse to the end and link the new node.
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
        else {
            // Case: List is empty. New node becomes the head.
            head = newNode;
            tail = newNode;
            current = head;
            newNode->next = head;
        }
    }

    // Traversal: Displays all media items in the list.
    void displayList() const {

        // Checking to see if head is not a nullptr otherwise result in error message.
        if (head != nullptr)
        {
            // Console header display
            std::cout << "\n--- Current Playlist ---" << std::endl;


            Node<T>* curr = head; // current head
            unsigned int index = 0; // made unsigned for positive numbers (In case negative numbers...)

            do {
                index++; // increment +1
                std::cout << index << ". " << curr->data->toString() << std::endl; // console current
                curr = curr->next; // get next
            } while (curr != head);

            // Console bottom display
            std::cout << "------------------------" << std::endl;
        }
        else {
            std::cout << "\n[Playlist is empty.]" << std::endl;
            return;
        }
    }

    // Simple play method for demonstration (students will expand this later)
    void playCurrent() const {

        // Checking to see if head is not a nullptr otherwise result in error message.
        if (current != nullptr)
        {
            current->data->play();
        }
        else {
            std::cout << "[Playlist is empty. Nothing to play.]" << std::endl;
        }
    }

    void playNext()
    {
        // Checking to see if head is not a nullptr otherwise result in error message.
        if (current != nullptr)
        {
            current = current->next;
            current->data->play();
        }
        else {
            std::cout << "[Playlist is empty. Nothing to play.]" << std::endl;
            return;
        }
    }

};

#endif //CIRCULARTEMPLATEDLIST_LINKEDLIST_H