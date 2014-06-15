[TOC]

归并排序(分治法)
---
###基本概念
divide and conquer，从字面上讲叫"分而治之"，即拆分再解决。从哲学上说就是“大事化小，小事化了”，也就是我们平时说的复杂问题简单化，或者将问题分成无数个小问题，逐一解决。这个方法比较符合中国的传统方法，往往在项目实施过程中用到的最多。

**分（divide）**  

	将问题分成无数个子问题，但子问题必须与主问题具有一致性。

**治（conquer）**  

	逐一求解子问题，通过递推分解子问题并求解。

**合（combinne）**  

	将所有子问题统一归纳，得到最终解。  

###测试实例
算法导论以归并排序（merge sort）为例，对n个元素的数组进行排序。  
方法：  
（1）将数组分成含n/2个元素的2个数组  
（2）对2个数组进行递推归并排序  
（3）将排序要的数组合并  

以书中数组为例：  

|0  |1  |2  |3  |4  |5  |6  |7  |
|---|---|---|---|---|---|---|---|
|5  |2  |4  |7  |1  |3  |2  |6  |

（1）首先分成2部分  

|0  |1  |2  |3  | |---| |0  |1  |2  |3  |
|---|---|---|---| |---| |---|---|---|---|
|5  |2  |4  |7  | |---| |1  |3  |2  |6  |

（2）再将2部分再次分解  

|0  |1  |   |---|   |0  |1  |   |------|    |0  |1  |   |---|   |0  |1  |
|---|---|   |---|   |---|---|   |------|    |---|---|   |---|   |---|---|
|5  |2  |   |---|   |4  |7  |   |------|    |1  |3  |   |---|   |2  |6  |

（3）最后对每组进行比较排序  

|0  |1  |   |---|   |0  |1  |   |------|    |0  |1  |   |---|   |0  |1  |
|---|---|   |---|   |---|---|   |------|    |---|---|   |---|   |---|---|
|2  |5  |   |---|   |4  |7  |   |------|    |1  |3  |   |---|   |2  |6  |

|------>|
|------>|
|------>|

|0  |1  |2  |3  | |---| |0  |1  |2  |3  |
|---|---|---|---| |---| |---|---|---|---|
|2  |4  |5  |7  | |---| |1  |2  |3  |6  |

|------>|
|------>|
|------>|

|0  |1  |2  |3  |4  |5  |6  |7  |
|---|---|---|---|---|---|---|---|
|1  |2  |2  |3  |4  |5  |6  |7  |

每次比较时都将小数调到前面，大数换到后面。  

测试用例:
```C
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
// 归并排序函数
void merge_sort(int A[], int p, int r)
{
    int q;
    if (p < r)  //当第一个数与最后一个数相同时停止
    {
        q = (p + r) / 2;    //不停的分拆
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);  //递推归并排序
        merge(A, p, q, r);  //每次递推时排序
    }
}
void main(void)
{
    int i;
    int number[] = {5, 2, 4, 7, 1, 2, 3, 6, 9};
    merge_sort(number, 0, 7);
    for (i = 0; i < 9; i++)
        printf("%d ", number[i]);
}

```
`gcc -o merge_sort merge_sort.c`  
结果为：1 2 2 3 4 5 6 7 9

###复杂度分析
二分归并排序的时间复杂度为：  
\[T(n) = 2T(n/2) + \Theta (n)\]  
根据主定理\[T(n) = \Theta (n\log n)\!]，其中\[\log n = {\log _2}n\!]  

因为每次都是分成2部分，假设分了\[x\!]次后只剩1个，便无需再分，每次分拆时有\[{{\rm{2}}^x}\!]部分。则有 
\[\frac{n}{{{{\rm{2}}^x}}} = 1\]  
求解得:  
\[x = \log n\]  
即分拆\[\log n\!]次后结束，由于每次都比较相同数目的元素，且总大小为\[n\!]，则总的比较次数为每次分拆比较的次数加上第一次没分拆时比较的次数，因为最终都要归并到完整不分拆的时刻。所以总的比较次数为：  
\[n\log n\]  
假设每次比较耗时\[c\!]个单位时间，则总的耗时为：  
\[cn\log n + cn\]  
这样时间复杂度就是：  
\[\Theta (n\log n)\]  

主定理(master theorem)：[wiki][1]  
\[T(n) = aT(\frac{n}{b}) + f(n)\!]  \[(a \ge 1,b > 1)\]    
其中\[n\]表示问题的规模，相当于要求解的数据数量。\[a\!]为递推的子问题数量，\[\frac{n}{b}\!]为每个子问题的规模，因为分拆成的子问题有\[\frac{n}{b}\!]个数据。\[f(n)\!]为递推之外的计算量，比如最后一次后者第一次的常量值。  

（1） 若存在常数\[\varepsilon  > 0\!]，使得\[f(n) = O({n^{{{\log }_b}a - \varepsilon }})\!]，则  
\[T(n) = \Theta ({n^{{{\log }_b}a}})\]  
当\[a{\rm{ = }}b\!]时，\[f(n) = O({n^{{\rm{1}} - \varepsilon }})\!]，若\[f(n) = \Theta (1)\!]，则\[\varepsilon  = 1\!]。\[f(n) = \Theta (1)\!]满足\[O({n^{{\rm{1}} - 1}})\]。  

（2）若存在常数\[k \ge 0\!]，使得\[f(n) = \Theta ({n^{{{\log }_b}a}}{\log ^k}n)\!]，则  
\[T(n) = \Theta ({n^{{{\log }_b}a}}{\log ^{k + 1}}n)\]  
特别是当\[k = 0\!]时，有\[f(n) = \Theta ({n^{{{\log }_b}a}})\!]，则  
\[T(n) = \Theta ({n^{{{\log }_b}a}}{\mathop{\rm logn}\nolimits} )\]  

（3）若存在常数\[\varepsilon  > 0\!]，使得\[f(n) = \Omega ({n^{{{\log }_b}a + \varepsilon }})\!]，并且存在\[af(n/b) \le cf(n)\!]，对于任意的\[c < 1\!]多项式成立，当然非负。则有  
\[T(n) = \Theta (f(n))\]  

常见的只有1和2，并且2中\[k = 0\!]时最常见。根据主定理，当得到时间复杂度的推导公式时即可求出结果。

[1]:http://zh.wikipedia.org/wiki/%E4%B8%BB%E5%AE%9A%E7%90%86