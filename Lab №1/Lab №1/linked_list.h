#pragma once

template<typename T>
class Node {
public:

	Node<T> * prev, * next;
    T data;
	Node(T data);
};

template<typename T>
class LinkedList {
private:
    int size;
	Node<T> * begin, * end;
    Node<T>* getnode(int index);
    T getdata(int index);
public:
	LinkedList();
	T operator[] (int index);
    int getsize();
	int add_top(T data);
	int add_end(T data);
	int delete_top();
	int delete_end();
    int insert(int index, T data);
    int erase(int index);
	~LinkedList();
};

template<typename T>
LinkedList<T>::LinkedList() {
    begin = NULL;
    end = NULL;
    size = 0;
}

template<typename T>
Node<T>* LinkedList<T>::getnode(int index) {
    Node<T>* ptr = begin;
    for (int i = 0; i < index; ++i) {
        if (ptr == NULL)
            return ptr;
        ptr = ptr->next;
    }

    return ptr;
}

template<typename T>
T LinkedList<T>::getdata(int index) {
    Node<T>* ptr = begin;
    for (int i = 0; i < index; ++i) {
        ptr = ptr->next;
    }

    return ptr->data;
}

template<typename T>
T LinkedList<T>::operator[] (int index) {
    if (index < 0 || index >= size)
        return 0;
    return getdata(index);
}

template<typename T>
int LinkedList<T>::getsize() {
    return this->size;
}

template<typename T>
int LinkedList<T>::add_top(T data) {
    Node<T>* ptr = new Node<T>(data);
    ptr->next = begin;

    if (begin != NULL) // Если список не пустой
        begin->prev = ptr;

    if (end == NULL)
        end = ptr;

    begin = ptr;
    ++size;

    return 1;
}

template<typename T>
int LinkedList<T>::add_end(T data) {
    Node<T>* ptr = new Node<T>(data);
    ptr->next = NULL;

    if (begin == NULL) {
        ptr->prev = NULL;
        begin = ptr;
    }

    else {
        ptr->prev = end;
        end->next = ptr;
    }

    end = ptr;
    ++size;

    return 1;
}

template<typename T>
int LinkedList<T>::delete_top() {
    if (begin == NULL)
        return 0;

    Node<T>* ptr = begin->next;
    if (ptr != NULL)
        ptr->prev = NULL;
    else
        end = NULL;

    delete begin;
    begin = ptr;
    --size;

    return 1;
}

template<typename T>
int LinkedList<T>::delete_end() {
    if (end == NULL)
        return 0;

    Node<T>* ptr = end->prev;
    if (ptr != NULL)
        ptr->next = NULL;
    else
        begin = NULL;

    delete end;
    end = ptr;
    --size;

    return 1;
}

template<typename T>
int LinkedList<T>::insert(int index, T data) {
    Node<T>* right = getnode(index);

    if (right == NULL)
        return add_end(data);

    Node<T>* left = right->prev;
    if (left == NULL)
        return add_top(data);

    Node<T>* ptr = new Node<T>(data);

    ptr->prev = left;
    ptr->next = right;
    left->next = ptr;
    right->prev = ptr;
    ++size;

    return 1;
}

template<typename T>
int LinkedList<T>::erase(int index) {
    if (index < 0 || index >= size)
        return 0;

    Node<T>* ptr = getnode(index);

    if (ptr->prev == NULL) {
        return delete_top();
    }

    if (ptr->next == NULL)
        return delete_end();

    Node<T>* left = ptr->prev; Node<T> *right = ptr->next;
    left->next = right;
    right->prev = left;

    delete ptr;
    --size;

    return 1;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    while (begin != NULL) // Вызовом деструктора очищаем память
        delete_end();
}

template<typename T>
Node<T>::Node(T data) {
    this->data = data;
    prev = NULL;
    next = NULL;
}