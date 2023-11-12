#pragma once

template <typename T>
class Node { //  ласс узла
public:
    T data;
    Node<T>* left, *right; // ”казатели на дочерние элементы
    Node(T value);
};

template <typename T>
class BinaryTree {
private:
    Node<T>* root;

public:
    BinaryTree();
    void BypassInDepth(Node<T>);
};

template <typename T>
Node<T>::Node(T value) {
    data = value;
    left = nullptr;
    right = nullptr;
}

template <typename T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
}

template <typename T>
void BinaryTree<T>::BypassInDepth(Node<T> TNode) {
    if (TNode == nullptr)
        return;

    //visit(tnode)
    bypassindepth(TNode.left);
    std::cout << TNode.data;
    bypassindepth(TNode.right);
}

