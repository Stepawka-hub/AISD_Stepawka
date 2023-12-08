#pragma once
#include "BinaryTree.h"
#include "AVLTree.h"

class TApplication {
private:
	BinaryTree<int> BTree;
	AVLTree<int> AVLTree;
	int Menu(int);
	int BinaryMenu();
	int AVLMenu();

public:
	TApplication();
	int Executor();
	~TApplication();
};
