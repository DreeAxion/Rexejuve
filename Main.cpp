#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>
#include <ctime>
#include "Header.h"

// 2.	Найти сумму элементов k-го столбца.


int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(NULL));

	int N, v, n, m, A, B, k;
	int arr[50][50];

	do {
		printf_s(" 1 - клавиатура\n 2 - случ. числа от А до В\n 3 - формула\n 4 - текст. файл\n 5 - бин. файл\n"); scanf_s("%d", &N);
		printf_s("Вывод: \n1 - на экран\n2 - в текст. файл\n3 - бин. файл\n"); scanf_s("%d", &v);
		if  (N < 1 || N > 5 || v > 3 || v < 1) printf_s("Ошибка\n");
	} while (N < 1 || N > 5 || v > 3 || v < 1);

	do {
		printf_s("Строк - "); scanf_s("%d", &n);
		printf_s("Столбцов - "); scanf_s("%d", &m);
		printf_s("Столбец k - "); scanf_s("%d", &k);

		if  (m < 0 || n < 0 || m > 50 || n > 50 || k < 1 || k > m) printf_s("Ошибка\n");
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
