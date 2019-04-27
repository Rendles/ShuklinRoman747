    #include<stdio.h>
    void sort(int* arr, int N)
    {
    int i, j, m, k;
    for (m = N / 2; m > 0; m = m / 2)
    {
    for (i = m; i < N; i++)
    {
    for (j = i - m; j >= 0; j = j - m)
    {
    if (arr[j + m] >= arr[j])
    break;
    else
    {
    k = arr[j];
    arr[j] = arr[j + m];
    arr[j + m] = k;
    }
    }
    }
    }
    }
    int main()
    {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
    sort(a, n);
    int i = 0;
    while (n)
    {
    printf("%d ", a[i]);
    i++;
    if (i == n)break;
    }
    printf("\n");
    }


