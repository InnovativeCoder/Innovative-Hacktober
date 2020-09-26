import subprocess
subprocess.check_call(["python", '-m', 'pip', 'install', 'playsound']) # install pkg
import time
import playsound
import tkinter as tk


window = tk.Tk()
window.title('Surprise!')
tk.Label(window, text='Happy Birthday!', font=("Helvetica", 20)).pack()


window.mainloop()
playsound.playsound("song.mp3", True)
