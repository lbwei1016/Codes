# Interval Heap

> Left bound: min heap
>
> Right bound: max heap

## Insert

* Insert like an ordinary heap (suppose "a" is to be inserted)
* 三種情形
  1. a < "left bound" of the parent of the last node (heap 是 complete binary tree)
     * insert like "min heap"
  2. a > "right bound"
     * insert like "max heap"
  3. else