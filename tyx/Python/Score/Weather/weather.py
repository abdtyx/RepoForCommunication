import requests
# import urllib.request
url = "https://api.seniverse.com/v3/pro/weather/grid/now.json?key=SXODOIvfMy3B7XlOP&location=39.865927:116.359805"
response = requests.get(url)
# response = urllib.request.urlopen(url=url)
# print(response.read().decode('utf-8'))
print(response.text)