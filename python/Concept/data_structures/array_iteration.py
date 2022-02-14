# -*- coding: utf-8 -*-
"""
Created on Mon Dec  6 09:26:57 2021

@author: williamlin
"""

import numpy as np
arr = np.array([[1, 2, 3], [4, 5, 6]])

# iteration
for i in np.nditer(arr):
    print(i)
# iteration with idices
for idx, i in np.ndenumerate(arr):
    print(idx, i)
    # print(type(idx)) <class 'tuple'>
# array slicing: [start:end:step]
for i in np.nditer(arr[:, ::2]):
    print(i)