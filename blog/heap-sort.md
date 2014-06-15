[TOC]

堆排序（HEAP SORT）
---

### 基本概念
堆排序采用二叉树结构来存取数据，并以数组的形式出现。  
一个采用堆排序的二叉树结构如下图所示。 
![堆排序二叉树结构](C:\Users\Wee Yokay\Desktop\Mythbird\blog\heapsort1.gif)  
变换成数组的形式就是：  

|0  |1  |2  |3  |4  |5  |6  |7  |8  |9  |
|---|---|---|---|---|---|---|---|---|---|
|16 |14 |10 |8  |7  |9  |3  |2  |4  |1  |

本人的下标方式与《算法导论》中标的不一致，这是为了在于程序中数组下标以0开始一致。  

从上面可以看出父节点的index为0，左子节点的为偶数，右子节点的为奇数。每个子节点又可以作为下面子节点的父节点。  
假设当前节点为`index`，父节点与当前节点的关系为：  
`parent(index) = index/2`  
(对于index为奇数也满足，index>0)，本来parent(index) = floor(index/2)，floor(x)返回的是<=x的最大整数，对于index/2，如果index为偶数，则floor返回的就是index/2；如果index为奇数，则index/2就是(index-1)/2+0.5，则floor返回的就是(index-1)/2，在c语言中index/2为整数，也就是去除小数的部分，于是在这里就满足了floor的定义。  
与其子节点的关系为：  
`left(index) = index*2`  
`right(index) = index*2+1`  

堆分为：最大堆和最小堆。先说最大堆。  
最大堆的父节点比子节点要大，子节点之间无特殊关系，只要求当前节点比它下面的子节点大。  
假设上面的数组为`A[10]`，则当前`index`节点与父节点的关系为：  
`A[parent(index)]>=A[index]`  
对于最小堆，同理是：  
`A[parent(index)]<=A[index]` 

当我们将一个数组变成最大堆时，只需满足上式即可。 
最大堆排序的示例如下：  
```C
int parent(int index)
{
	return (index/2);
}
// 对于头节点特殊处理
int left(int index)
{
	return (index * 2 + 1);
}

int right(int index)
{
	return (index * 2 + 2);
}
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

``` 
上面函数仅仅是对3个数进行了堆排序，如果已经是最大堆，则不会往下进行。  
单个的排序如图所示：(假设数组为:16 4 10 14 7 9 3 2 8 1)  
从第一个子节点开始。  
![(1)](C:\Users\Wee Yokay\Desktop\Mythbird\blog\heapsort.png)  
![(2)](C:\Users\Wee Yokay\Desktop\Mythbird\blog\heapsort1.png)  
![(3)](C:\Users\Wee Yokay\Desktop\Mythbird\blog\heapsort2.png)  

建立最大堆时从下往上挤，就像挤牙膏一样，每次将3个数中的最大值挤上去，这样挤到最高点时，数据中的最大值便升到了最高处，
也就是根节点。  

建立最大堆排序的示例如下：  
```C
void build_max_heap(int *num, int num_length)
{
	int count;	// count为每次要比较最后一个值得父节点
	for (count = (num_length-1)/2; count >=0; count--)
	{
		// 比较最后一个值所在的3人组
		max_heapify(num, count, num_length);
		//printf("%d\n", num[height]);
	}
}
```
建立最大堆后，每个3人组都是最大堆，也就是说每个3人组中父节点是最大值。  
这样一次取出最大值就可以排序，但是每次取出最大值后要再次进行最大堆化，使之始终遵守最大堆，即保持3人组是最大堆格式的。  
最大堆排序的示例如下：  
```C
void heap_sort(int *num, int num_length)
{
	int leaf;
	int heap_size;
	heap_size = num_length;
	build_max_heap(num, num_length);

	for (leaf = (num_length-1); leaf > 0; leaf--) {
		exchange_num(&num[0], &num[leaf]);	// 将最大值放在最后
		heap_size = heap_size - 1;	// 去除最大值后，对剩下的再次进行最大堆化
		max_heapify(num, 0, heap_size);
	}
}
```
这样就实现了一个简单的最大堆排序算法。  
其时间复杂度为O(nlgn)。  