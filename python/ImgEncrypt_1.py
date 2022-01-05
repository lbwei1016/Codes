# -*- coding: utf-8 -*-
"""
Created on Mon Dec  6 09:33:57 2021

@author: williamlin

description:
    This is the first attempt to encrypt an image through a permutation matrix, 
    and decrypt it through the inverse matrix.
    This image is a square. Rectangular images will be covered in the future.
"""

import numpy as np
from numpy.linalg import inv # inverse matrix
from PIL import Image
import random as rand
import matplotlib.pyplot as plt

img = Image.open('./Images/cat_rectangular.jpg')
arr = np.array(img)

print(arr.shape)
# alter transparency
# =============================================================================
# for idx, i in np.ndenumerate(arr):
#     if idx[2] == 3:
#         arr[idx] = i*0.5
# =============================================================================
#plt.imshow(arr)

# The image is 512*512 (square)
N = 732
set_to_1 = tuple()

permu = np.empty(N*N, dtype='i')
permu.fill(0)
permu = permu.reshape(N, N)
# generate a random permutation matrix
for i in range(N):
    while True:
        r = rand.randint(0, N-1)
        if set_to_1.count(r) == 0:
            permu[i, r] = 1
            #tmp = (r,)
            #set_to_1 += tmp
            set_to_1 += tuple([r])
            break
# separately permute R, G, B, and transparency
for i in range(3):
    # A @ B: '@' means matrix mult.
    arr[:, :, i] = permu @ arr[:, :, i] 

# store the encrypted image
img = Image.fromarray(arr)
img.save("enc.png")

# inverse of the permutation matrix
inv_permu = np.array(inv(permu), dtype='i')
plt.subplot(1, 2, 1) # plot two plots together (without overlapping)
plt.imshow(arr)
#plt.axis('off')
# invert the image back
for i in range(3):
    arr[:, :, i] = inv_permu @ arr[:, :, i]
plt.subplot(1, 2, 2)
plt.imshow(arr)
#plt.axis('off')



