#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <clocale>
#include <stdlib.h>
#include <limits.h>


using namespace std;
int i, j, m, n, v;
int** graph;
int counter;
bool sr = false;
int nachalo;
int k, p;
int main(void)
{
	k = 1;
	while (k == 1) {
		setlocale(LC_ALL, "Rus");
		srand(time(NULL));
		printf("Создание матрицы смежности\n");
		printf("Введите с клавиатуры желаемое количество вершин в матрице:  ");
		scanf("%d", &m);
		while (m == 0 || m < 0) {
			printf("\nОшибка!!!\n");
			printf("Введите с клавиатуры количество вершин в матрице (больше нуля):  ");
			scanf("%d", &m);
		}
		n = m;
		graph = new int* [m];
		for (int i = 0; i < m; i++) {
			graph[i] = new int[m];
		}
		//генерация матрицыы
		for (i = 0; i < m; ++i) {
			for (j = i; j < m; ++j) {
				graph[i][j] = graph[j][i] = rand() % 2;
			}
			graph[i][i] = 0; //обнуление вершины
		}
		for (i = 0; i < n; i++) //отзеркаливание матрицы
		{
			for (j = 0; j < n; j++)
			{
				graph[j][i] = graph[i][j];
			}
		}


		printf("Матрица смежности: \n");
		//нумерование столбцов
		printf("\n     ");
		for (int i = 0; i < n; i++) {
			printf("[%d] ", i + 1);
		}

		printf("\n");

		//нумерование строк
		for (i = 0; i < m; ++i)
		{
			printf("[%d] ", i + 1);
			for (j = 0; j < m; ++j) {
				if ((i + 1) < 10)
				{
					if (j < 10)
						printf("%3d ", graph[i][j]);
					else
						printf(" %3d ", graph[i][j]);

				}

				else if ((i + 1) < 100)
				{
					if (j == 0)
						printf(" %d", graph[i][j]);
					else if (j < 10)
						printf("   %d", graph[i][j]);
					else
						printf("    %d", graph[i][j]);

				}

			}
			printf("\n");
		}

		printf("\nМатрица инцидентности: \n");
		int reb = 0;
		int ch = 0;

		while (ch != n)
			for (int i = 0; i < n; i++)
			{
				for (int j = 0 + ch; j < n; j++)
					if (graph[i][j] != 0)
						reb++;
				ch++;
			}
		/////

		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (graph[i][j] != 0)
					graph[j][i] = 0;

		int** inc;

		inc = (int**)malloc(n * sizeof(int*));
		for (int i = 0; i < n; i++)
		{
			inc[i] = (int*)malloc(reb * sizeof(int));
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < reb; j++)
				inc[i][j] = 0;

		int	ch1 = reb;
		reb = 0;
		for (int i = 0; i < n; i++)				//создание матрицы инцидентности
		{
			for (int j = 0; j < n; j++)
				if (graph[i][j] != 0)
				{
					inc[i][reb] = 1;				//начало
					inc[j][reb] = 1;				//конец
					reb++;
				}
		}

		printf("\n    ");
		for (int i = 0; i < ch1; i++) {
			printf("[%d] ", i + 1);
		}
		for (int i = 0; i < n; i++)
		{
			printf("\n[%d]", i + 1);

			for (int j = 0; j < reb; j++)
			{
				if ((i + 1) < 10)
				{
					if (j < 10)
						printf("%3d ", inc[i][j]);
					else
						printf(" %3d ", inc[i][j]);

				}

				else if ((i + 1) < 100)
				{
					if (j == 0)
						printf(" %d", inc[i][j]);
					else if (j < 10)
						printf("   %d", inc[i][j]);
					else
						printf("    %d", inc[i][j]);

				}

			}
		}
		printf("\n");
		printf("Независимые рёбра: ");
		counter = 1;
		for (int i = 0; i < reb; i++) {
			for (int j = i + 1; j < reb; j++) {
				sr = false;
				
				for (int k = 0; k < n; k++) {
					if (inc[k][i] == 1 && inc[k][j] == 1) {
						sr = true;
					}
				}
				if (sr == false) {
					counter = 0;
					printf("\n%d - %d\n", i + 1, j + 1);
					

				}
			}
		}
		if (counter == 1) {
			printf("таких рёбер не встретилось");
		}


		printf("\n \n \n");
		printf("Если хотите начать программу занова нажмите: 1, а если хотите закончить программу нажмите: 0 \n");
		if (scanf("%d", &nachalo) != 1 || nachalo == 0) return 0;
		nachalo = k;
		if (k == 1) {
			k = true;
			system("cls");
		}
	}

	return 0;
}
