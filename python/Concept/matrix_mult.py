# -*- coding: utf-8 -*-
"""
Created on Sat Dec  4 23:29:54 2021

@author: williamlin
"""

import numpy as np

arr1 = np.array([[1, 2, 3], [4, 5, 6]])
# 用一維陣列的形式宣告再 reshape，比較方便
arr2 = np.array([-1, -2, -3]).reshape(3, 1)
# np.dot(A, B): matrix multiplication
print(arr1 @ arr2)
print(arr1.reshape((3, 2)))
