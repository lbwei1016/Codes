# -*- coding: utf-8 -*-
"""
Created on Wed Dec 29 13:02:42 2021

@author: williamlin
"""

def modular_inv(a, b, x, y):
    d = a
    if b != 0:
        d = modular_inv(b, a%b, y, x)[0]
        y[0] -= (a//b) * x[0]
    else:
        x[0], y[0] = 1, 0
    return [d, x]

# =============================================================================
# a = 515
# p = 257
# r = modular_inv(a, p, [0], [0])
# print(r)
# print((r[1][0]+p)%p)
# =============================================================================
