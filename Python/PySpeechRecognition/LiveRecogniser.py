import speech_recognition as sr

def RecogniseSpeech():
    r = sr.Recognizer()
    # We can change the input microphone index to receive audio from different mics
    # Use print(sr.Microphone.list_microphone_names()) to list different microphones connected to system
    mic = sr.Microphone(device_index=0)
    with mic as source:
        print("Listening...")
        r.adjust_for_ambient_noise(source)
        audio = r.listen(source)
    print("Recognising...")
    try:
        text=r.recognize_google(audio)
        return text
    except:
        return ""