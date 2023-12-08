#include <stack>
#include <queue>
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
    AVLNode<T>* search(AVLNode<T>*, T); // Поиск узла по ключу
    AVLNode<T>* remove(AVLNode<T>*, T); // Удаление узла по ключу
    AVLNode<T>* get_minkey(AVLNode<T>*); // Поиск узла с мин. ключом относительно искомого
    AVLNode<T>* remove_minkey(AVLNode<T>*); // Удаление узла из дерева с мин. ключом относительно искомого

    // Повороты
    AVLNode<T>* rr_rotation(AVLNode<T>*);
    AVLNode<T>* ll_rotation(AVLNode<T>*);
    AVLNode<T>* lr_rotation(AVLNode<T>*);
    AVLNode<T>* rl_rotation(AVLNode<T>*);

    // Рекурсивные обходы
    void orderCLR(AVLNode<T>*); // Прямой порядок
    void orderLCR(AVLNode<T>*); // Центрированный порядок
    void orderLRC(AVLNode<T>*); // Обратный порядок
    void traversalIter(AVLNode<T>*); // Обход в глубину (итеративный вариант)
    void widthTraversal(AVLNode<T>*); // Обход в ширину

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

    if (TNode != nullptr) { // Узел есть
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

// Поиск узла по ключу
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
        std::cout << "\n\x1B[93mУзел с указанным ключом\x1B[91m не был найден!\n";
    else if (TNode->data == key)
        std::cout << "\n\x1B[93mУзел с указанным ключом\x1B[96m был найден!\n";

    return TNode;
}

// Удаление узла по ключу
template <typename T>
AVLNode<T>* AVLTree<T>::remove(AVLNode<T>* TNode, T key) {
    if (TNode == nullptr)
        return 0;

    if (key < TNode->data) // Ищем узел с указанным ключом
        TNode->left = remove(TNode->left, key);

    else if (key > TNode->data) // Ищем узел с указанным ключом
        TNode->right = remove(TNode->right, key);

    else { // Узел найден
        AVLNode<T>* l_root = TNode->left;
        AVLNode<T>* r_root = TNode->right;
        delete TNode;

        if (r_root == nullptr) // Если правое поддерево не пустое, то находим там узел с мин. ключом
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
        std::cout << "\n\x1B[93mУзел с указанным ключом\x1B[91m не был найден!\n";
    else
        std::cout << "\n\x1B[93mУзел с указанным ключом\x1B[96m был удалён!\n";
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

// Обход - Прямой порядок
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

// Обход - Центрированный порядок
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

// Обход - Обратный порядок
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

// Обход в глубину (Итеративный вариант)
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

// Обход в ширину
template <typename T>
void AVLTree<T>::widthTraversal(AVLNode<T>* tree) {
    if (tree == nullptr)
        return;

    std::queue<AVLNode<T>*> Queue;
    Queue.push(tree);

    while (!Queue.empty()) {
        AVLNode<T>* TNode = Queue.front(); // Первый элемент очереди
        Queue.pop(); // Удаление элемента из начала очереди
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

