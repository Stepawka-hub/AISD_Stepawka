#pragma once

class LinkedList {
private:
	Node * begin, * end;

public:
	LinkedList();
	int add_top(double data);
	int add_end(double data);
	~LinkedList();
};

class Node {
private:
	double data;
public:
	Node* prev, * next;
	Node(double data);
};