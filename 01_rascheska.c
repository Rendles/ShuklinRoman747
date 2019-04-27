#include <stdio.h>
#include <stdlib.h>

int poisk(int shag)
{
shag = (int)(shag / 1.247);
if (shag < 1)
shag = 1;
return shag;
}
void sort(int arr[], int N)
{
int shag = N;
while (1)
{
shag = poisk(shag);
int swap = 0;
for (int i = 0; i < N - shag; i++)
{
int j = i + shag;
if (arr[i] > arr[j])
{
int t = arr[i];
arr[i] = arr[j];
arr[j] = t;
swap = 1;
}
}
if (shag == 1 && !swap)
break;
}
}
int main()
{
int n;
scanf("%d", &n);
int a[n];
for (int i = 0; i < n; i++)
{
scanf("%d", &a[i]);
}
sort(a, n);
for (int i = 0; i < n; i++)
{
printf("%d ", (a[i]));
}
printf("\n");
}
