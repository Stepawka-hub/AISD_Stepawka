#include <stack>
#include <sstream>

#pragma once

template <typename T>
class AVLNode { // Класс узла
public:
    T data;
    int height;
    AVLNode<T>* left, * right; // Указатели на дочерние элементы
    AVLNode(T);
};


template <typename T>
class AVLTree {
private:
    AVLNode<T>* root;
    void create(Node<T>*); // Создание АВЛ дерева на основе бинарного
    int height(AVLNode<T>*); // Подсчёт высоты АВЛ-дерева
    int diffheight(AVLNode<T>*); // Разница в высотах между поддеревьями
    AVLNode<T>* balance(AVLNode<T>*); // Балансировка АВЛ дерева
    AVLNode<T>* insert(AVLNode<T>*, T); // Вставка элемента

    // Повороты
    AVLNode<T>* rr_rotation(AVLNode<T>*);
    AVLNode<T>* ll_rotation(AVLNode<T>*);
    AVLNode<T>* lr_rotation(AVLNode<T>*);
    AVLNode<T>* rl_rotation(AVLNode<T>*);

    // Рекурсивные обходы
    void orderCLR(AVLNode<T>*); // Прямой порядок
    void orderLCR(AVLNode<T>*); // Центрированный порядок
    void orderLRC(AVLNode<T>*); // Обратный порядок

public:
    AVLTree();
    void create(BinaryTree<T>);
    T insert(T);
    void orderCLR(); // Прямой порядок (Вызов из интерфейса)
    void orderLCR(); // Центрированный порядок (Вызов из интерфейса)
    void orderLRC(); // Обратный порядок (Вызов из интерфейса)
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

// Создание АВЛ дерева на основе бинарного
template <typename T>
void AVLTree<T>::create(Node<T>* TNode) {
    if (TNode == nullptr)
        return;
    this->root = insert(this->root, TNode->data);
    create(TNode->left);
    create(TNode->right);
}

// Создание АВЛ дерева на основе бинарного
template <typename T>
void AVLTree<T>::create(BinaryTree<T> BTree) {
    create(BTree.GetRoot());
}

// Высота АВЛ-дерева
template <typename T>
int AVLTree<T>::height(AVLNode<T>* TNode) {
    int AVLheight = 0;

    if (TNode != NULL) { // Узел не пуст
        int hleft = height(TNode->left); // Высота левого поддерева
        int hright = height(TNode->right); // Высота правого поддерева
        int max_height = std::max(hleft, hright);
        AVLheight = max_height + 1; // Высота АВЛ дерева - максимальная из высот (+1)
    }

    return AVLheight;
}

// Разница в высоте
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

// Балансировка АВЛ дерева
template <typename T>
AVLNode<T>* AVLTree<T>::balance(AVLNode<T>* TNode) {
    int bfactor = diffheight(TNode);

    // Если высота левого поддерева больше высоты правого более, чем на 1
    if (bfactor > 1) {
        if (diffheight(TNode->left) > 0)
            TNode = ll_rotation(TNode);
        else
            TNode = lr_rotation(TNode);
    }

    // Если высота правого поддерева больше высоты левого более, чем на 1
    else if (bfactor < -1) { // Если
        if (diffheight(TNode->right) > 0)
            TNode = rl_rotation(TNode);
        else
            TNode = rr_rotation(TNode);
    }

    return TNode;
}

// Вставка элемента
template <typename T>
AVLNode<T>* AVLTree<T>::insert(AVLNode<T>* root, T data) {
    if (root == NULL)
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

// Обход - Прямой порядок
template <typename T>
void AVLTree<T>::orderCLR(AVLNode<T>* tree) {
    if (tree == NULL)
        return;
    std::cout << tree->data << "  ";
    orderCLR(tree->left);
    orderCLR(tree->right);
}

template <typename T>
void AVLTree<T>::orderCLR() {
    orderCLR(this->root);
}

// Обход - Центрированный порядок
template <typename T>
void AVLTree<T>::orderLCR(AVLNode<T>* tree) {
    if (tree == NULL)
        return;
    orderLCR(tree->left);
    std::cout << tree->data << "  ";
    orderLCR(tree->right);
}

template <typename T>
void AVLTree<T>::orderLCR() {
    orderLCR(this->root);
}

// Обход - Обратный порядок
template <typename T>
void AVLTree<T>::orderLRC(AVLNode<T>* tree) {
    if (tree == NULL)
        return;
    orderLRC(tree->left);
    orderLRC(tree->right);
    std::cout << tree->data << "  ";
}

template <typename T>
void AVLTree<T>::orderLRC() {
    orderLRC(this->root);
}


