#include <stack>
#include <queue>
#include <sstream>

#pragma once

template <typename T>
class AVLNode { // ����� ����
public:
    T data;
    int height;
    AVLNode<T>* left, * right; // ��������� �� �������� ��������
    AVLNode(T);
};

template <typename T>
class AVLTree {
private:
    AVLNode<T>* root;
    void create(Node<T>*); // �������� ��� ������ �� ������ ���������
    int height(AVLNode<T>*); // ������� ������ ���-������
    int diffheight(AVLNode<T>*); // ������� � ������� ����� ������������
    AVLNode<T>* balance(AVLNode<T>*); // ������������ ��� ������
    AVLNode<T>* insert(AVLNode<T>*, T); // ������� ��������
    AVLNode<T>* search(AVLNode<T>*, T); // ����� ���� �� �����
    AVLNode<T>* remove(AVLNode<T>*, T); // �������� ���� �� �����
    AVLNode<T>* get_minkey(AVLNode<T>*); // ����� ���� � ���. ������ ������������ ��������
    AVLNode<T>* remove_minkey(AVLNode<T>*); // �������� ���� �� ������ � ���. ������ ������������ ��������

    // ��������
    AVLNode<T>* rr_rotation(AVLNode<T>*);
    AVLNode<T>* ll_rotation(AVLNode<T>*);
    AVLNode<T>* lr_rotation(AVLNode<T>*);
    AVLNode<T>* rl_rotation(AVLNode<T>*);

    // ����������� ������
    void orderCLR(AVLNode<T>*); // ������ �������
    void orderLCR(AVLNode<T>*); // �������������� �������
    void orderLRC(AVLNode<T>*); // �������� �������
    void traversalIter(AVLNode<T>*); // ����� � ������� (����������� �������)
    void widthTraversal(AVLNode<T>*); // ����� � ������

public:
    AVLTree();
    void create(BinaryTree<T>);
    T insert(T);
    AVLNode<T>* search(T);
    void remove(T);
    void orderCLR();
    void orderLCR();
    void orderLRC();
    void traversalIter();
    void widthTraversal();
};

template <typename T>
AVLNode<T>::AVLNode(T value) {
    data = value;
    height = 0;
    left = nullptr;
    right = nullptr;
}

template <typename T>
AVLTree<T>::AVLTree() {
    root = nullptr;
}

// �������� ��� ������ �� ������ ���������
template <typename T>
void AVLTree<T>::create(Node<T>* TNode) {
    if (TNode == nullptr)
        return;
    this->root = insert(this->root, TNode->data);
    create(TNode->left);
    create(TNode->right);
}

// �������� ��� ������ �� ������ ���������
template <typename T>
void AVLTree<T>::create(BinaryTree<T> BTree) {
    create(BTree.GetRoot());
}

// ������ ���-������
template <typename T>
int AVLTree<T>::height(AVLNode<T>* TNode) {
    int AVLheight = 0;

    if (TNode != nullptr) { // ���� ����
        int hleft = height(TNode->left); // ������ ������ ���������
        int hright = height(TNode->right); // ������ ������� ���������
        int max_height = std::max(hleft, hright);
        AVLheight = max_height + 1; // ������ ��� ������ - ������������ �� ����� (+1)
    }

    return AVLheight;
}

// ������� � ������
template <typename T>
int AVLTree<T>::diffheight(AVLNode<T>* TNode) {
    int hleft = height(TNode->left);
    int hright = height(TNode->right);
    int bfactor = hleft - hright;
    return bfactor;
}

// Right - Right Rotation
template <typename T>
AVLNode<T>* AVLTree<T>::rr_rotation(AVLNode<T>* parent) {
    AVLNode<T>* temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

// Left - Left Rotation
template <typename T>
AVLNode<T>* AVLTree<T>::ll_rotation(AVLNode<T>* parent) {
    AVLNode<T>* temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

// Left - Right Rotation
template <typename T>
AVLNode<T>* AVLTree<T>::lr_rotation(AVLNode<T>* parent) {
    AVLNode<T>* temp;
    temp = parent->left;
    parent->left = rr_rotation(temp);
    return ll_rotation(parent);
}

// Right - Left Rotation
template <typename T>
AVLNode<T>* AVLTree<T>::rl_rotation(AVLNode<T>* parent) {
    AVLNode<T>* temp;
    temp = parent->right;
    parent->right = ll_rotation(temp);
    return rr_rotation(parent);
}

// ������������ ��� ������
template <typename T>
AVLNode<T>* AVLTree<T>::balance(AVLNode<T>* TNode) {
    int bfactor = diffheight(TNode);

    // ���� ������ ������ ��������� ������ ������ ������� �����, ��� �� 1
    if (bfactor > 1) {
        if (diffheight(TNode->left) > 0)
            TNode = ll_rotation(TNode);
        else
            TNode = lr_rotation(TNode);
    }

    // ���� ������ ������� ��������� ������ ������ ������ �����, ��� �� 1
    else if (bfactor < -1) { // ����
        if (diffheight(TNode->right) > 0)
            TNode = rl_rotation(TNode);
        else
            TNode = rr_rotation(TNode);
    }

    return TNode;
}

// ������� ��������
template <typename T>
AVLNode<T>* AVLTree<T>::insert(AVLNode<T>* root, T data) {
    if (root == nullptr)
        return new AVLNode<T>(data);

    else if (data < root->data) {
        root->left = insert(root->left, data);
        root = balance(root);
    }

    else if (data >= root->data) {
        root->right = insert(root->right, data);
        root = balance(root);
    }

    return root;
}

template <typename T>
T AVLTree<T>::insert(T data) {
    root = insert(root, data);
    return data;
}

// ����� ���� �� �����
template <typename T>
AVLNode<T>* AVLTree<T>::search(AVLNode<T>* TNode, T key) {
    if (TNode == nullptr || TNode->data == key)
        return TNode;

    if (key < TNode->data)
        return search(TNode->left, key);
    else
        return search(TNode->right, key);
}

template <typename T>
AVLNode<T>* AVLTree<T>::search(T key) {
    AVLNode<T>* TNode = search(root, key);

    if (TNode == nullptr)
        std::cout << "\n\x1B[93m���� � ��������� ������\x1B[91m �� ��� ������!\n";
    else if (TNode->data == key)
        std::cout << "\n\x1B[93m���� � ��������� ������\x1B[96m ��� ������!\n";

    return TNode;
}

// �������� ���� �� �����
template <typename T>
AVLNode<T>* AVLTree<T>::remove(AVLNode<T>* TNode, T key) {
    if (TNode == nullptr)
        return 0;

    if (key < TNode->data) // ���� ���� � ��������� ������
        TNode->left = remove(TNode->left, key);

    else if (key > TNode->data) // ���� ���� � ��������� ������
        TNode->right = remove(TNode->right, key);

    else { // ���� ������
        AVLNode<T>* l_root = TNode->left;
        AVLNode<T>* r_root = TNode->right;
        delete TNode;

        if (r_root == nullptr) // ���� ������ ��������� �� ������, �� ������� ��� ���� � ���. ������
            return l_root;

        AVLNode<T>* min = get_minkey(r_root);
        min->right = remove_minkey(r_root);
        min->left = l_root;

        return balance(min);
    }

    return balance(TNode);
}

template <typename T>
void AVLTree<T>::remove(T key) {
    if (remove(root, key) == nullptr)
        std::cout << "\n\x1B[93m���� � ��������� ������\x1B[91m �� ��� ������!\n";
    else
        std::cout << "\n\x1B[93m���� � ��������� ������\x1B[96m ��� �����!\n";
}

template <typename T>
AVLNode<T>* AVLTree<T>::get_minkey(AVLNode<T>* TNode) {
    if (TNode->left != nullptr)
        return get_minkey(TNode->left);
    else
        return TNode;
}

template <typename T>
AVLNode<T>* AVLTree<T>::remove_minkey(AVLNode<T>* TNode) {
    if (TNode->left == 0)
        return TNode->right;
    TNode->left = remove_minkey(TNode->left);

    return balance(TNode);
}

// ����� - ������ �������
template <typename T>
void AVLTree<T>::orderCLR(AVLNode<T>* tree) {
    if (tree == nullptr)
        return;
    std::cout << tree->data << "  ";
    orderCLR(tree->left);
    orderCLR(tree->right);
}

template <typename T>
void AVLTree<T>::orderCLR() {
    orderCLR(this->root);
}

// ����� - �������������� �������
template <typename T>
void AVLTree<T>::orderLCR(AVLNode<T>* tree) {
    if (tree == nullptr)
        return;
    orderLCR(tree->left);
    std::cout << tree->data << "  ";
    orderLCR(tree->right);
}

template <typename T>
void AVLTree<T>::orderLCR() {
    orderLCR(this->root);
}

// ����� - �������� �������
template <typename T>
void AVLTree<T>::orderLRC(AVLNode<T>* tree) {
    if (tree == nullptr)
        return;
    orderLRC(tree->left);
    orderLRC(tree->right);
    std::cout << tree->data << "  ";
}

template <typename T>
void AVLTree<T>::orderLRC() {
    orderLRC(this->root);
}

// ����� � ������� (����������� �������)
template <typename T>
void AVLTree<T>::traversalIter(AVLNode<T>* root) {
    if (root == NULL)
        return;

    std::stack<AVLNode<T>*> IterStack;
    IterStack.push(root);

    while (!IterStack.empty()) {
        AVLNode<T>* TNode = IterStack.top();
        IterStack.pop();
        std::cout << TNode->data << " ";

        if (TNode->right)
            IterStack.push(TNode->right);

        if (TNode->left)
            IterStack.push(TNode->left);
    }
}

template <typename T>
void AVLTree<T>::traversalIter() {
    traversalIter(this->root);
}

// ����� � ������
template <typename T>
void AVLTree<T>::widthTraversal(AVLNode<T>* tree) {
    if (tree == nullptr)
        return;

    std::queue<AVLNode<T>*> Queue;
    Queue.push(tree);

    while (!Queue.empty()) {
        AVLNode<T>* TNode = Queue.front(); // ������ ������� �������
        Queue.pop(); // �������� �������� �� ������ �������
        std::cout << TNode->data << " ";

        if (TNode->left != nullptr)
            Queue.push(TNode->left);

        if (TNode->right != nullptr)
            Queue.push(TNode->right);
    }
}

template <typename T>
void AVLTree<T>::widthTraversal() {
    widthTraversal(this->root);
}

