#include <stdio.h>

void exchange(int *first, int *second)
{
    int tmp;
    tmp = *first;
    *first = *second;
    *second = tmp;
}
// Hoare partition corrctness
int partition(int A[], int p, int r)
{
    int x;
    int i,j;
        
    x = A[p];
    i = p;
    j = r + 1;

    while (1)
    {
        while ((i <= r) && (A[++i] < x));
        while ((j > 0) && (A[--j] > x));
        if (i >= j)
            break;
        exchange(A + j, A + i);
    }
    exchange(A + p, A + j);
    return j;
}

void quicksort(int A[], int p, int r)
{
    int q = 0;
    if (p < r)
    {
        q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}
void tail_recursive_quicksort(int A[], int p, int r)
{
    int q = 0;
    while (p < r)
    {
        q = partition(A, p, r);
        tail_recursive_quicksort(A, p, q - 1);
        p = q + 1;
    }
}

int main(void)
{
    int i;
    int num[] = {2, 3, 5, 1, 7, 8, 6, 4, 2, 3, 6, 9, 10, 4};
    printf("q = %d\n", partition(num, 0, 13));
    //quicksort(num, 0, 13);
    tail_recursive_quicksort(num, 0, 13);
    for (i = 0; i < 14; i++)
        printf("%d\n", num[i]);
}
