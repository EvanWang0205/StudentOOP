#include <iostream>
#include "llist.h"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
    os << nd->data << endl;
    return os;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
    /* 1. allocate node */
    Node* new_node = new Node(d);
    
    Node *last = head; /* used in step 3*/
    
    /* 2. If the Linked List is empty,
     then make the new node as head */
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    
    /* 3. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
    
    /* 4. Change the next of last node */
    last->next = new_node;
    return;
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* curr) {
    if (curr == NULL)
        return;
    
    if (curr->next == NULL)
        os << curr->data << endl;
    
    print_list(os, curr->next);    //CHECK!!
    
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
    /* 1. check if head is nullptr*/
    if (head == NULL)
        Node* new_node = new Node(d);
    /* 2. if head is not null*/
    else {
        /* create new node, new node next is orginal head*/
        Node* new_node = new Node(d, head);
        /* re-assign head to new node*/
        head = new_node;
    }
}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
    if(!head)
        return nullptr;
    else if(!head -> next)
        return head;
    else
        return last(head -> next);
}


bool del_head(Node*& head){
    if(!head)
        return false;
    else{
        Node* temp = head;
        head = head -> next;
        delete temp;
        return true;
    }
}


bool del_tail(Node*& curr){
    if(!curr)
        return false;
    else{
        if (curr -> next == nullptr){
            delete curr;
            curr = nullptr;
            return true;
        }
        else{
            return del_tail(curr -> next);
        }
    }
}


Node* duplicate(Node* head) {
    Node* curr = head;
    
    /* if list is empty*/
    if (curr == NULL)
        return curr;
    
    /* copy head */
    Node* copy = new Node(curr->data, curr->next);
    Node* const new_head = copy;
    
    /* copy the rest of the list */
    curr = curr->next;
    while (curr != NULL) {
        copy = copy->next;
        copy = new Node(curr->data, curr->next);
        curr = curr->next;
    }
    
    return new_head;
}

Node* join(Node*& list1, Node* list2) {
    Node* last_list1 = last(list1);
    last_list1->next = list2;
}

Node* reverse(Node* curr, Node* new_next){
    if(!curr)
        return new_next;
    else{
        return reverse(curr -> next, new Node(curr -> data, new_next));
    }
}

