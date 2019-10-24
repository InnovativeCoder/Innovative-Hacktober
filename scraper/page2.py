from tkinter import *
import webbrowser
from search import *

def fun1(querry):
	def get_entry():
		# print (ent.get())
		global r
		r = str(ent.get())
		root.destroy()
	root = Tk()
	large_font = ('Verdana',30)
	canvas = Canvas(root, width=1000, height=150)
	canvas.pack()
	widget = Label(canvas, text='	WEB CRAWLER', fg='black')
	widget.config(font=("Courier", 30))
	widget.pack()
	canvas.create_window(300, 30, window=widget)

	var = StringVar(root)
	ent = Entry(root,textvariable = var,font=large_font,width=32)
	canvas.create_window(430, 100, window=ent)
	btn1 = Button(root, text="SEARCH", command=get_entry,height=3,width=10)
	canvas.create_window(900, 100, window=btn1)

	result = search(querry)
	def callback(event):
	    webbrowser.open_new(event.widget.cget("text"))
	for i in range(len(result)):

		lbl = Label(root, text=(str(result[i])[2:-3]), fg="blue", cursor="hand2")
		lbl.pack(fill =X, padx=10,pady=10)	
		lbl.bind("<Button-1>", callback)

	root.mainloop()
	return r
