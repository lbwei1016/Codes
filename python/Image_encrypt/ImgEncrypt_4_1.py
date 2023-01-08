import numpy as np
from PIL import Image
import matplotlib.pyplot as plt
from modular_inverse import modular_inv as mod_inv

MOD = 257
  
img = Image.open('./Images/cat_rectangular.png')
#img = Image.open('./Images/Cat_small.png')
arr = np.array(img)

size = arr.shape[0]
# linearly independent matrix
M = np.array([[0, 2, 4, 5, 9, 1, 7, 3], [11, 4, 2, 4, 3, 7, 9, 0]])
M = M.reshape(8, 2)

M = M.transpose() @ M


# encrypt
size = arr.shape
LEN = M.shape[0]
start_c, end_c, start_r, end_r = 0, LEN, 0, LEN
# convert first (use int64 instead of uint64)
arr = arr.astype('int64')
while end_c <= size[0]:
    start_r, end_r = 0, LEN
    while end_r <= size[1]:
        for i in range(3):
            arr[start_c:end_c, start_r:end_r, i] = arr[start_c:end_c, start_r:end_r, i] @ M
        start_r += LEN
        end_r += LEN
    start_c += LEN
    end_c += LEN
for i in range(size[0]):
    for j in range(size[1]):
        # only RGB, alpha neglected (hence .jpg is supported)
        for k in range(3):
            arr[i, j, k] %= MOD
            # if arr[i, j, k] == 0, this pixel should just stay 0, or it will corrupt after the following procedure
# =============================================================================
#             if arr[i, j, k] > 0:
#                 arr[i, j, k] -= 1
# =============================================================================
# convert back
arr = arr.astype('uint8')

plt.axis('off')
#plt.subplot(1, 2, 1)
plt.imshow(arr)

# det. should be an int.
DET = int(np.round(np.linalg.det(M)))
print("DET: ", DET)
# 防止和 257 撞到 (失真程度未知)
if DET % MOD == 0:
    DET = 1
# modular inverse
inv = mod_inv(DET, MOD, [0],[0])[1][0]
# to be positive
inv = (inv + MOD) % MOD
print("inv: ", inv)

INV_M = np.linalg.inv(M)
INV_M *= DET
for i in range(LEN):
    for j in range(LEN):
        INV_M[i, j] = int(np.round(INV_M[i, j]))
INV_M = INV_M.astype('int64')

# decrypt
start_c, end_c, start_r, end_r = 0, LEN, 0, LEN
arr = arr.astype('int64')
#arr[:, :, :3] *= inv
# =============================================================================
# for i in range(size[0]):
#     for j in range(size[1]):
#         for k in range(3):
#             arr[i, j, k] *= inv
# =============================================================================
# =============================================================================
# for i in range(size[0]):
#      for j in range(size[1]):
#          for k in range(3):
#              # add it back first
#              if arr[i, j, k] != 0:
#                 arr[i, j, k] += 1
# =============================================================================

while end_c <= size[0]:
    start_r, end_r = 0, LEN
    while end_r <= size[1]:
        for i in range(3):
            arr[start_c:end_c, start_r:end_r, i] = arr[start_c:end_c, start_r:end_r, i] @ INV_M
        start_r += LEN
        end_r += LEN
    start_c += LEN
    end_c += LEN
arr[:, :, :3] *= inv
arr[:, :, :3] %= MOD
# =============================================================================
# for i in range(size[0]):
#     for j in range(size[1]):
#         for k in range(3):
#             #arr[i, j, k] *= inv
#             arr[i, j, k] %= MOD
# =============================================================================

arr = arr.astype('uint8')

#plt.subplot(1, 2, 2)
#plt.imshow(arr)

