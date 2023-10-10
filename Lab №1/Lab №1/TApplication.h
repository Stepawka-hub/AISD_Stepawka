#pragma once
#include "linked_list.h"
#include "stack.h"
#include "dynamic_array.h"

class TApplication {
private:
	int keychange;
	LinkedList List;
	Stack Stack;
	DynamicArray Array;

	int MainMenu();
	int LinkedListMenu();
	int StackMenu();
	int DynamicArrayMenu();

public:
	TApplication();
	int Executor();
	~TApplication();
};
