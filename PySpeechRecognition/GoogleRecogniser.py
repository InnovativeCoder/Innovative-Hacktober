import speech_recognition as sr
from Recorder import record_audio

def RecognizeSpeechGoogle(AUDIO_FILENAME, num_seconds=5):
    r = sr.Recognizer()
    record_audio(num_seconds,AUDIO_FILENAME)
    audio_file = sr.AudioFile(AUDIO_FILENAME)
    with audio_file as source:
        r.adjust_for_ambient_noise(source)
        audio=r.record(source)
    try:
        text=r.recognize_google(audio)
        return text
    except:
        return ""