#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "linked_list.h"

LinkedList::LinkedList() {
	begin = NULL;
	end = NULL;
}

int LinkedList::add_top(double data) {
    Node * ptr = new Node(data);
    ptr->next = begin;

    if (begin != NULL)
        begin->prev = ptr;

    if (end == NULL)
        end = ptr;

    begin = ptr;

    return 1;
}

int LinkedList::add_end(double data) {
    Node* ptr = new Node(data);
    ptr->prev = end;

    if (end != NULL)
        begin->next = ptr;

    if (begin == NULL)
        begin = ptr;

    end = ptr;

    return 1;
}

int LinkedList::delete_top() {
    if (begin == NULL)
        return 0;

    Node* ptr = begin->next;

    begin->next = begin;

    return 1;
}

int LinkedList::delete_end() {
    
    return 1;
}

LinkedList::~LinkedList() {

}

Node::Node(double data) {
	this->data = data;
	prev = NULL;
	next = NULL;
}