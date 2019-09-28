# -*- coding: utf-8 -*-
# @Author: XOXO
# @Date:   2019-01-28 19:18:38
# @Last Modified by:   XOXO
# @Last Modified time: 2019-02-03 21:16:38
import requests
from bs4 import BeautifulSoup
import os
import re
headers = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36','Host':'www.qk6.org',}
Path = '/storage/emulated/0/脚本/'
i = 1
for n in list(range(1,2)):
    link = 'https://www.qk6.org/shuku/1_0_0_1_0_0_0_0_'
	print('第' + str(n) + '页:')
	Link = link + str(n) + '.html'
	resposen = requests.get(Link,headers=headers)
	# resposen.encoding = 'gbk'
	# resposen.text 转换为 树形字典
	Soup = BeautifulSoup(resposen.text,'lxml')
	#更进html格式或者补全html代码
	# Soup.prettify();
	for title in Soup.select(".storelistbt3b  .ts_font01"):
		# print(title.string)
		name = title.string
		# print(title.get('href'))
	for url in Soup.select(" .storelistbt3a"):
		# url1 = url.get('href'
		url1 = str(url.a)
		url1 = re.findall('ht.*txt.html',url1)
		link_1 = ''.join(url1)
		if link_1 == '':
			continue
		else:
			r = requests.get(link_1,headers=headers)
			Soup = BeautifulSoup(r.text,'lxml')
			name = str(Soup.head.title.string)
			value = len(name)
			name = name[:((value-6)//2)]
			html = str(Soup.select('#TxtdownTop'))
			Doadlown = re.findall('https://down.qk6.org/.*.txt',html)
			Doadlown = ''.join(Doadlown)
			Doadlown_Date = requests.get(Doadlown,headers=headers).content
			with open(Path+name+'.txt',"wb") as f:
				f.write(Doadlown_Date)
				print('第'+str(i)+"本")
				i += 1
			
			
