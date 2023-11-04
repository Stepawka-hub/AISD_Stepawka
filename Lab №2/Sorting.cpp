#include "Sorting.h"

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

void MergingArrays (int Array[], int left, int mid, int right) { // Разбиваем массив на две части - Левую часть и правую часть
    int len1 = mid - left + 1, len2 = right - mid;
    int * LeftPart = new int [len1], * RightPart = new int [len2]; 

    for (int i = 0; i < len1; ++i)
        LeftPart[i] = Array[left + i]; // Заполняем левую часть (Левый подмассив)

    for (int i = 0; i < len2; ++i)
        RightPart[i] = Array[mid + 1 + i]; // Заполняем правую часть (Правый подмассив)

    int i = 0, j = 0, k = left; // Объединяем эти два массива в один путём сравнения
    while (i < len1 && j < len2) { // Пока индексы i и j не дойдут до конца массивов
        if (LeftPart[i] <= RightPart[j]) // Сравниваем элементы и заносим наименьший в итоговый массив
            Array[k] = LeftPart[i++];
        else
            Array[k] = RightPart[j++];
        ++k;
    }

    // Оставшиеся элементы из левого массива заносим в основной (если они есть)
    while (i < len1) {
        Array[k] = LeftPart[i++];
        ++k;
    }

    // Аналогично с правым массивом
    while (j < len2) {
        Array[k] = RightPart[j++];
        ++k;
    }
}