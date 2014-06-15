#include <stdio.h>

void insertion_sort(int *A, int A_length)
{
	int key;	//key值为当前值
	int i, j;	//用i,j去索引数据
	int tmp;	//用于暂存数据

	for (j = 1; j < A_length; j++)
	{
		key = A[j];	//从第二个数开始，j为第二个数
		i = j - 1;	//i为j前面的数
		while ((i >= 0)&& (A[i] > key))
		{
			tmp = A[i];
			A[i] = key;
			A[i+1] = tmp;
			i -= 1;
		}
	}
}

void main()
{
    int i = 0;
    int number[] = {5, 2, 4, 6, 1, 3};
    insertion_sort(number, 6);
    for (i = 0; i < 6; i++)
        printf("%d-", number[i]);
}
