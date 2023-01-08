# Leftist Tree

### Property I

> 對於有 $n$ 個節點的 *binary tree(leftist tree)*，恰有 $n+1$ 個 external node

設共有 $n$ 個節點，每一節點 (不會有葉，因為 *leftist tree* 的葉是 external node) 可以接兩個 child node，因此共可以接 $2n$ 個 node ($2n$ 條邊)。

> $2n = (n-1) + (n+1)$ 

把 $n$ 個 node 連接起來只需 $n-1$ 條邊 (tree 的定義)，因此剩下的全部邊都用來連接 external node，於是共 $n+1$ 個 external node。

### Property II

