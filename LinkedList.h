//
// Created by Christopher Vaughn on 10/24/25.
//

#ifndef CIRCULARTEMPLATEDLIST_LINKEDLIST_H
#define CIRCULARTEMPLATEDLIST_LINKEDLIST_H
#include "Media.h"
#include <iostream>

template <typename T> struct Node {
    // Data is now hard-coded to the BASE CLASS pointer: Media*
    T data;
    Node<T>* next;

    // Constructor initializes data and pointer
    Node(T media) : data(media), next(nullptr) {}
};


// === 5. Hard-coded LinkedList Class (Singly, Non-Circular) ===
// This list is only capable of managing Media* objects (Song*, Podcast*, etc.) and is forward-only.
template <typename T> class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* current;
public:
    // Constructor: Initializes an empty list
    LinkedList() : head(nullptr) {}

    // Destructor: Cleans up all nodes and the Media objects they point to.
    ~LinkedList() {
        if (head != nullptr)
        {
            Node<T>* curr = head;
            Node<T>* next_node = nullptr;

            do
            {
                next_node = curr->next;
                delete curr->data;
                delete curr;
                curr = next_node;
            } while (curr != head);

        }
        else {
            std::cout << "\n[Playlist cleanup complete. All memory deallocated.]" << std::endl;
            return;
        }
    }

    // Insertion: Adds a new Media pointer to the end of the list.
    void insert(T newMedia) {
        Node<T>* newNode = new Node<T>(newMedia);
        if (head != nullptr)
        {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
        else {
            head = newNode;
            tail = newNode;
            current = head;
            newNode->next = head;
        }
    }

    // Traversal: Displays all media items in the list.
    void displayList() const {

        if (head != nullptr)
        {
            std::cout << "\n--- Current Playlist ---" << std::endl;

            Node<T>* curr = head;
            unsigned int index = 0;

            do {
                index++;
                std::cout << index << ". " << curr->data->toString() << std::endl;
                curr = curr->next;
            } while (curr != head);


            std::cout << "------------------------" << std::endl;
        }
        else {
            std::cout << "\n[Playlist is empty.]" << std::endl;
            return;
        }
    }

    // Simple play method for demonstration (students will expand this later)
    void playCurrent() const {
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