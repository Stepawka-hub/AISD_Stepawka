#pragma once

class Node {
private:
	double data;
public:
	Node* prev, * next;
	Node(double data);
};

class LinkedList {
private:
	Node * begin, * end;
public:
	LinkedList();
	int add_top(double data);
	int add_end(double data);
	int delete_top();
	int delete_end();
	~LinkedList();
};