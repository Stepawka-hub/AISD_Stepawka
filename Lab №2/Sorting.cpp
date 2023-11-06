#include "Sorting.h"
#include <cmath>
#include <iostream>

#define REPEATS 7

int GetMinrun(int N) { // Находим minrun
	int M = 0;
	while (N >= 64) {
		M |= N & 1;
		N >>= 1;
	}

	return M + N;
}

void SortingInserts (int Array[], int left, int right) { // Сортировка подмассивов вставками
	for (int i = left + 1; i <= right; ++i) { // Считаем, что первый элемент это уже отсортированная часть массива
		int temp = Array[i]; // Элемент, который будет сравниваться с элементами отсортированной части
		int k = i - 1; // Индекс последнего элемента в отсортированной части (является наибольшим в той части)

		while (k >= left && Array[k] > temp) { // Пока элемент из не отсортированной части меньше, чем k-ый элемент в отсортированной части (Ищет нужную позицию)
			Array[k + 1] = Array[k];
			Array[k] = temp;
			--k;
		}
	}
}

//void MergingArrays(int Array[], int left, int mid, int right) { // Отделяем от массива левую часть (условно считаем, что с позиции len2 - правый массив)
//	int len1 = mid - left + 1, len2 = right - mid;
//    int * LeftPart = new int [len1]; 
//	
//	for (int i = 0; i < len1; ++i)
//	    LeftPart[i] = Array[left + i]; // Заполняем левую часть (Левый подмассив)
//	
//	int i = 0, j = 0, k = left; // Объединяем эти два массива в один путём сравнения
//	while (i < len1 && j < len2) { // Пока индексы i и j не дойдут до конца массивов
//	    if (LeftPart[i] <= Array[len2 + j]) // Сравниваем элементы и заносим наименьший в итоговый массив
//	        Array[k] = LeftPart[i++];
//	    else
//	        Array[k] = Array[len2 + j++];
//	    ++k;
//	}
//	
//	// Оставшиеся элементы из левого массива заносим в основной (если они есть)
//	while (i < len1) {
//	    Array[k] = LeftPart[i++];
//	    ++k;
//	}
//
//}

void MergingArrays(int Array[], int left, int mid, int right) { // Отделяем от массива левую часть (условно считаем, что с позиции len2 - правый массив)
	int len1 = mid - left + 1, len2 = right - mid, repeats1 = 0, repeats2 = 0;
	int* LeftPart = new int[len1];

	for (int i = 0; i < len1; ++i)
		LeftPart[i] = Array[left + i]; // Заполняем левую часть (Левый подмассив)

	int i = 0, j = 0, k = left, rightpos = mid + 1; // Объединяем эти два массива в один путём сравнения
	while (i < len1 && j < len2) { // Пока индексы i и j не дойдут до конца массивов
		if (repeats1 >= REPEATS || repeats2 >= REPEATS) { // Было найдено REPEATS повторений (7)
			int degree = 0;
			if (repeats1 >= REPEATS) { // REPEATS (7) раз произошла ситуация, когда элемент из левой части меньше очередного элемента из правой
				repeats1 = 0;
				// Формула: (n + 2^i)
				for (int l = i + pow(2, degree); l < len1; l += pow(2, degree)) { // Быстрее проходимся по массиву, сравнивая элементы
					if (LeftPart[l] < Array[rightpos + j])
						++degree;
					else { // Если очередной сравниваемый элемент оказался меньше, то возвращаемся к прошлой итерации
						l -= pow(2, degree);
						while (i < l)
							Array[k++] = LeftPart[i++]; // Копируем все подходящие элементы в наш итоговый массив
						break; // Выходим из режима галопа
					}
				}
			}

			else { // REPEATS (7) раз произошла ситуация, когда элемент из правой части меньше очередного элемента из левой
				repeats2 = 0;
				// Формула: (n + 2^i)
				for (int r = j + rightpos + pow(2, degree); r < right; r += pow(2, degree)) { // Быстрее проходимся по массиву, сравнивая элементы
					if (Array[r] < LeftPart[i])
						++degree;
					else { // Если очередной сравниваемый элемент оказался меньше, то возвращаемся к прошлой итерации
						r -= pow(2, degree);
						while (j + rightpos < r)
							Array[k++] = Array[rightpos + j++];
						break; // Выходим из режима галопа
					}
				}
			}
		}

		if (LeftPart[i] <= Array[rightpos + j]) { // Сравниваем элементы и заносим наименьший в итоговый массив
			Array[k] = LeftPart[i++];
			++repeats1;
			repeats2 = 0;
		}

		else {
			Array[k] = Array[rightpos + j++];
			++repeats2;
			repeats1 = 0;
		}

		++k;
	}

	// Оставшиеся элементы из левого массива заносим в основной (если они есть)
	while (i < len1) {
		Array[k] = LeftPart[i++];
		++k;
	}

}