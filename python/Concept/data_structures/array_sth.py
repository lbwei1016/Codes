# -*- coding: utf-8 -*-
"""
Created on Tue Dec  7 09:31:33 2021

@author: williamlin
"""

import numpy as np

arr = np.array([1, 2, 3, 4, 5, 6]).reshape(3, 2)
print(arr)

arr2 = np.empty(20, dtype='i')
arr2.fill(-1)
arr2 = arr2.reshape(5, 4)
print(arr2, arr2.shape)