#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>
#include <ctime>
#include "Header.h"

#define filein "C:\\Users\\itr-tt\\Desktop\\1.txt"
#define fileout "C:\\Users\\itr-tt\\Desktop\\2.txt"
#define fileinbin "4.bin"
#define fileoutbin "4.bin"


void In(int *arr, int n, int m)
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf_s("arr[%d][%d] = ", i, j); scanf_s("%d", &arr[i * n + j]);
		}
	}
}


void InForm(int* arr, int n, int m)
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i > j) arr[i * n + j] = i + j;
			if (i <= j) arr[i * n + j] = i * j;
		}
	}
}





void InRand(int* arr, int n, int m, int A, int B)
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i * n + j] = rand() % (B - A + 1) + A;
		}printf_s("\n");
	}

}



void InTxt(int* arr, int n, int m)
{
	FILE* f;

	errno_t err = fopen_s(&f, filein, "rt");

	if (err) printf_s("Файл не открылся\n");
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (!feof(f))
			{
				for (int j = 0; j < m; j++)
				{
					if (!feof(f)) fscanf_s(f, "%d ", &arr[i * n + j]); 
				}printf_s("\n");
			}
			
		}fclose(f);
	}
}


void InBin(int* arr, int n, int m)
{
	int sum;
	FILE* f;

	errno_t err = fopen_s(&f, fileinbin, "rb");

	if (err) printf_s("Файл не открылся\n");
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				arr[i * n + j] = getc(f);
			}
		}sum = getc(f);
		fclose(f);
	}
}


void Out(int* arr, int n, int m, int v, int k)
{
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += arr[i * n + k];
	}

	if (v == 1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				printf_s("%d  ", arr[i * n + j]);
			}printf_s("\n");
		}printf_s("Сумма = %d", sum);
	}


	if (v == 2)
	{
		FILE* f;
		errno_t err = fopen_s(&f, fileout, "wt");
		if (err)
			printf_s("Файл не открылся\n");
		else
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					fprintf_s(f, "%d  ", arr[i * n + j]);
				}fprintf_s(f, "\n");
			}fprintf_s(f, "Сумма = %d", sum);
			fclose(f);
		}
	}


	if (v == 3)
	{
		FILE* f;
		errno_t err = fopen_s(&f, fileoutbin, "wb");
		if (err)
			printf_s("Файл не открылся\n");
		else
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					putc(arr[i * n + j], f);
				}
			}//putc(sum, f);
			fclose(f);
		}
	}


}