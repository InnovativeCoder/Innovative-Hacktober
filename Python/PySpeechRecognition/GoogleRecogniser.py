import speech_recognition as sr
from Recorder import record_audio

def RecognizeSpeechGoogle(AUDIO_FILENAME, num_seconds=5):
    recogniser = sr.Recognizer()
    record_audio(num_seconds,AUDIO_FILENAME)
    audio_file = sr.AudioFile(AUDIO_FILENAME)
    with audio_file as source:
        recogniser.adjust_for_ambient_noise(source)
        audio = recogniser.record(source)
    try:
        text = recogniser.recognize_google(audio)
        return text
    except:
        return ""
