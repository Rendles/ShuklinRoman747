#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

double count = 0;

void down(int* num, int root, int bot)
{
int max;
int done = 0;

while ((root * 2 <= bot) && (!done))
{
if (root * 2 == bot)
{
max = root * 2;

}

else if (num[root * 2] > num[root * 2 + 1])
{
max = root * 2;
}
else
{
max = root * 2 + 1;
}

if (num[root] < num[max])
{
int temp = num[root];
num[root] = num[max];
num[max] = temp;
root = max;

}
else
done = 1;
}
}
int main()
{
int f = 0;
scanf("%d", &f);
int a[f];
for (int j = 0; j < f; j++)
{
scanf("%d", &a[j]);
}

for (int i = (f / 2); i >= 0; i--)
down(a, i, f - 1);

for (int i = f - 1; i >= 1; i--)
{
int temp = a[0];
a[0] = a[i];
a[i] = temp;
down(a, 0, i - 1);
}
for (int i = 0; i < f; i++)
printf("%d ", a[i]);
printf("\n");
}
