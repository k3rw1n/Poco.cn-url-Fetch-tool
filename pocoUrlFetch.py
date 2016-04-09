# coding: utf-8
import re
import urllib
import threading


def getHtml(url):
    page = urllib.urlopen(url)
    html = page.read()
    return html
    # f=open('html.txt','r')
    # return f.read()

def saveImg(urlList):
    x = 0
    for imgurl in urlList:
        urllib.urlretrieve(imgurl,'%s.jpg' % x)
        x = x + 1
    print "OK"

def getImg(html):
    
    rg=re.compile(r'(?<=data_org_bimg\s=")http:\/\/image17-c.poco.cn\/mypoco\/myphoto\/\d{8}\/\d{2}\/\d+.jpg\?\d+x\d+_\d+')
    m = rg.findall(html)
    
    print m
    # with open('url.txt', 'w') as uf:
    #     for i in imgList:
    #         uf.write(str(i))
    #         uf.write('\n')
    x=0
    threads=[]
    for imgurl in m:
        x = x + 1
        t=threading.Thread(target=urllib.urlretrieve,args=(imgurl,'%s.jpg' % x))
        # urllib.urlretrieve(imgurl,'%s.jpg' % x)
        t.start()
        threads.append(t)
        
    print "OK"

if __name__ == '__main__':
    # print u"请输入POCO网链接"
    # url=raw_input("> ")
    # url = 'http://photo.poco.cn/lastphoto-htx-id-5049051-p-0.xhtml'
    html = getHtml('http://photo.poco.cn/lastphoto-htx-id-5073227-p-0.xhtml')
    getImg(html)
