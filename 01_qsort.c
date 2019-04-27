#include <stdio.h>

double Sort(int* numbers, int left, int right)
{
int supp;
int l = left;
int r = right;
supp = numbers[left];

while (left < right)
{
while ((numbers[right] >= supp) && (left < right))
{
right--;
}
if (left != right)
{
numbers[left] = numbers[right];
left++;
}
while ((numbers[left] <= supp) && (left < right))
{
left++;
}

if (left != right)
{
numbers[right] = numbers[left];
right--;
}
}
numbers[left] = supp;
supp = left;
left = l;
right = r;
if (left < supp)
Sort(numbers, left, supp - 1);
if (right > supp)
Sort(numbers, supp + 1, right);
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
Sort(a, 0, f - 1);

for (int i = 0; i < f; i++)
printf("%d ", a[i]);

printf("\n");
}
