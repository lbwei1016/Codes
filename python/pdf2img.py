# -*- coding: utf-8 -*-
"""
Created on Wed Feb 23 10:49:33 2022

@author: williamlin
"""

from pdf2image import convert_from_path
img = convert_from_path("./exampdf.pdf", 100)

for i in len(img):
    img[i].save('page'+i+'.png')