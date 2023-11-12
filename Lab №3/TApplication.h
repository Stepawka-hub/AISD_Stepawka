#pragma once
#include "BinaryTree.h"

class TApplication {
private:
	BinaryTree<int> MyTree;
	int Menu(int);
	int BinaryMenu();
	int AVLMenu();

public:
	TApplication();
	int Executor();
	~TApplication();
};
