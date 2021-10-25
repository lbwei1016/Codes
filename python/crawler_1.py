import requests
from bs4 import BeautifulSoup

req = requests.get(
    "https://www.google.com.tw/?hl=zh_TW"
    )
#print(req.cookies)
soup = BeautifulSoup(req.text, "html.parser")
# print(soup.prettify)

title_tag = soup.title
print(title_tag, title_tag.string) # fetch the "title tag" and its content respectively
all_link = soup.find_all('a', limit=3) # "limit": the maximum number of results
for tags in all_link:
    print(tags.string) # 印出 tags 的文字內容
    print(tags.get('href')) # 印出標籤的 "href" 屬性內容
tag_div = soup.find('div') # fetch the first "div" tag
print(tag_div.get('id'))