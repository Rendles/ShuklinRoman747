#include <stdlib.h>
#include <stdio.h>


void jmp(int* x, int* y) 
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int* srch(int array[5][5], int size, int a)
{
	int* lenght = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) 
	{
		if (i == a)
			lenght[i] = 0;
		else
			lenght[i] = 1000;
	}
	int t, minr, minv, pos[5] = { 1, 1, 1, 1, 1 };
	do 
	{
		minr = 1000;
		minv = 1000;
		for (int i = 0; i < size; i++) 
		{
			if ((pos[i] == 1) && (lenght[i] < 1000)) 
			{
				minr = lenght[i];
				minv = i;
			}
		}
		if (minv != 1000) 
		{
			for (int i = 0; i < size; i++) 
			{
				if (array[minv][i] > 0)
				{
					t = minr + array[minv][i];
					if (t < lenght[i])
						lenght[i] = t;
				}
			}
			pos[minv] = 0;
		}
	} 
	while (minv < 1000);
	return lenght;
}
int contr(int* a, int g[5][5], int n, int cost)
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				g[i][j] = 0;
			else 
			{
				if (g[i][j] == 0)
					g[i][j] = 1000;
			}
		}
	}
	int temp = 0;
	int gr = 0;
	int sum = 0;
	for (int i = 0; i <= n - 1; i++)
		sum += g[a[i % 5]][a[(i + 1) % 5]];
	if (cost > sum)
	{
		cost = sum;
	}
	while (gr < 119) 
	{
		sum = 0;
		int j = n - 2;
		while (j != -1 && a[j] >= a[j + 1])
			j--;
		if (j == -1)
			gr = 119;
		int k = n - 1;
		while (a[j] >= a[k])
			k--;
		{
			jmp(&a[j], &a[k]);
		}
		int l = j + 1, r = n - 1;
		while (l < r)
			jmp(&a[l++], &a[r--]);
		for (int i = 0; i <= n - 1; i++)
			sum += g[a[i % 5]][a[(i + 1) % 5]];
		if (cost > sum)
			cost = sum;
		gr++;
	};
	return cost;
}
int main()
{
	int LengthMass = 0;
	printf("Vershin: ");
	scanf("%d", &LengthMass);
	int graph[LengthMass][LengthMass];

	for (int i = 0; i < LengthMass; i++)
	{
		for (int j = 0; j < LengthMass; j++)
		{
			printf("Lenght %d to %d ", i + 1, j + 1);
			scanf("%d", &graph[i][j]);
		}
	}



	int* arr = (int*)malloc(LengthMass * sizeof(int));
	for (int i = 0; i < LengthMass; i++)
		arr[i] = i;
	int z = 1;
	for (int i = 0; i < LengthMass; i++)
	{
		for (int j = 0; j < LengthMass; j++) 
		{
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
	int v;
	printf("First\n");
	scanf("%d", &v);
	int* f = srch(graph, LengthMass, v - 1);
	for (int i = 0; i < LengthMass; i++)
	{
		if (f[i] <= 9999) 
		{
			printf("Minimum way from %d to %d: %d\n", v, z, f[i]);
		}
		z++;
	}
	int min = contr(arr, graph, LengthMass, 9999);
	if (min <= 9999) 
	{
		printf("Minimum contour %d\n", min);
	}
	return 0;
}
