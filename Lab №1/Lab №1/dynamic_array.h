#pragma once

template<typename T>
class DynamicArray {
private:
	T* data;
	int size;
	int capacity;
public:
	DynamicArray();
	DynamicArray(const DynamicArray<T>& copy); // Конструктор копирования
	int get(int index);
	int add(int index, T data);
	int set(int index, T data);
	int remove(int index);
	int getsize();
	~DynamicArray();
};

template<typename T>
DynamicArray<T>::DynamicArray() {
	size = 0;
	capacity = 0;
	data = NULL;
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& copy) {
	size = copy.size;
	capacity = size;
	data = NULL;
	if (size != 0)
		data = new T[size];
	else
		data = 0;
	for (int i = 0; i < size; ++i)
		data[i] = copy.data[i];
}

template<typename T>
int DynamicArray<T>::get(int index) {
	return 0;
}

template<typename T>
int DynamicArray<T>::add(int index, T data) {
	return 0;
}

template<typename T>
int DynamicArray<T>::set(int index, T data) {
	return 0;
}

template<typename T>
int DynamicArray<T>::remove(int index) {
	return 0;
}

template<typename T>
int DynamicArray<T>::getsize() {
	return this->size;
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
	if (data)
		delete[] data;
}