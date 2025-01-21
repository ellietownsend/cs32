//
//  linkedList.cpp
//  VoiceMail
//
//  Created by Ellie Townsend on 1/20/25.
//

#include <stdio.h>
#include <string>
using namespace std;
/*Linked List*/

// What leads us to using a linked list:
//        - Arrays are great, but there only good in certain cases, like when we know how many items we need. But what if we dont know, then were just reserving a bunch of extra space, when we dont really know if we need it, example: int array[10000];
// Even with dynamic allocation (new/delete), we have to supply if with a number at SOME time example: cin >> numItems;
// What if we needed to insert a new item in the middle of the array? Now were moving a bunch of items over, just to keep the items in order!


// Typically we use dynamic allocation for a linked list:
// Creating pointers:           Chest *head, *second, *third;
//                              head = new Chest;  "Hey can you allocate 20 bytes for me?" OS: "Sure i've reserved some memoty for you at location 5000"
// Creating our second node:    second = new Chest;
//                              head->treasure = "toast";
// Use an arrow when there is a pointer on the left. Above, head is a pointer, so we have to access member variables from head using a pointer. It does not matter what is on the left.
//                              head->next_chest = second;

struct Node{
    string value;
    Node *next;
};

// Allocating new nodes:                     Node *p = new Node;
//                                           Node *q = new Node;
// To change of access a node p's value =    p->value = "blah";
// Read the value:                           cout << p-> value;
// Linking nodes:                            p->next = q;
// Getting the address of the node after p:  Node *r = p->next;
// Terminal node:                            q->next = nullptr;
// The delete command:                       delete p;
//                                           delete q;

// We have to create a dedicated class to hold our linked list:
class LinkedList{
private:
    struct Node{ // this is called a "nested" struct
        string value;
        Node *next;
    };
public:
    Node* head_; // a member variable to hold our head pointer

    LinkedList(){
        head_ = nullptr; // Why does a nullptr go here? This indicates it is an empty list.
    }
    // The following will work even when we have no items in our list:
    void add_front(string V){
        Node *nn; // creating a pointer to the new node we are adding
        nn = new Node; // dynamically adding a node, which also means it will not discard once this function is done running
        nn->value = V; // store the value of the node
        nn->next = head_; // Addiing it to the front of the list
        head_ = nn; // not a pointer to nn because the head is not a pointer, the head is a node
    }
    bool is_last_node(Node *n){
        if(n->next == nullptr){
            return true;
        }
        else{
            return false;
        }
    }
    void insert_after(Node *p, string v){
        Node *nn = new Node;
        nn->value = v;
        nn->next = p->next; // Were saying "Set our new nodes "next" value to the value that came after the node we got in the constructor
        p->next= nn; // setting our previous pointer to the new node
    }
    void add_rear(string v){
        if( head_ == nullptr){
            add_front(v);
            return;
        }
        Node *p = head_;
        while (is_last_node(p) == false){
            p = p->next;
        }
        p->next = insert_after(p, v)
    }
    void print_items(){
        Node *p;
        p = head_;
        while (p!= nullptr){
            cout << p->value; // have to use an arrow because on the left there is a p
            p = p->next; // moving our pointer along
        }
    }
};
// Anytime we iterate through the nodes of a list we are "traversing". In the while loop, we traversed a linked list when we printed each item. But we traverse for lots of reasons such as to add a node, or delete a node.
// Fucntion to insert a node:
//


// Note: Nullptr means invalid pointer


//Creating a treasure hunt as an example of a linked list:
struct Chest{
    string treasuer; // a string to represent the treasure within a chest
    // a pointer that depicts the location of the next chest:
    Chest *next_chest; // Self-refrential data structure: This defines "next_chest" as a pointer to another chest! This means we are capable of pointing to another object of the samy type.
};
