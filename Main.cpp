#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>
#include <ctime>
#include "Header.h"

// 2.	����� ����� ��������� k-�� �������.


int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(NULL));

	int N, v, n, m, A, B, k;
	int arr[50][50];

	do {
		printf_s(" 1 - ����������\n 2 - ����. ����� �� � �� �\n 3 - �������\n 4 - �����. ����\n 5 - ���. ����\n"); scanf_s("%d", &N);
		printf_s("�����: \n1 - �� �����\n2 - � �����. ����\n3 - ���. ����\n"); scanf_s("%d", &v);
		if  (N < 1 || N > 5 || v > 3 || v < 1) printf_s("������\n");
	} while (N < 1 || N > 5 || v > 3 || v < 1);

	do {
		printf_s("����� - "); scanf_s("%d", &n);
		printf_s("�������� - "); scanf_s("%d", &m);
		printf_s("������� k - "); scanf_s("%d", &k);

		if  (m < 0 || n < 0 || m > 50 || n > 50 || k < 1 || k > m) printf_s("������\n");
	} while (m < 0 || n < 0 || m > 50 || n > 50 || k < 1 || k > m);

	k -= 1;

	switch (N)
	{
	case 1:
		In(*arr, n, m);

		Out(*arr, n, m, v, k);

		break;

	case 2:
		do {
			printf_s("A = "); scanf_s("%d", &A);
			printf_s("(B>A) B = "); scanf_s("%d", &B);
			printf_s("\n");
		} while (A > B );

		InRand(*arr, n, m, A, B);

		Out(*arr, n, m, v, k);

		break;

	case 3:
		InForm(*arr, n, m);

		Out(*arr, n, m, v, k);

		break;

	case 4:

		InTxt(*arr, n, m);

		Out(*arr, n, m, v, k);

		break;
	
	case 5:

		InBin(*arr, n, m);

		Out(*arr, n, m, v, k);

		break;
	}

	return 1;
}
