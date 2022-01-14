# -*- coding: utf-8 -*-
"""
Created on Mon Dec 20 12:57:34 2021

@author: williamlin

description:
    A new version for rectangular images.
        1. replace "tuple" with "list"
        2. use a different method to produce permutation matrices
    (compatible with square images)
"""

import numpy as np
from PIL import Image
import random as rand
import matplotlib.pyplot as plt

def encrypt(arr, PM):
    shape = arr.shape

    if(min(shape[0], shape[1]) <= 10):
        return
    
    if shape[0] <= shape[1]:
        PM.append(list(partial_encrypt(shape[0], arr[:, :shape[0], :])))
        encrypt(arr[:, shape[0]:, :], PM)
    else :
        PM.append(list(partial_encrypt(shape[1], arr[:shape[1], :, :])))
        encrypt(arr[shape[1]:, :, :], PM)
    return 
    
def partial_encrypt(N, arr):
    perm = np.empty(N*N, dtype='i')
    perm.fill(0)
    perm = perm.reshape(N, N)
    
    set_to_one = list() # 1s of a single permutation matrix
    fr = list()
    for i in range(N):
        fr.append(i)
    for i in range(N):
        r = rand.randint(0, N-i-1)
        set_to_one.append((fr[r]))
        perm[i, fr[r]] = 1
        del fr[r]
    
    
    for i in range(arr.shape[2]):
        arr[:N, :N, i] = perm @ arr[:N, :N, i]
    return set_to_one

def decrypt(arr, PM, at, Len):
    if at == Len:
        return
    size = len(PM[at]) # number of rows
    inv_mat = np.empty(size*size, dtype='i')
    inv_mat.fill(0)
    inv_mat = inv_mat.reshape(size, size)
    
    for j in range(size):
        inv_mat[j][PM[at][j]] = 1

    inv_mat = inv_mat.transpose() # P^T = P^(-1)
    
    for j in range(arr.shape[2]):
        arr[:size, :size, j] = inv_mat @ arr[:size, :size, j]
    
    shape = arr.shape
    if shape[0] <= shape[1]:
        decrypt(arr[:, shape[0]:, :], PM, at+1, Len)
    else:
        decrypt(arr[shape[1]:, :, :], PM, at+1, Len)
               
img = Image.open('./Images/cat.jpg')
arr = np.array(img)

# compressed permutation matrices (only record 1s)
# recorded for future decryption
PM = list() 

encrypt(arr, PM)
plt.subplot(1, 2, 1)
plt.imshow(arr)

decrypt(arr, PM, 0, len(PM))
plt.subplot(1, 2, 2)
plt.imshow(arr)


