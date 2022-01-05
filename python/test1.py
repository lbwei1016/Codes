# -*- coding: utf-8 -*-
"""
Created on Tue Dec 28 19:51:12 2021

@author: williamlin
"""

import numpy as np

key = [1, 2, 5, 7, 8, 9]
LEN = 5
encrypt_matrix = np.array(key[0:LEN])
print(encrypt_matrix)
encrypt_matrix = encrypt_matrix.reshape(LEN, 1)
print('en', encrypt_matrix)

a_col = np.array(key[0:5])
#print(a_col)
tmp_mat = np.c_[encrypt_matrix, a_col]
tmp_mat = np.c_[tmp_mat, a_col]
print(tmp_mat)