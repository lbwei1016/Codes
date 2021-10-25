# -*- coding: utf-8 -*-
"""
Created on Tue Sep  7 11:55:40 2021

@author: williamlin
"""
import requests
from bs4 import BeautifulSoup

my_param = {'q': '貓咪'} # 要 GET 的參數 (?q=貓咪)
req = requests.get("https://www.google.com/search", params=(my_param))
# 成功 GET 才繼續 parse
if req.status_code == requests.codes.ok:
    print(req.status_code)
    
    soup = BeautifulSoup(req.text, 'html.parser')
    
    search = soup.find_all('h3') # class 是 python 的保留字，所以用 "class_" 取代
    for tag in search:
        print(tag.string)