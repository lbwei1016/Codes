import numpy as np
from PIL import Image
import random as rand
import matplotlib.pyplot as plt
from modular_inverse import modular_inv as mod_inv
import math

MOD = 257  
cnt = 0           
  
img = Image.open('./Images/fb.png')
#img = Image.open('./Images/Cat_small.png')
arr = np.array(img)
#print("before:\n", arr)
#print("before\n", arr[200, 200, :])

size = arr.shape[0]
M = np.array([[0, 2, 4, 5, 9, 1, 7, 3], [11, 4, 2, 4, 3, 7, 9, 0]])
M = M.reshape(8, 2)

M = M.transpose() @ M
print("M:\n", M)


# encrypt
size = arr.shape
LEN = M.shape[0]
start_c, end_c, start_r, end_r = 0, LEN, 0, LEN
#print("LEN:", LEN)
arr = arr.astype('int64')
while end_c <= size[0]:
    start_r, end_r = 0, LEN
    while end_r <= size[1]:
        for i in range(3):
            # print(image[start_c:end_c, start_r:end_r, i], matrix)
            #print("val before: ", arr[start_c:end_c, start_r:end_r, i])
            arr[start_c:end_c, start_r:end_r, i] = arr[start_c:end_c, start_r:end_r, i] @ M
            #print("val after: ", arr[start_c:end_c, start_r:end_r, i])
        start_r += LEN
        end_r += LEN
    start_c += LEN
    end_c += LEN
#print("middle\n", arr)
#print("middle\n", arr[200, 200, :])
for i in range(size[0]):
    for j in range(size[1]):
        # only RGB, alpha is used to indicate 
        for k in range(3):
            arr[i, j, k] %= MOD
# =============================================================================
#             if arr[i, j, k] > 0:
#                 arr[i, j, k] -= 1
#             elif arr[i, j, k] > 1:
#                 arr[i, j, 3] = 1
# =============================================================================
#print("after\n", arr[200, 200, :])
arr = arr.astype('uint8')
#print(arr)

plt.subplot(1, 2, 1)
plt.imshow(arr)

DET = int(np.round(np.linalg.det(M)))
inv = mod_inv(DET, MOD, [0],[0])[1][0]
inv = (inv + MOD) % MOD

INV_M = np.linalg.inv(M)
print("INV_M before:\n", INV_M, '\n')
print("det(M):", DET)
print("modular inv: ", inv)
INV_M *= DET
for i in range(LEN):
    for j in range(LEN):
        INV_M[i, j] = int(np.round(INV_M[i, j]))
INV_M = INV_M.astype('int64')
# =============================================================================
# for i in range(LEN):
#     for j in range(LEN):
#         INV_M[i, j] *= DET
# =============================================================================
print("INV_M after:\n", INV_M, '\n')
#print("after\n", arr)
start_c, end_c, start_r, end_r = 0, LEN, 0, LEN
arr = arr.astype('int64')

for i in range(size[0]):
     for j in range(size[1]):
         for k in range(3):
             if arr[i, j, 3] != 1:
                 if arr[i, j, k] != 0:
                     arr[i, j, k] += 1
             elif arr[i, j, 3] == 1:
                arr[i, j, 3] = 255
#arr += 1

while end_c <= size[0]:
    start_r, end_r = 0, LEN
    while end_r <= size[1]:
        for i in range(3):
            # print(image[start_c:end_c, start_r:end_r, i], matrix)
            #print("val before: ", arr[start_c:end_c, start_r:end_r, i])
            arr[start_c:end_c, start_r:end_r, i] = arr[start_c:end_c, start_r:end_r, i] @ INV_M
            #print("val after: ", arr[start_c:end_c, start_r:end_r, i])
        start_r += LEN
        end_r += LEN
    start_c += LEN
    end_c += LEN

for i in range(size[0]):
    for j in range(size[1]):
        for k in range(3):
            arr[i, j, k] *= inv
            arr[i, j, k] %= MOD
            #arr[i, j, k] += M%MOD - 1
            #arr[i, j, k] %= MOD
            #if arr[i, j, k] == 1:
            #if rand.randint(0, 100) % 2:
                #arr[i, j, k] -= 1
arr = arr.astype('uint8')

#print("decrypted\n", arr[200, 200, :])
#print("M:\n", M)
#print("M%MOD:\n", M%MOD)
plt.subplot(1, 2, 2)
plt.imshow(arr)

