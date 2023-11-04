#include "Sorting.h"

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

void MergingArrays (int Array[], int left, int mid, int right) { // ��������� ������ �� ��� ����� - ����� ����� � ������ �����
    int len1 = mid - left + 1, len2 = right - mid;
    int * LeftPart = new int [len1], * RightPart = new int [len2]; 

    for (int i = 0; i < len1; ++i)
        LeftPart[i] = Array[left + i]; // ��������� ����� ����� (����� ���������)

    for (int i = 0; i < len2; ++i)
        RightPart[i] = Array[mid + 1 + i]; // ��������� ������ ����� (������ ���������)

    int i = 0, j = 0, k = left; // ���������� ��� ��� ������� � ���� ���� ���������
    while (i < len1 && j < len2) { // ���� ������� i � j �� ������ �� ����� ��������
        if (LeftPart[i] <= RightPart[j]) // ���������� �������� � ������� ���������� � �������� ������
            Array[k] = LeftPart[i++];
        else
            Array[k] = RightPart[j++];
        ++k;
    }

    // ���������� �������� �� ������ ������� ������� � �������� (���� ��� ����)
    while (i < len1) {
        Array[k] = LeftPart[i++];
        ++k;
    }

    // ���������� � ������ ��������
    while (j < len2) {
        Array[k] = RightPart[j++];
        ++k;
    }
}