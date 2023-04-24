import requests
import json
from playsound import playsound


url = 'http://api.voicerss.org/'
api_key = '94b084f0dc914d38bb217b21b18796d6'

text = input('Please input a string: ')
speed = input('Speech rate[-10:10]: ')

params_dikt = {
    'key' : api_key, 
    'src' : text,
    'hl': 'en-us',
    'r' : speed,
}

r = requests.get(url, params = params_dikt)

with open('output.wav', 'wb') as fhand:
        fhand.write(r.content)

print('Playing...')
playsound('output.wav')
print('Done!')