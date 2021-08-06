# Performance: 
`gcc version 9.3.0 (Ubuntu 9.3.0-17ubuntu1~20.04)`

> **Test data**: *10 strings, length 9999*
### 1. No optimization 
- 282270: `vector, bucket` --`3.6`
- 160007: `array, bucket` --`2.1`
- 83662: `vector, counting` --`1.1`
- 74649: `array, counting` --`1`

- 151807: `array, built-in` --`2.0`
- 484416: `vector, built-in(pair)` --`6.05`
- 327430: `vector, built-in(struct)` --`4.4` 
### 2. `O2` optimization
- 69256: `vector, bucket` --`3.3` ↑
- 131664:` array, bucket` --`6.05` ↓
- 25831: `vector, counting` --`1.02` ↑
- 21567: `array, counting` --`1`

- 54302: `array, built-in sort` --`2.6` ↓
- 102514: `vector, built-in(pair)` --`4.9` ↑
- 107049: `vector, built-in(struct)` --`5.0` ↓

> (clock: data structure, algo --relative spent time)

# Observation:
1. Large scale of calling `memset` is costly 
2. Good-written `counting sort` is faster than `bucket sort` when implementing `radix sort`
3. `radix sort` method is `2` times faster than `built-in sort` method 
4. The influence of `O2` is siginificant on `vector`, but is not on `array`

# Conclusion:
## Use `counting sort` !!!
- ### `array` is good
- ### Since competitive programming uses `O2`, so `vector` is also safe to use.
- ### If a large portion of memory is certainly idle, use `vector` for not only <br> memory but for *time efficiency* as well !!!

