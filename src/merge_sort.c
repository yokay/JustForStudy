#include <stdio.h>
// A[]为要排序的数组，p、q、r为索引值，数组从0开始计数的
void merge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1; //第一个数组个数
    int n2 = r - q; //第二个数组个数
    int i = 0;
    int j = 0;
    int k = 0;
    int L[n1 + 1];  //第一个数组最后一个数为极大值
    int R[n2 + 1];  //第二个数组最后一个数为极大值

    for (i = 0; i < n1; i++)
        L[i] = A[p + i];    //用第一个数组存A[]的前p:q的数据
    L[i] = 65536;
    for (j = 0; j < n2; j++)
        R[j] = A[q + j + 1];    //用第二个数组存A[]的后q+1:r的数据，第q个数据在第一个数组中
    R[j] = 65536;

    //将两个数组中小的数放在A[]中，则最终数据以升序排列
    i = 0;
    j = 0;
    for (k = p; k <= r; k++)    
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++; 
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}
void merge_sort(int A[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
    }
}
void main(void)
{
    int i;
    int number[] = {2, 4, 5, 7, 1, 2, 3, 6, 9};
    merge_sort(number, 0, 7);
    for (i = 0; i < 9; i++)
        printf("%d-", number[i]);
}
