#include <stdio.h>
#include <malloc.h>

int main()
{
 int a, n;
 int i = 1;
 int sum = 0;
 scanf("%d" ,&n);
 while (i<=n)
 {
 scanf("%d", &a);
 sum = sum + (a-i);
 i++;
 }
 printf("%d",sum);
}

