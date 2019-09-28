import os
import requests
 
headers = {'User-Agent':'Mozilla/5.0 3578.98 Safari/537.36'}
page = 0
nu = 1
path = '/storage/emulated/0/1/sina/'
page_max = int(input('请输入最大页数:'))
while (page < page_max):
    link = 'http://tu.mhwang.cc/xeall/lifanacgup/papapa/20161125/3/'
    na = "%03d" %page
    link = link + str(na) + '.jpg'
    name = path + str(nu) + '.jpg'
    print(link)
    r = requests.get(link,headers=headers).content
    with open(name,'wb') as f:
        f.write(r)
    page += 1
    nu += 1
    print('下载成功:'+str(page)+'.jpg')

