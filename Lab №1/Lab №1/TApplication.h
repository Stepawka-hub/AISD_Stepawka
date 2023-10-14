#pragma once
#include "linked_list.h"
#include "dynamic_array.h"
#include "stack.h"

class TApplication {
private:
	LinkedList<int> List;
	DynamicArray<int> Array;
	Stack Stack;
	int Menu(int status);
	int LinkedListMenu();
	int StackMenu();
	int DynamicArrayMenu();

public:

	TApplication();
	int Executor();
	~TApplication();
};
