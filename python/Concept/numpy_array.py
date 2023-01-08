# -*- coding: utf-8 -*-
"""
Created on Sat Dec  4 00:00:08 2021

@author: williamlin
"""

import numpy as np

# create a blank array with data type "integer"
arr = np.array([], dtype='i')
# to add a single element or a whole array
arr= np.append(arr, int(4))
print(arr[0])
arr = np.append(arr, [5, 6, 7, 8])
print(arr)

# 2D
arr2 = np.array([[1, 2, 4], [5, 6, 9]])
print(arr2[0, 2])