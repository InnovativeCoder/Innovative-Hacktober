import json
import time
import requests
from playsound import playsound

r = requests.get('https://api.coinmarketcap.com/v2/ticker/1/')
jsonObject = r.json()
btcPrice = jsonObject["data"]["quotes"]["USD"]["price"]

while btcPrice >= 10000:
    print('1 BTC is '+ str(btcPrice))
    playsound('alert.wav')
    print('Checking again in 15 minutes..')
    time.sleep(900)
