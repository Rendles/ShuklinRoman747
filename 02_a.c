#include <stdio.h>
#include <malloc.h>

int main()
{
 int *a;
 int n, i;
 int sum = 0;
 scanf("%d" ,&n);
 a = (int*)malloc(n * sizeof(int));
 for (i = 0; i<n; i++)
 {
 scanf("%d", &a[i]);
 }
 for (i = 0; i<n; i++)
 {
 sum = sum + (a[i] - i);
 }
 printf("%d",sum);
}

