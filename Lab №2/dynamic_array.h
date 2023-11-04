#pragma once
#include "Sorting.h"

template<typename T>
class DynamicArray {
private:
	T* data;
	int size;
	int capacity;
public:
	DynamicArray();
	DynamicArray(const DynamicArray<T>& copy); // ����������� �����������
	int add(int index, T data);
	int set(int index, T data);
	int remove(int index);
	int getsize();
	void resize(int size);
	int sort();
	T& operator[] (int i);
	~DynamicArray();
};

template<typename T>
DynamicArray<T>::DynamicArray() {
	size = 0;
	capacity = 0;
	data = NULL;
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& copy) { // ����������� �����������
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
int DynamicArray<T>::add(int index, T value) {
	resize(this->size + 1);

	for (int i = this->size - 1; i > index; --i)
		data[i] = data[i - 1];

	data[index] = value;

	return 0;
}

template<typename T>
int DynamicArray<T>::set(int index, T value) {
	data[index] = value;

	return 0;
}

template<typename T>
int DynamicArray<T>::remove(int index) {
	for (int i = index; i < this->size - 1; ++i)
		data[i] = data[i + 1];

	resize(this->size - 1);

	return 0;
}

template<typename T>
int DynamicArray<T>::getsize() {
	return this->size;
}

template<typename T>
void DynamicArray<T>::resize(int size) {
	if (size > this->capacity) {
		int capacity = std::max<int>(size, this->size * 2);
		T* data = new T [capacity];

		for (int i = 0; i < this->size; ++i)
			data[i] = this->data[i];

		delete[] this->data;
		this->data = data;
		this->capacity = capacity;
	}

	this->size = size;
}

template<typename T>
int DynamicArray<T>::sort() {
	int minrun = GetMinrun(size);
	int index = 0;

	SortingInserts(data, 0, size - 1);

	//for (int i = 0; i < size; i += minrun)
	//	SortingInserts(data, i, std::min(i, size - 1)); // ��������� ������� �� ���������� ����������� minrun, ����� ������ �� ��� ��������� ���������

	return 1;
}

template<typename T>
T& DynamicArray<T>::operator[] (int index) {
	return this->data[index];
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
	if (data)
		delete[] data;
}