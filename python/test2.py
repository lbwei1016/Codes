# -*- coding: utf-8 -*-
"""
Created on Tue Dec 28 21:53:57 2021

@author: williamlin
"""

from scipy.linalg import null_space
import numpy as np

A = np.array([[7, 1], [1, 1], [8, 5], [45, 6]])
print(null_space(A))
print(null_space(A).any())