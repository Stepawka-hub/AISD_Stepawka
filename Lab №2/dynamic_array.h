#pragma once

#define REPEATS 7

template<typename T>
class DynamicArray {
private:
	T* data;
	int size;
	int capacity;
	int GetMinrun(int);
	void SortingInserts(int, int);
	void MergingArrays(int, int, int);
public:
	DynamicArray();
	DynamicArray(const DynamicArray<T>& copy); // Конструктор копирования
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
DynamicArray<T>::DynamicArray(const DynamicArray<T>& copy) { // Конструктор копирования
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
	int Tsize = this->size;
	int minrun = GetMinrun(Tsize);
	int index = 0;
	for (int i = 0; i < Tsize; i += minrun)
		SortingInserts(i, std::min(i + minrun - 1, Tsize - 1));
	for (int size = minrun; size < Tsize; size *= 2) { 
		for (int left = 0; left < Tsize; left += 2 * size) {
			int mid = left + size - 1;
			int right = std::min((left + 2 * size - 1), (Tsize - 1));
			if (mid < right)
				MergingArrays(left, mid, right);
		}
	}
	return 1;
}

template<typename T>
int DynamicArray<T>::GetMinrun(int N) {
	int M = 0;
	while (N >= 64) {
		M |= N & 1;
		N >>= 1;
	}

	return M + N;
}

template<typename T>
void DynamicArray<T>::SortingInserts(int left, int right) {
	for (int i = left + 1; i <= right; ++i) { // Считаем, что первый элемент это уже отсортированная часть массива
		int temp = data[i]; // Элемент, который будет сравниваться с элементами отсортированной части
		int k = i - 1; // Индекс последнего элемента в отсортированной части (является наибольшим в той части)

		while (k >= left && data[k] > temp) { // Пока элемент из не отсортированной части меньше, чем k-ый элемент в отсортированной части (Ищет нужную позицию)
			data[k + 1] = data[k];
			data[k] = temp;
			--k;
		}
	}
}

template<typename T>
void DynamicArray<T>::MergingArrays(int left, int mid, int right) {
	int len1 = mid - left + 1, len2 = right - mid, repeats1 = 0, repeats2 = 0;

	//int* LeftPart = new int[len1];
	DynamicArray<int> LeftPart;
	LeftPart.resize(len1);

	for (int i = 0; i < len1; ++i)
		LeftPart[i] = data[left + i]; // Заполняем левую часть (Левый подмассив)

	int i = 0, j = 0, k = left, rightpos = mid + 1; // Объединяем эти два массива в один путём сравнения
	while (i < len1 && j < len2) { // Пока индексы i и j не дойдут до конца массивов
		if (repeats1 >= REPEATS || repeats2 >= REPEATS) { // Было найдено REPEATS повторений (7)
			int degree = 0;
			if (repeats1 >= REPEATS) { // REPEATS (7) раз произошла ситуация, когда элемент из левой части меньше очередного элемента из правой
				repeats1 = 0;
				// Формула: (n + 2^i)
				for (int l = i + pow(2, degree); l < len1; l += pow(2, degree)) { // Быстрее проходимся по массиву, сравнивая элементы
					if (LeftPart[l] < data[rightpos + j])
						++degree;
					else { // Если очередной сравниваемый элемент оказался меньше, то возвращаемся к прошлой итерации
						l -= pow(2, degree);
						while (i < l)
							data[k++] = LeftPart[i++]; // Копируем все подходящие элементы в наш итоговый массив
						break; // Выходим из режима галопа
					}
				}
			}

			else { // REPEATS (7) раз произошла ситуация, когда элемент из правой части меньше очередного элемента из левой
				repeats2 = 0;
				// Формула: (n + 2^i)
				for (int r = j + rightpos + pow(2, degree); r < right; r += pow(2, degree)) { // Быстрее проходимся по массиву, сравнивая элементы
					if (data[r] < LeftPart[i])
						++degree;
					else { // Если очередной сравниваемый элемент оказался меньше, то возвращаемся к прошлой итерации
						r -= pow(2, degree);
						while (j + rightpos < r)
							data[k++] = data[rightpos + j++];
						break; // Выходим из режима галопа
					}
				}
			}
		}

		if (LeftPart[i] <= data[rightpos + j]) { // Сравниваем элементы и заносим наименьший в итоговый массив
			data[k] = LeftPart[i++];
			++repeats1;
			repeats2 = 0;
		}

		else {
			data[k] = data[rightpos + j++];
			++repeats2;
			repeats1 = 0;
		}

		++k;
	}

	// Оставшиеся элементы из левого массива заносим в основной (если они есть)
	while (i < len1) {
		data[k] = LeftPart[i++];
		++k;
	}
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