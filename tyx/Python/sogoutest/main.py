import requests
url = "https://www.douban.com"
response = requests.get(url=url)
try:
    print(response.text)
except Exception as result:
    print(result)