#pragma once
#include "linked_list.h"
#include "stack.h"
#include "dynamic_array.h"

class TApplication {
private:
	LinkedList<int> List;
	Stack Stack;
	DynamicArray Array;
	int Menu(int status);
	int LinkedListMenu();
	int StackMenu();
	int DynamicArrayMenu();

public:

	TApplication();
	int Executor();
	~TApplication();
};
