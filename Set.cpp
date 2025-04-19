//
//  newSet.cpp
//  homework_one
//
//  Created by Ellie Townsend on 4/12/25.
//

#include "Set.h"
#include <cstdlib>

Set::Set(){
    head = nullptr; // Creates a ptr called head, this is just saying "hey, lets start a list, but it does not point to anything valid because the user has not inserted anything into their list
}

Set::Set(const Set &set){
    //what if we gave it an empty set, a set with one element, a set with 0 elements
    Node *myPtr = head;
    Node *last = nullptr;
    
    for(Node *ptr = set.head; ptr != nullptr; ptr = ptr->next){
        Node *newNode = new Node(ptr->value);
        if(head == nullptr){
            head = newNode;
        }
        else{
            last->next = newNode;
            newNode->prev = last;
        }
        last = newNode;
    }
}

Set& Set::operator=(const Set &other){
    //Are they the same list?
    if(this == &other){
        return *this;
    }
    //
    Node *toDelete = head;
    while(toDelete != nullptr){
        Node* next = toDelete->next;
        delete toDelete;
        toDelete = next;
    }
    head = nullptr;
    
    Node *last = nullptr;
    for(Node *ptr = other.head; ptr != nullptr; ptr = ptr->next){
        //Create a new node
        Node *newNode = new Node(ptr->value);
        //need to check if its the head
        if(head == nullptr){
            head = newNode;
        }
        else{
            last->next = newNode;
            newNode->prev = last;
        }
        last = newNode;
    }
    return *this;
}

Set::~Set(){
    Node* toDelete = head;
    while (toDelete != nullptr) {
        Node* next = toDelete->next;
        delete toDelete;
        toDelete = next;
    }
}
    
bool Set::empty() const{
    return head == nullptr;
}

int Set::size() const{
    int count = 0;
    for(Node *size = head; size != nullptr; size = size->next){
        count += 1;
    }
    return count;
}

bool Set::insert(const ItemType& value){
    //declare a pointer outside the for loop, that will get us access to the last element in the list
    if(head == nullptr){
        //Do not have to check if the value is already in the list because if head == nullptr that means are list is empty
        head = new Node(value);
        return true;
    }
    
    Node *last = head;
    while(last != nullptr){
        if(last->value == value){
                //found a duplicate and our set class does not allow for duplicates
            return false;
        }
        if(last->next == nullptr){
            Node *newNode = new Node(value);
            last->next = newNode;
            newNode->prev = last;
            return true;
            }
        last = last->next;
        }
    return false;
}



bool Set::erase(const ItemType& value){
    //Check to see if we have an empty list:
    if(head == nullptr){
        return false;
    }
    //Look for that value
    Node *ptr = head;
    while(ptr != nullptr){
        if(ptr->value == value){
            if(ptr->next == nullptr){
                //If we only had one item in the list:
                if(ptr->prev == nullptr){
                    delete head;
                    head = nullptr;
                    return true;
                }
                    // We have reached the last node in the linked list:
                    ptr->prev->next = nullptr;
                    delete ptr;
                    return true;
                }
            else{
                // if we have to delete the head:
                if(ptr->prev == nullptr){
                    head = ptr->next;
                    ptr->next->prev = nullptr;
                    delete ptr;
                    return true;
                }
                else{
                    //regular case (middle of the list)
                    ptr->prev->next = ptr->next;
                    ptr->next->prev = ptr->prev;
                    delete ptr;
                    return true;
                }
            }
            }
            ptr = ptr->next;
        }
    //Cound not find the value we were suppose to erase
    return false;
}

bool Set::contains(const ItemType& value) const{
    Node *valueFinder = head;
    for(valueFinder; valueFinder != nullptr; valueFinder= valueFinder->next){
        if(valueFinder->value == value){
            return true;
        }
    }
    return false;
}


bool Set::get(int i, ItemType& value)const{
  //I need to create a copy of the linked list, one i can rearrange
    if(head != nullptr){
        int size = 0;
        Node *ogList = head;
        Node *newHead = nullptr;
        Node *lastlyInserted = nullptr;
        for(ogList; ogList != nullptr; ogList = ogList->next){
            //I want to create a new node
            Node *newNode = new Node(ogList->value);
            if(newHead == nullptr){
                newHead = newNode;
            }
            else{
                lastlyInserted->next = newNode;
                newNode->prev = lastlyInserted;
            }
            lastlyInserted = newNode;
            size += 1;
        }
        //Great! our copy has been created, now we can rearrange the nodes
        if(size == 1 && i == 0){
            value = head->value;
            return true;
        }
        else if(i < 0 || i >= size){
            //The user gave us a value that is greater than the list
            return false;
        }
        else{
        //The list is greater than one, we have to rearrange based on size
            for(int j = 0; j < size; j++){
                Node *ptr = newHead;
                while(ptr->next != nullptr){
                    if(ptr->value > ptr->next->value){
                        ItemType temp = ptr->value;
                        ptr->value = ptr->next->value;
                        ptr->next->value = temp;
                    }
                    ptr = ptr->next;
                }
            }
        }
        //Great! we have an assorted list note we can look for the element
        Node *findI = newHead;
        for(int e = 0; e < i; e++){
            findI = findI->next;
        }
        value = findI->value;
        delete newHead;
        return true;
    }
    return false;
}


void Set::swap(Set& other){
    Node *temp = head;
    head = other.head;
    other.head = temp;
}

