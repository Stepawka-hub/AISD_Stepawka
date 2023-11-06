#include "Sorting.h"
#include <cmath>
#include <iostream>

#define REPEATS 7

int GetMinrun(int N) { // ������� minrun
	int M = 0;
	while (N >= 64) {
		M |= N & 1;
		N >>= 1;
	}

	return M + N;
}

void SortingInserts (int Array[], int left, int right) { // ���������� ����������� ���������
	for (int i = left + 1; i <= right; ++i) { // �������, ��� ������ ������� ��� ��� ��������������� ����� �������
		int temp = Array[i]; // �������, ������� ����� ������������ � ���������� ��������������� �����
		int k = i - 1; // ������ ���������� �������� � ��������������� ����� (�������� ���������� � ��� �����)

		while (k >= left && Array[k] > temp) { // ���� ������� �� �� ��������������� ����� ������, ��� k-�� ������� � ��������������� ����� (���� ������ �������)
			Array[k + 1] = Array[k];
			Array[k] = temp;
			--k;
		}
	}
}

//void MergingArrays(int Array[], int left, int mid, int right) { // �������� �� ������� ����� ����� (������� �������, ��� � ������� len2 - ������ ������)
//	int len1 = mid - left + 1, len2 = right - mid;
//    int * LeftPart = new int [len1]; 
//	
//	for (int i = 0; i < len1; ++i)
//	    LeftPart[i] = Array[left + i]; // ��������� ����� ����� (����� ���������)
//	
//	int i = 0, j = 0, k = left; // ���������� ��� ��� ������� � ���� ���� ���������
//	while (i < len1 && j < len2) { // ���� ������� i � j �� ������ �� ����� ��������
//	    if (LeftPart[i] <= Array[len2 + j]) // ���������� �������� � ������� ���������� � �������� ������
//	        Array[k] = LeftPart[i++];
//	    else
//	        Array[k] = Array[len2 + j++];
//	    ++k;
//	}
//	
//	// ���������� �������� �� ������ ������� ������� � �������� (���� ��� ����)
//	while (i < len1) {
//	    Array[k] = LeftPart[i++];
//	    ++k;
//	}
//
//}

void MergingArrays(int Array[], int left, int mid, int right) { // �������� �� ������� ����� ����� (������� �������, ��� � ������� len2 - ������ ������)
	int len1 = mid - left + 1, len2 = right - mid, repeats1 = 0, repeats2 = 0;
	int* LeftPart = new int[len1];

	for (int i = 0; i < len1; ++i)
		LeftPart[i] = Array[left + i]; // ��������� ����� ����� (����� ���������)

	int i = 0, j = 0, k = left, rightpos = mid + 1; // ���������� ��� ��� ������� � ���� ���� ���������
	while (i < len1 && j < len2) { // ���� ������� i � j �� ������ �� ����� ��������
		if (repeats1 >= REPEATS || repeats2 >= REPEATS) { // ���� ������� REPEATS ���������� (7)
			int degree = 0;
			if (repeats1 >= REPEATS) { // REPEATS (7) ��� ��������� ��������, ����� ������� �� ����� ����� ������ ���������� �������� �� ������
				repeats1 = 0;
				// �������: (n + 2^i)
				for (int l = i + pow(2, degree); l < len1; l += pow(2, degree)) { // ������� ���������� �� �������, ��������� ��������
					if (LeftPart[l] < Array[rightpos + j])
						++degree;
					else { // ���� ��������� ������������ ������� �������� ������, �� ������������ � ������� ��������
						l -= pow(2, degree);
						while (i < l)
							Array[k++] = LeftPart[i++]; // �������� ��� ���������� �������� � ��� �������� ������
						break; // ������� �� ������ ������
					}
				}
			}

			else { // REPEATS (7) ��� ��������� ��������, ����� ������� �� ������ ����� ������ ���������� �������� �� �����
				repeats2 = 0;
				// �������: (n + 2^i)
				for (int r = j + rightpos + pow(2, degree); r < right; r += pow(2, degree)) { // ������� ���������� �� �������, ��������� ��������
					if (Array[r] < LeftPart[i])
						++degree;
					else { // ���� ��������� ������������ ������� �������� ������, �� ������������ � ������� ��������
						r -= pow(2, degree);
						while (j + rightpos < r)
							Array[k++] = Array[rightpos + j++];
						break; // ������� �� ������ ������
					}
				}
			}
		}

		if (LeftPart[i] <= Array[rightpos + j]) { // ���������� �������� � ������� ���������� � �������� ������
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

	// ���������� �������� �� ������ ������� ������� � �������� (���� ��� ����)
	while (i < len1) {
		Array[k] = LeftPart[i++];
		++k;
	}

}