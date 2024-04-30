# `mystery` function

'mystery' recursively searches through the linked list, and whenever it finds a node with the value `n`, it modifies the list by removing that node and effectively linking its predecessor to whatever the recursive call returns. This continues until the end of the list is reached.

Given the linked list:

```cpp
10 -> 10 -> 20 -> 20 -> 30 -> 10 -> NULL
```

and the function call `mystery(top, 10)`, let's trace what happens:

1. The function starts at the first node (value 10). Since `top->data` is 10, it matches `n`, so it calls `mystery` on the rest of the list minus the first node.
2. The function now considers the second node (value 10). Again, since `top->data` is 10, it matches `n`, so it calls `mystery` on the rest of the list starting from the third node.
3. The function now considers the third node (value 20). Since `top->data` is not 10, it calls `mystery` on the next node.
4. The same happens with the fourth node (value 20).
5. The fifth node (value 30) also doesn't match `n`, so `mystery` is called on the sixth node.
6. The sixth node (value 10) matches `n`, so `mystery` is called on the rest of the list, which is `NULL` at this point.

**The function effectively removes all nodes with the value 10 from the list.**

The final state of the linked list, after all recursive calls return, will be:

```cpp
20 -> 20 -> 30 -> NULL
```

Thus, the linked list returned by the call `mystery(top, 10)` is as drawn above.
