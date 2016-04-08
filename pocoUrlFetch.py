# coding: utf-8
import re
import urllib
from webclient import WebBrowser

def getHtml(url):
    # page = urllib.urlopen(url)
    # html = page.read()
    # return html
    browser = WebBrowser()
    html = browser._request(url)
    print type(html)
    return html

def saveImg(urlList):
    x = 0
    for imgurl in urlList:
        urllib.urlretrieve(imgurl,'%s.jpg' % x)
        x = x + 1
    print "OK"

def getImg(html):
    
    rg=re.compile(r'(?<=data_org_bimg=")http:\/\/image17-c.poco.cn\/mypoco\/myphoto\/\d{8}\/\d{2}\/\d+.jpg\?\d+x\d+_\d+',re.IGNORECASE |re.DOTALL)
    m = rg.findall(html)
    # print m
    
    print m
    with open('url.txt', 'w') as uf:
        for i in imgList:
            uf.write(str(i))
            uf.write('\n')

if __name__ == '__main__':
    # print u"请输入POCO网链接"
    # url=raw_input("> ")
    # url = 'http://photo.poco.cn/lastphoto-htx-id-5049051-p-0.xhtml'
    html = getHtml('http://photo.poco.cn/lastphoto-htx-id-5049051-p-0.xhtml')
    getImg(html)
