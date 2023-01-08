# Indexed BST

> 為了在 $O(log\ n)$ 內找到 $i^{th}$ 元素

### requirements

* $x.leftSize$: 紀錄左子樹大小
* *inorder traversal* of the BST: 對於 BST 而言是一 sorted list for keys

### algorithm

> 設要查找第 $id$ 個元素

```cpp
int find_position(root x, int id) {
    if (id == x.leftSize) 
        return x.val;
    else if (id < x.leftSize) 
        return find_position(x.lch, id);
    else 
        return find_position(x.rch, id-x.leftSize-1);
}
```
> ref: https://www.quora.com/What-is-an-indexed-binary-search-tree