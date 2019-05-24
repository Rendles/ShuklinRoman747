#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pascheska(int* array, int lenght)
{
	int tmp = 0;


	int jmp = lenght, i;
	int stp = 1;
	while (jmp > 1 || stp)
	{
		if (jmp > 1) {
			jmp /= 1.24733;
		}
		stp = 0;
		for (i = 0; i + jmp < lenght; ++i)
			if (array[i + jmp] > array[i])
			{
				tmp++;
				int tmp;
				tmp = array[i];
				array[i] = array[i + jmp];
				array[i + jmp] = tmp;
				stp = 1;
				tmp++;
			}

	}

	return tmp;
}

int main()
{
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
				a[i] = rand() % 10000 - 8419;
			}
			rez = pascheska(a, n[f]);
			sr_rez += rez;
		}
		stop = clock();
		printf("%d\n %f \n", n[f], sr_rez / 1000);
		sr_rez = 0;
		rez = 0;
		double clock_rez = (stop - start) / (double)CLOCKS_PER_SEC;
		printf("%f \n", clock_rez * 100000);
		start, stop = 0;
		clock_rez = 0;
	}
}
