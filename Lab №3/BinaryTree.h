#include <stack>
#include <sstream>

#pragma once

template <typename T>
class Node { // Класс узла
public:
    T data;
    Node<T>* left, *right; // Указатели на дочерние элементы
    Node(T value);
};

template <typename T>
class BinaryTree {
private:
    Node<T>* root;

public:
    BinaryTree();
    Node<T>* Parsing(const std::string&);
    void BypassInDepth(Node<T>*);
    Node<T>* GetRoot();
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

template<typename T>
Node<T>* BinaryTree<T>::Parsing(const std::string& str) {
    std::stack <Node<T>*> Stack;
    std::istringstream istr(str);

    char symbol;
    for (int i = 0; i < str.length(); i++) {
        symbol = str[i];
        if (symbol != '(' && symbol != ')' && symbol != ' ' && !(std::isdigit(symbol))) {
            std::cout << "\x1B[93mВ скобочной записи дерева указаны некорректные символы!\n";
            return 0;
        }
    }

    std::stack<char> parenthesis;
    for (int i = 0; i < str.length(); i++) {
        symbol = str[i];
        if (symbol == '(')
            parenthesis.push(symbol);

        else if (symbol == ')') {
            if (parenthesis.empty() || parenthesis.top() != '(') {
                std::cout << "\x1B[93mНекорректная скобочная запись!\n";
                return 0;
            }
            parenthesis.pop();
        }
    }

    if (!(parenthesis.empty())) {
        std::cout << "\x1B[93mНекорректная скобочная запись!\n";
        return 0;
    }

    char token;
    while (istr >> token) {
        if (isdigit(token)) {
            int value;

            istr.unget();
            istr >> value;

            Node<T>* TNode = new Node<T>(value); // Новый узел
            if (!Stack.empty()) { // Стек не пустой
                Node<T>* ParentNode = Stack.top(); // Родительский узел
                if (ParentNode->left == nullptr) // Если нет левого сына [добавляется]
                    ParentNode->left = TNode;

                else if (ParentNode->right == nullptr) // Если левый сын есть, но нет правого [добавляется]
                    ParentNode->right = TNode;

                else {
                    std::cout << "\x1B[93mДерево не является бинарным!\n";
                    return nullptr;
                }
            }

            else { // Стек пуст
                root = TNode;
            }

            Stack.push(TNode);
        }

        else if (token == ')') {
            Stack.pop();
        }
    }

    return root;
}

template <typename T>
void BinaryTree<T>::BypassInDepth(Node<T>* TNode) {
    if (TNode) { // Узел существует
        BypassInDepth(TNode->left);
        std::cout << TNode->data << " ";
        BypassInDepth(TNode->right);
    }
}

template <typename T>
Node<T> * BinaryTree<T>::GetRoot() {
    return this->root;
}

