import requests
# from requests.models import Response
# from requests.sessions import _Data
json = {
    "location" : "108.98,34.25",
    "key" : "e4cf87b1febf4b33b7d614072ab0c370",
    "lang" : "zh",
    "unit" : "m",
}
# response = requests.get("https://api.qweather.com/v7/grid-weather/now", json=json, timeout=5)
response = requests.get("https://api.qweather.com/v7/grid-weather/now?location=108.98,34.25&key=e4cf87b1febf4b33b7d614072ab0c370&lang=zh&unit=m", timeout=5)
print(response.text)