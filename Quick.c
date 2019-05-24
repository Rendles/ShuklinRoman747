#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int quick(int* arr, int lenght) {
	int tem = 0;
	int size = lenght;
	int r = 0;
	int t = arr[(int)(lenght / 2)];
	int tmp = 0;
	do {
		while (arr[r] < t) r++;
		while (arr[lenght] > t) lenght--;

		if (r <= lenght) {
			tmp = arr[r];
			arr[r] = arr[lenght];
			arr[lenght] = tmp;
			r++;
			lenght--;
			tem++;
		}tem++;
	} while (r <= lenght);
	if (lenght > 0) { tem += quick(arr, lenght); }
	if (lenght > 0) { tem += quick(arr + r, size - r); }
	return tem;
}

int main()
{
	srand(time(0));
	clock_t start, stop;
	unsigned long t;
	double rez, sr_rez = 0;
	int n[15] = { 1,2,3,4,5,10,15,20,25,30,50,75,100,250,500 };
	for (int f = 0; f < 15; f++)
	{
		int* a;
		a = (int*)malloc(n[f] * sizeof(int));
		start = clock();
		for (int j = 0; j < 1000; j++)
		{
			for (int i = 0; i < n[f]; i++)
			{
				a[i] = rand() % 10000 - 8000;
			}
			rez += quick(a, n[f]);
		}
		stop = clock();
		printf("%d\n %f \n", n[f], rez / 1000);
		rez = 0;
		double clock_rez = (stop - start) / (double)CLOCKS_PER_SEC;
		printf("%f \n", clock_rez * 100000);
		start, stop = 0;
		clock_rez = 0;
	}
}
