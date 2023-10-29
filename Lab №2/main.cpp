#include <iostream>
#include "TApplication.h"
#include "linked_list.h"

/*
1. Сортировка вставками
2. Поиск последовательностей run
3. Подсчёт minrun
4. Слияние последовательностей run
5. Режим галопа при слиянии
*/

int main() {
    setlocale(LC_ALL, "");

    TApplication Application;
    Application.Executor();

    return 1;
}