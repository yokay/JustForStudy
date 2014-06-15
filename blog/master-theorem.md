[TOC]

主定理
---

二分归并排序的时间复杂度为：  
$latex \displaystyle T(n)=2T(n/2)+\Theta (n)$ 
根据主定理$latex \displaystyle T(n)=\Theta (n\log n)$，其中$latex \displaystyle \log n={{\log }_{2}}n$  

因为每次都是分成2部分，假设分了$latex \displaystyle x$次后只剩1个，便无需再分，每次分拆时有$latex \displaystyle {{\text{2}}^{x}}$部分。则有 
$latex \displaystyle \frac{n}{{{\text{2}}^{x}}}=1$  
求解得:  
$latex \displaystyle x=\log n$    
即分拆$latex \displaystyle \log n$次后结束，由于每次都比较相同数目的元素，且总大小为$latex \displaystyle n$，则总的比较次数为每次分拆比较的次数加上第一次没分拆时比较的次数，因为最终都要归并到完整不分拆的时刻。所以总的比较次数为：   
$latex \displaystyle n\log n$ 
假设每次比较耗时$latex \displaystyle c$个单位时间，则总的耗时为：  
$latex \displaystyle cn\log n+cn$    
这样时间复杂度就是：  
$latex \displaystyle \Theta (n\log n)$  

主定理(master theorem)：[wiki][1]  
$latex \displaystyle T(n)=aT(\frac{n}{b})+f(n)$  $latex \displaystyle (a\ge 1,b>1)$    
其中$latex \displaystyle n$表示问题的规模，相当于要求解的数据数量。$latex \displaystyle a$为递推的子问题数量，$latex \displaystyle \frac{n}{b}$为每个子问题的规模，因为分拆成的子问题有$latex \displaystyle \frac{n}{b}$个数据。$latex \displaystyle f(n)$为递推之外的计算量，比如最后一次后者第一次的常量值。  

（1） 若存在常数$latex \displaystyle \varepsilon >0$，使得$latex \displaystyle f(n)=O({{n}^{{{\log }_{b}}a-\varepsilon }})$，则  
$latex \displaystyle T(n)=\Theta ({{n}^{{{\log }_{b}}a}})$  
当$latex \displaystyle a\text{=}b$时，$latex \displaystyle f(n)=O({{n}^{\text{1}-\varepsilon }})$，若$latex \displaystyle f(n)=\Theta (1)$，则$latex \displaystyle \varepsilon =1>0$。$latex \displaystyle f(n)=\Theta (1)$满足$latex \displaystyle O({{n}^{\text{1}-1}})$。  

（2）若存在常数$latex \displaystyle k\ge 0$，使得$latex \displaystyle f(n)=\Theta ({{n}^{{{\log }_{b}}a}}{{\log }^{k}}n)$，则  
$latex \displaystyle T(n)=\Theta ({{n}^{{{\log }_{b}}a}}{{\log }^{k+1}}n)$  
特别是当$latex \displaystyle k=0$时，有$latex \displaystyle f(n)=\Theta ({{n}^{{{\log }_{b}}a}})$，则  
$latex \displaystyle T(n)=\Theta ({{n}^{{{\log }_{b}}a}}\text{logn})$  

（3）若存在常数$latex \displaystyle \varepsilon >0$，使得$latex \displaystyle f(n)=\Omega ({{n}^{{{\log }_{b}}a+\varepsilon }})$，并且存在$latex \displaystyle af(n/b)\le cf(n)$，对于任意的$latex \displaystyle c<1$多项式成立，当然非负。则有  
$latex \displaystyle T(n)=\Theta (f(n))$  

常见的只有1和2，并且2中$latex \displaystyle k=0$时最常见。根据主定理，当得到时间复杂度的推导公式时即可求出结果。

[1]:http://zh.wikipedia.org/wiki/%E4%B8%BB%E5%AE%9A%E7%90%86