import tkinter as tk


def main():
    #window
    window=tk.Tk()
    window.geometry('1200x800')
    window.title("16x16 grid")

    #canvas
    # canvas=tk.Canvas(window,bg='#1F1E33',height=800,width=800)
    # canvas.pack()

    #lines
    step=800/16
    # for i in range(1, 16):
        # canvas.create_line(step*i,0,step*i,800,fill="#FFB6C1",width=2)
        # canvas.create_line(0,step*i,800,step*i,fill="#FFB6C1",width=2)
    point=[]
    eps=10
    for i in range(1,16):
        item = []
        for j in range(1,16):
            pass
            # item.append(canvas.create_oval(i*step-eps,j*step-eps,i*step+eps,j*step+eps,fill="",outline=""))
        # point.append(item)
    
    but1=tk.Button(window,text="jiao",bg="#000000",width=20,height=5,command=action1).pack(side="left")
    # but2=tk.Button(window,text="da",command=daa).pack()

    window.mainloop()

def action1():
    pass

def daa():
    tmp=2


if __name__ == '__main__':
    main()