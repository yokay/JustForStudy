[TOC]

快速排序(续)
---
前面稍微讲了下快速排序算法，在讲解过程中也发现，如果数据已经排好，或者部分排好，那么就会出现交换自身的过程，这对排序的速度很有影响。从中我们也可以发现一个规律，就是交换的总是从最后往前小于基数的数和从第一个往后大于基数的数。这样对已排序的部分进行循环检测，直到满足交换的那种性质。  
这里以实例说明：  
```C
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
    tail_recursive_quicksort(num, 0, 13);
    for (i = 0; i < 14; i++)
        printf("%d\n", num[i]);
}

```
结果为：1 2 2 3 3 4 4 5 6 6 7 8 9 10  

其实这种方式是快速排序发明人的原始方法，Hoare partition的方式。这种方式的好处就是可以避免已排序的再次排序。  
对于排序的递归调用，采用深度递归或者尾递归。后者递归深度较小。  
采用快速排序可以直接在当前数组中执行，无需额外空间。  
其最坏时间复杂度为O(N^2)，平均时间复杂度为O(nlgn)。在实际应用中，快速排序应用较多。
