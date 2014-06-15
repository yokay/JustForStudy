/*-----------------------------------------------------------------------
** Copyright       :  Copyright (c) 2013-2014  ---------------------
** File Name       :  heap_sort.c
** File tag        :
** Summary         :
** Current Version :  v1.0
** Author          :
** Finish date     :  2014-3-18
** Modify records  :
** Modify records  :
** Modify date     :
** Version         :
** Modify Author   :
** Modify content  :
-----------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
/*-----------------------------------------------------------------------
** Function Name   : exy
** Function Profile:
** Input           :
** Output          :
** Return          :
-------------------------------------------------------------------------------*/
int exy(int x)
{
	int tmp;
	int result = 1;
	if (x ==0) return 1;
	for (tmp = 1; tmp <= x; tmp++)
		result *=2;
	return result;
}
/*-----------------------------------------------------------------------
** Function Name   : exchange_num
** Function Profile:
** Input           :
** Output          :
** Return          :
-------------------------------------------------------------------------------*/
void exchange_num(int * one, int * two)
{
	int tmp;
	tmp = *two;
	*two = *one;
	*one = tmp;
}
/*-----------------------------------------------------------------------
** Function Name   : parent
** Function Profile:
** Input           :
** Output          :
** Return          :
-------------------------------------------------------------------------------*/
int parent(int index)
{
    // 当节点为根节点时，其父节点为它本身
    if (index == 0)
        return 0;
	return (index-1)/2;
}
/*-----------------------------------------------------------------------
** Function Name   : left
** Function Profile: index first is 0
** Input           :
** Output          :
** Return          :
-------------------------------------------------------------------------------*/
int left(int index)
{
	return (index * 2 + 1);
}
/*-----------------------------------------------------------------------
** Function Name   : right
** Function Profile: index first is 0
** Input           :
** Output          :
** Return          :
-------------------------------------------------------------------------------*/
int right(int index)
{
	return (index * 2 + 2);
}
/*-----------------------------------------------------------------------
** Function Name   : max_heapify
** Function Profile:
** Input           :
** Output          :
** Return          :
** Author          :
** Date            :  2014-3-18
** Version         :  1.0
-------------------------------------------------------------------------------*/
void max_heapify(int * num, int index, int num_length)
{
	/*index:表示节点的索引*/
	int left_index, right_index, max_index;

	left_index = left(index);
	right_index = right(index);
	/* left_index 和　right_index <= num_length-1*/
	if ((left_index < num_length) && (num[left_index] > num[index]) )
		max_index = left_index;
	else
		max_index = index;
	if ((right_index < num_length) && (num[right_index] > num[max_index]))
		max_index = right_index;
	if (max_index != index) {
		exchange_num(num + index, num + max_index);
		max_heapify(num, max_index, num_length);
	}
}

/*-----------------------------------------------------------------------
** Function Name   : min_heapify
** Function Profile:
** Input           :
** Output          :
** Return          :
-------------------------------------------------------------------------------*/
void min_heapify(int * num, int index, int num_length)
{
	int left_index, right_index, min_index;

	left_index = left(index);
	right_index = right(index);
	if ((left_index < num_length)&& (num[left_index] < num[index]) )
		min_index = left_index;
	else
		min_index = index;
	if ((right_index < num_length)&& (num[right_index] < num[min_index]))
		min_index = right_index;
	if (min_index != index) {
		exchange_num(num + index, num + min_index);
		min_heapify(num, min_index, num_length);
	}
}
/*-----------------------------------------------------------------------
** Function Name   : build_max_heap
** Function Profile:
** Input           :
** Output          :
** Return          :
-------------------------------------------------------------------------------*/
void build_max_heap(int *num, int num_length)
{
	int count;
	for (count = (num_length-1)/2; count >=0; count--)
	{
		max_heapify(num, count, num_length);
		//printf("%d\n", num[height]);
	}
}

/*-----------------------------------------------------------------------
** Function Name   : build_min_heap
** Function Profile:
** Input           :
** Output          :
** Return          :
-------------------------------------------------------------------------------*/
void build_min_heap(int *num, int num_length)
{
	int height;
	for (height = (num_length-1)/2; height >=0; height--)
	{
		min_heapify(num, height, num_length);
		//printf("%d\n", num[height]);
	}
}

/*-----------------------------------------------------------------------
** Function Name   : heap_sort
** Function Profile:
** Input           :
** Output          :
** Return          :
-------------------------------------------------------------------------------*/
void heap_sort(int *num, int num_length)
{
	int leaf;
	int heap_size;
	heap_size = num_length;
	build_max_heap(num, num_length);

	for (leaf = (num_length-1); leaf > 0; leaf--) {
		exchange_num(&num[0], &num[leaf]);
		heap_size = heap_size - 1;
		max_heapify(num, 0, heap_size);
	}
}

/*-----------------------------------------------------------------------
** Function Name   : heap_maximum
** Function Profile:
** Input           :
** Output          :
** Return          :
** Date            :  2014-4-14
-------------------------------------------------------------------------------*/
int heap_maximum(int *num)
{
	return num[0];
}
/*-----------------------------------------------------------------------
** Function Name   : heap_extract_max
** Function Profile:
** Input           :
** Output          :
** Return          :
** Date            :  2014-4-14
-------------------------------------------------------------------------------*/
int heap_extract_max(int *num, int num_length)
{
	int max;
	int heap_size;
	heap_size = num_length;
	if (heap_size < 1) {
		printf("heap underflow\n");
		return 0;
	}

	max = num[0];
	num[0] = num[heap_size - 1];
	heap_size -= 1;
	max_heapify(num, 0, heap_size);
	return max;
}
/*-----------------------------------------------------------------------
** Function Name   : heap_increase_key
** Function Profile:
** Input           :
** Output          :
** Return          :
** Date            :  2014-4-14
-------------------------------------------------------------------------------*/
void heap_increase_key(int *num, int index, int key, int num_length)
{
	int heap_size;
	heap_size = num_length;
	if (key < num[index]) {
		printf("new key is smaller than current key");
		exit(0);
	}

	num[index] = key;
	while ((index > 0) && (num[parent(index)] < num[index])) {
		exchange_num(num+index, num+parent(index));
		index = parent(index);
	}
}
/*-----------------------------------------------------------------------
** Function Name   : max_heap_insert
** Function Profile:
** Input           :
** Output          :
** Return          :
** Date            :  2014-4-14
-------------------------------------------------------------------------------*/
void max_heap_insert(int *num, int key, int num_length)
{
	int heap_size;
	heap_size = num_length + 1;
	num[num_length] = 0;
	heap_increase_key(num, num_length, key, heap_size);
}
/*-----------------------------------------------------------------------
** Function Name   : main
** Function Profile:
** Input           :
** Output          :
** Return          :
-------------------------------------------------------------------------------*/
void main()
{
	int show = 0;
	int line = 0;
	int number[1024] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

    heap_sort(number,10);
	max_heap_insert(number, 25, 10);
	//printf("max is %d\n", heap_extract_max(number, 11));
	for (show = 0; show < 11; show++)
		printf("%d ", number[show]);
}
