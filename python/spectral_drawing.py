# -*- coding: utf-8 -*-
"""
Created on Fri Oct 28 00:10:10 2022

Use the spectral drawing method to draw the Buckyball in the three-dimensional space.

@author: 110550079 林伯蔚
"""
import numpy as np
import matplotlib.pyplot as plt

A5 = list()
vis = [0] * 5
G = np.array([0] * 3600).reshape(60, 60)

# find A5
def permute(d, per):
    if d == 5:
        cnt = 0
        for i, x in enumerate(per):
            cnt += sum(x > y for y in per[i:])
        if cnt % 2 == 0:
            A5.append(per.copy())
        return
    for i in range(5):
        if vis[i] == 0:
            vis[i] = 1
            per.append(i)
            permute(d+1, per)
            
            per.pop()
            vis[i] = 0

# three permutations    
def cayley(i):
    # (54321)
    cay1 = A5[i].copy()
    cay1.append((cay1[0]))
    cay1.remove(cay1[0])
    
    # (23)(45)
    cay2 = A5[i].copy()
    cay2[1], cay2[2] = cay2[2], cay2[1]
    cay2[3], cay2[4] = cay2[4], cay2[3]
    
    # (12345)
    cay3 = A5[i].copy()
    cay3.insert(0, cay3[4])
    cay3.pop()
    return [cay1, cay2, cay3]
        
def findEdge():
    for i in range(60):
        cay = cayley(i)
        for j in range(60):
            if A5[j] == cay[0] or A5[j] == cay[1] or A5[j] == cay[2] :
                G[i][j] = G[j][i] = 1

# return 3 needed eigenvectors
def eigen():
    L = np.diag(np.array([3] * 60))
    L = L - G
    
    eigval, eigvec = np.linalg.eig(L)
    
    eigval = list((i, val) for i, val in enumerate(eigval))
    eigval.sort(key=lambda tup: tup[1])
    # print(eigval)
    # print(L @ eigvec[:,1])
    # print(eigval[1][1] * eigvec[:,1])
    
    return [eigvec[:,eigval[1][0]], eigvec[:,eigval[2][0]], eigvec[:,eigval[3][0]]]

# plot
def plot3D():
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    
    pts = eigen()

    dots = list()
    for x, y, z in zip(pts[0], pts[1], pts[2]):
        ax.scatter(x.real, y.real, z.real, color='g')
        dots.append([x.real, y.real, z.real])
        print([x.real, y.real, z.real])
    
    for u in range(60):
        for v in range(60):
            if G[u][v] == 1:
                ax.plot([dots[u][0], dots[v][0]], [dots[u][1], dots[v][1]], [dots[u][2], dots[v][2]], color='b')
    plt.show()
            
permute(0, [])
findEdge()
plot3D()