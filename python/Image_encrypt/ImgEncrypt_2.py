# -*- coding: utf-8 -*-
"""
Created on Mon Dec 20 12:57:34 2021

@author: williamlin

description:
    A version for rectangular images.
    (compatible with square images)
"""

import numpy as np
from PIL import Image
import random as rand
import matplotlib.pyplot as plt
import random as rand
from numpy.linalg import inv


def encrypt(arr):
    shape = arr.shape
    # compressed permutation matrices (only record 1s)
    # recorded for future decryption
    PM = tuple() 
    
    if(min(shape[0], shape[1]) <= 10):
        return PM
    
    if shape[0] <= shape[1]:
        PM += tuple((partial_encrypt(shape[0], arr[:, :shape[0], :]),))
        PM += encrypt(arr[:, shape[0]:, :])
    else :
        PM += tuple((partial_encrypt(shape[1], arr[:shape[1], :, :]),))
        PM += encrypt(arr[shape[1]:, :, :])
    return PM
    
def partial_encrypt(N, arr):
    perm = np.empty(N*N, dtype='i')
    perm.fill(0)
    perm = perm.reshape(N, N)
    
    set_to_one = tuple() # 1s of a single permutation matrix
    
    for i in range(N):
        while True:
            r = rand.randint(0, N-1)
            if set_to_one.count(r) == 0:
                perm[i, r] = 1
                set_to_one += tuple((r,))
                break;
    
    for i in range(arr.shape[2]):
        arr[:N, :N, i] = perm @ arr[:N, :N, i]
    return set_to_one

def decrypt(arr, pos_of_one, at, Len):
    if at == Len:
        return
    size = len(pos_of_one[at]) # number of rows
    inv_mat = np.empty(size*size, dtype='i')
    inv_mat.fill(0)
    inv_mat = inv_mat.reshape(size, size)
    
    for j in range(size):
        inv_mat[j][pos_of_one[at][j]] = 1

    inv_mat = inv_mat.transpose() # P^T = P^(-1)
    
    for j in range(arr.shape[2]):
        arr[:size, :size, j] = inv_mat @ arr[:size, :size, j]
    
    shape = arr.shape
    if shape[0] <= shape[1]:
        decrypt(arr[:, shape[0]:, :], pos_of_one, at+1, Len)
    else:
        decrypt(arr[shape[1]:, :, :], pos_of_one, at+1, Len)
                
        

img = Image.open('./Images/Cat_small.png')
arr = np.array(img)

# "pos_of_one" is equivalent to "set_to_one" in partial_encryption
pos_of_one = encrypt(arr)
plt.subplot(1, 2, 1)
plt.imshow(arr)

decrypt(arr, pos_of_one, 0, len(pos_of_one))
plt.subplot(1, 2, 2)
plt.imshow(arr)

