from tkinter import *

def fun():
	def get_entry():
		global k
		global v	
		k = str(ent.get())
		v = 1
		root.destroy()

	def getval():
		global k
		global v	
		k = str(ent.get())
		v = 2
		root.destroy()



	root = Tk()
	large_font = ('Verdana',30)
	canvas = Canvas(root, width=600, height=600)
	canvas.pack()

	widget = Label(canvas, text='WEB CRAWLER', fg='black')
	widget.config(font=("Courier", 40))
	widget.pack()
	canvas.create_window(300, 230, window=widget)
	var = StringVar(root)
	ent = Entry(root,textvariable = var,font=large_font)
	canvas.create_window(300, 310, window=ent)

	btn2 = Button(root, text="CREATE DATABASE", command=get_entry,height=2,width=15)
	canvas.create_window(170, 370, window=btn2)
	btn3 = Button(root, text="SEARCH", command=getval,height=2,width=15)
	canvas.create_window(400, 370, window=btn3)
	root.mainloop()
	return v,k
