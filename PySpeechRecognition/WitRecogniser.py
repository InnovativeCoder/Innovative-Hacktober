import requests
import json
from Recorder import read_audio,record_audio

# Wit speech API endpoint
API_ENDPOINT = 'https://api.wit.ai/speech'

# Wit.ai api access token
wit_access_token = 'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX'
# Create your own access token on wit.ai

def RecognizeSpeechWit(AUDIO_FILENAME, num_seconds=5):
    # record audio of specified length in specified audio file
    record_audio(num_seconds, AUDIO_FILENAME)

    # reading audio
    audio = read_audio(AUDIO_FILENAME)

    # defining headers for HTTP request
    headers = {'authorization': 'Bearer ' + wit_access_token,
               'Content-Type': 'audio/wav'}

    # making an HTTP post request
    resp = requests.post(API_ENDPOINT, headers=headers,
                         data=audio)

    # converting response content to JSON format
    data = json.loads(resp.content)

    # get text from data
    text = data['_text']

    # return the text
    return text