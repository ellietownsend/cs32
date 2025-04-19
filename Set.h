//
//  newSet.hpp
//  homework_one
//
//  Created by Ellie Townsend on 4/12/25.
//

#ifndef Set_h
#define Set_h

#include <iostream>
using namespace std;

typedef string ItemType;

class Set
{
  public:
    Set();         // Create an empty set (i.e., one whose size() is 0).
    // So what should set do for a linked list, well it should create a pointer called head. But because no values will be passed through we can consider that no node was created. So this would be an empty list
    
    //SIZE will no longer be nescessary because there is n
    //Set(int size); DELETE WHEN WE KNOW FOR SURE, ASK IN SECTION
    
    //Because we are dynamically allocating items, we need a copy constructor, destrcutor, and assignment operator
    Set(const Set &set);
    //When a brand new Set is created as a copy of an existing Set, enough new nodes must be allocated to hold a duplicate of the original list.
    
    
    //When an existing Set (the left-hand side) is assigned the value of another Set (the right-hand side), the result must be that the left-hand side object is a duplicate of the right-hand side object, with no memory leak of list nodes (i.e. no list node from the old value of the left-hand side should be still allocated yet inaccessible).
    Set& operator=(const Set &other);
    
    bool empty() const;  // Return true if the set is empty, otherwise false.

    int size() const;    // Return the number of items in the set.

    bool insert(const ItemType& value);
      // Insert value into the set if it is not already present.  Return
      // true if the value actually is inserted.  Leave the set unchanged
      // and return false if value was not inserted (perhaps because it
      // was already in the set or because the set has a fixed capacity and
      // is full).

    bool erase(const ItemType& value);
      // Remove the value from the set if present.  Return true if the
      // value was removed;  otherwise, leave the set unchanged and
      // return false.
     
    bool contains(const ItemType& value) const;
      // Return true if the value is in the set, otherwise false.
     
    bool get(int i, ItemType& value)const;
      // If 0 <= i < size(), copy into value the item in the set that is
      // strictly greater than exactly i items in the set and return true.
      // Otherwise, leave value unchanged and return false.

    void swap(Set& other);
      // Exchange the contents of this set with the other one.
    
    ~Set();
    //When a Set is destroyed, the nodes in the linked list must be deallocated.
    //ALL NODES ARE dynamically stored in memory, so we have to use a ptr to delete them?

private:
    class Node{
    public:
        Node(const ItemType& val, Node *previous = nullptr, Node *nextPtr = nullptr):
        value(val), next(nextPtr), prev(previous){}
        ItemType value;
        Node *next;
        Node *prev; // We can declare a pointer of type node but not a node itself
        //If we are creating a set, that we want to insert nodes in we will want a head to point to the first node
    };
    Node *head;
    
    //Node class:
    //This is a doubly linked list, so it will need a node that has a field to both the front and back
};


#endif
