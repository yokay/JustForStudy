#include <stdio.h>
#include <stdlib.h>
// 调用排序函数的回调函数
typedef void (*callsort)(int *data, int data_length);
void callback(callsort foo, int *data, int data_length)
{
    foo(data, data_length);
}
int find_max(int *A, int A_length)
{
    int max = 0;
    while(A_length--)
    {
        if(max <= A[A_length])
            max = A[A_length];
    }
    if(max <= A[A_length])
        max = A[A_length];
    return max;
}

// 书上的算法
void count_sort(int A[], int B[], int C[], int k, int A_length)
{
    int i;
    for (i = 0; i <= k; i++)
        C[i] = 0;
    for (i = 0; i < A_length; i++)
        C[A[i]] += 1;
    for (i = 1; i <= k; i++)
        C[i] = C[i] + C[i-1];
    for (i = (A_length - 1); i >=0; i--)
    {
        B[C[A[i]] - 1] = A[i];  //C中放的是个数
        C[A[i]] -= 1;
    }
}

void my_count_sort(int A[], int B[], int C[], int k, int A_length)
{
    int i,j;
    j = 0;
    for (i = 0; i <=k; i++)
        C[i] = 0;
    for (i = 0; i < A_length; i++)
        C[A[i]] += 1;
    for (i = 0; i <= k; i++)
    {
        while (C[i]--)
            B[j++] = i;
    }
}
void my_count_sort_two(int *A, int *B, int *C, int k, int A_length)
{
    int *tmp;
    int i;
    tmp = (int*)malloc(sizeof(int) * (k + 1));
    for (i = 0; i <=k; i++)
        tmp[i] = i;
    for (i = 0; i < A_length; i++)
        C[A[i]] += 1;
    for (i = 0; i <=k; i++)
    {
        while (C[i]--)
            *B++ = tmp[i];
    }
    tmp = NULL;
    free(tmp);
}
void count_sort_call(int *A, int A_length)
{
    int i;
    int C_length = 0;
    int *B, *C;
    C_length =  find_max(A, A_length);
    C = (int *)malloc(sizeof(int)*(C_length + 1));  // C中值从0开始
    B = (int *)malloc(sizeof(int)*A_length);
    count_sort(A, B, C, C_length, A_length);
    for (i = 0; i < A_length; i++)
        A[i] = B[i];
    B = NULL;
    C = NULL;
    free(B);
    free(C);
}
// 选择第几位的数字
int select_number_bit(int num, int bit)
{
    while(--bit)
    {
        num/=10;
    }
    return num%10;
}
void select_array_bit(int *temp, int *A, int A_length, int bit)
{
    int i;
    for(i = 0; i < A_length; i++)
        temp[i] = select_number_bit(A[i], bit);
}
void radix_sort(int *A, int A_length, int A_bit_length)
{
    int i,j;
    int C_length = 0;
    int *B, *C, *temp;

    C_length =  9; // 十进制数最大为9

    C = (int *)malloc(sizeof(int)*(C_length + 1));  // C中值从0开始
    B = (int *)malloc(sizeof(int)*A_length);
    temp = (int *)malloc(sizeof(int)*A_length);

    for(j = 1; j <= A_bit_length; j++)
    {
        select_array_bit(temp, A, A_length, j);
        for (i = 0; i <= C_length; i++)
            C[i] = 0;
        for (i = 0; i < A_length; i++)
            C[temp[i]] += 1;
        for (i = 1; i <= C_length; i++)
            C[i] = C[i] + C[i-1];
        for (i = (A_length - 1); i >=0; i--)
        {
            B[C[temp[i]] - 1] = A[i];  //C中放的是个数
            C[temp[i]] -= 1;
        }
        for(i = 0; i < A_length; i++)
            A[i] = B[i];
    }
    B = NULL;
    C = NULL;
    temp = NULL;
    free(temp);
    free(B);
    free(C);
}
int main(int argc, char* argv[])
{
    int i;
    int bit_number;
    if(argc < 0)
        exit(1);
    while(argc == 1);
    for (i = 0; i < argc; i++)
        printf("%s\n",argv[i]);
    bit_number = atoi(argv[1]);
    printf("bit_number:%d\n", bit_number);
    int num[10] = {12, 16, 13, 20, 32, 43, 50, 33, 45, 27};
    int num2[7] = {329, 457, 657, 839, 436, 720, 355};
    //int sort[8] = {0};
    //int tmp[6] = {};
    //my_count_sort_two(num, sort, tmp, 5, 8);
    //callback(count_sort_call, num, 10);
    radix_sort(num, 10, bit_number);
    for (i = 0; i <10; i++)
        printf("%d ", num[i]);
    return 0;
}


