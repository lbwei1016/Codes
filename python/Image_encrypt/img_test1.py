import numpy as np
# import scipy as sp
import matplotlib.pyplot as plt
from PIL import Image
import random as rand

img = np.array((Image.open("./Images/Cat_small.png")))
print(img.shape)

# channel: represent RGB (hence "ch" is from 0 to 2)
'''
rows, cols, ch = img.shape
for i in range(rows):
    for j in range(cols):
        if((img[i, j] <= np.array([128, 128, 128])).all()):
            img[i, j] = [0, 0, 0]
        else:
            img[i, j] = [255, 255, 255]
'''
# error
'''
plt.figure('cat')
#plt.axis('off')
plt.show()
'''