[TOC]

基数排序(Radix Sort)
---

基数排序，言外之意就是通过基数来排序。所谓的基数，就像十进制里面的每个位数，在二进制里面就是bit位。  
基数排序对数据的每个位进行排序，遍历所有位后，整个数据便排好了，一般遍历方向是LSB-->MSB。  

我们又要使用算法导论上的例子了。  
这是我们要进行排序的一组数据。  
```md
	3 2 9
	4 5 7
	6 5 7
	8 3 9
	4 3 6
	7 2 0
	3 5 5
```
(1)首先是对个位进行排序  
```md
	3	2	|9|		-->		7	2	|0|		
	4	5	|7|		-->		3	5	|5|		
	6	5	|7|		-->		4	3	|6|		
	8	3	|9|		-->		4	5	|7|		
	4	3	|6|		-->		6	5	|7|		
	7	2	|0|		-->		3	2	|9|		
	3	5	|5|		-->		8	3	|9|		
```
(2)然后对十位进行排序
```md
	7	|2|	  0		-->		7	|2|	  0
	3	|5|	  5		-->		3	|2|	  9
	4	|3|	  6		-->		4	|3|	  6
	4	|5|	  7		-->		8	|3|	  9
	6	|5|	  7		-->		3	|5|	  5
	3	|2|	  9		-->		4	|5|	  7
	8	|3|	  9		-->		6	|5|	  7
```
(3)最后对百位进行排序
```md
	|7|	  2	  0		-->		|3|	  2	  9
	|3|	  2	  9		-->		|3|	  5   5
	|4|	  3	  6		-->		|4|	  3	  6
	|8|	  3	  9		-->		|4|	  5	  7
	|3|	  5	  5		-->		|6|	  5	  7
	|4|	  5	  7		-->		|7|	  2	  0
	|6|	  5	  7		-->		|8|	  3	  9
```
从上面可以看出多所有位进行遍历操作后数据排好。    
基于上面的思考，我写的程序如下：  
```C
void radix_sort(int *A, int A_length, int A_bit_length)
{
    int i,j;
    int C_length = 0;
    int *B, *C, *temp;

    C_length =  9; // 十进制数最大为9

    C = (int *)malloc(sizeof(int)*(C_length + 1));  // C中值从0开始
    B = (int *)malloc(sizeof(int)*A_length);
    temp = (int *)malloc(sizeof(int)*A_length);
    // count sort进行位的排序
    for(j = 1; j <= A_bit_length; j++)
    {
        select_array_bit(temp, A, A_length, j);	// temp中放的是拆分后的位数据
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
            A[i] = B[i];	// 通过拆分的位排序后留下的踪迹，将源数据放入指定位置处
    }
    B = NULL;
    C = NULL;
    temp = NULL;
    free(temp);
    free(B);
    free(C);
}
```
中间使用动态分配是为了保证函数接口的简单。  
基数排序也是线性时间O(d(n+k))，其中d为位数或者变换后的位数，k为各位的最大值。  

完整程序[program](https://github.com/yokay/JustForStudy/blob/master/src/count_sort.c)
