import tkinter as tk

#window
window=tk.Tk()
window.geometry('400x400')
window.title("4x4 grid")

#canvas
canvas=tk.Canvas(window,bg='#1F1E33',height=400,width=400)
canvas.pack()

#line
canvas.create_line(100,0,100,400,fill="#FFB6C1",width=2)
canvas.create_line(200,0,200,400,fill="#FFB6C1",width=2)
canvas.create_line(300,0,300,400,fill="#FFB6C1",width=2)
canvas.create_line(0,100,400,100,fill="#FFB6C1",width=2)
canvas.create_line(0,200,400,200,fill="#FFB6C1",width=2)
canvas.create_line(0,300,400,300,fill="#FFB6C1",width=2)

window.mainloop()