from LiveRecogniser import RecogniseSpeech
from GoogleRecogniser import RecognizeSpeechGoogle
from WitRecogniser import RecognizeSpeechWit

# Live Speech Recognition
while True:
    text=RecogniseSpeech()
    if text=="stop yourself":
        print("--> "+text)
        break
    else:
        print("--> "+text)

# ============================================================
# Audio Block Recognition Using By GoogleRecogniser
# param1 = AudioFileName
# param2 = Number of seconds

# text=RecognizeSpeechGoogle("GSample.wav",10)
# Uncomment the above line to use
# ============================================================
# Audio Block Recognition Using By WitRecogniser
# param1 = AudioFileName
# param2 = Number of seconds

# text=RecognizeSpeechWit("WSample.wav",10)
# Uncomment the above line to use
# ============================================================