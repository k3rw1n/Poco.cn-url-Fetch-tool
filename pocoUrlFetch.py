# coding: utf-8
import re
import urllib

def getHtml(url):
    page = urllib.urlopen(url)
    html = page.read()
    return html

def getImg(html):
    re1='(http)'    # Word 1
    re2='(:)'   # Any Single Character 1
    re3='(\\/)' # Any Single Character 2
    re4='(\\/)' # Any Single Character 3
    re5='(image17)' # Alphanum 1
    re6='(-)'   # Any Single Character 4
    re7='(c)'   # Variable Name 1
    re8='(\\.)' # Any Single Character 5
    re9='(poco)'    # Word 2
    re10='(\\.)'    # Any Single Character 6
    re11='(cn)' # Word 3
    re12='(\\/)'    # Any Single Character 7
    re13='((?:[a-z][a-z]+))'    # Word 4
    re14='(\\/)'    # Any Single Character 8
    re15='((?:[a-z][a-z]+))'    # Word 5
    re16='(\\/)'    # Any Single Character 9
    re17='((?:(?:[1]{1}\\d{1}\\d{1}\\d{1})|(?:[2]{1}\\d{3}))(?:[0]?[1-9]|[1][012])(?:(?:[0-2]?\\d{1})|(?:[3][01]{1})))(?![\\d])'    # YYYYMMDD 1
    re18='(\\/)'    # Any Single Character 10
    re19='(\\d+)'   # Integer Number 1
    re20='(\\/)'    # Any Single Character 11
    re21='(\\d+)'   # Integer Number 2
    re22='(_)'  # Any Single Character 12
    re23='(\\d+)'   # Integer Number 3
    re24='(\\.)'    # Any Single Character 13
    re25='((?:[a-z][a-z]+))'    # Word 6
    re26='(\\?)'    # Any Single Character 14
    re27='(\\d+)'   # Integer Number 4
    re28='(x)'  # Any Single Character 15
    re29='(\\d+)'   # Integer Number 5
    re30='(_)'  # Any Single Character 16
    re31='(\\d+)'   # Integer Number 6

    rg = re.compile(re1+re2+re3+re4+re5+re6+re7+re8+re9+re10+re11+re12+re13+re14+re15+re16+re17+re18+re19+re20+re21+re22+re23+re24+re25+re26+re27+re28+re29+re30+re31,re.IGNORECASE|re.DOTALL)
    m = rg.findall(html)
    # print m
    x = 0
    imgList = []
    for imgurl in m:
        urltext=""
        for tui in imgurl:
            urltext += tui
        imgList.append(urltext)

    imgList=list(set(imgList))
    with open('url.txt','w') as uf:
        for i in imgList:
            uf.write(str(i))
            uf.write('\n')

if __name__ == '__main__':
    print u"请输入POCO网链接"
    url=raw_input("> ")
    html = getHtml(url)
    getImg(html)
