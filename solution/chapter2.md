《算法导论》练习题
---

#### 2.1-1
A: Use INSERTION-SORT on array A = {31,41,59,26,41,58}.  
Ok, let's do it.  
(1) 31 < 41 < 59. So don't touch them.  
(2) 59 > 26. Then exchange them.We get "31 41 26 59".Like up,41 > 26,also exchange,
we get "31 26 41 59".Go on, "26 31 41 59"  
(3) 59 > 58.So "58 59".At last,we get the result "26 31 41 58 58"  
From it, we know "INSERTION-SORT" is put the bigger number left-behind the little.
As in (1), no one need exchange.So do nothing.In (2), we find the bigger one,and then
we need do something.We insert the little one-'26' behind '59'.And so on.At last we get
a new array in sort.  

#### 2.1-2
A:INSERTION-SORT in non-increasing.  
Just exchange when found a big number.  
'Presudocode'  
```
for j = 2 to A.length
    key = A[j]
    i = j - 1
    while i > 0 and A[i] < key
        A[i + 1] = A[i]
        i = i - 1
    A[i + 1] = key
```

#### 2.1-3
A:find 'v' in array A = {...}  
'Presudocode'  
```
while i = 1 and i <= A.length
    if A[i] = v
        return i
    else
        i = i + 1
if i = A.length
    return nil
```

#### 2.1-4
A:binary add and binary store  
Assume two 7-bit binary integers '1011001' '1100001'.
Sum is '10111010'.  
'Presudocode'  
```
for i = 1 to n
    if A[i] + B[i] + C[i] = 0
        C[i] = 0
    if A[i] + B[i] + C[i] = 1
        C[i] = 1
    if A[i] + B[i] + C[i] = 2
        C[i] = 0
        C[i+1] = 1
    if A[i] + B[i] + C[i] = 3
        C[i] = 1
        C[i+1] = 1
```
  
