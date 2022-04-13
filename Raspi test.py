from tkinter import *
from tkinter.ttk import Combobox
# import matplotlib.pyplot as plt
import tkinter.font as tkfont
root=Tk()
root.geometry("1000x530")
root.maxsize(1024,750)
root.config(bg="#124576")
root.title("raspiGUI V 1.1")
color2 ='red'
#Variable for GPIO pin status
counter =IntVar()
var = IntVar()
counter.set(0)
var.set(0)
color=StringVar()
color.set('red')
def GPIO2(var,value):
    counter.set(var.get() + value)
    if counter.get()%2 == 0:
        color2='red'
    else:
        color2='green'
def hello():
    print("hellllooooo")
    color.set("green")
GPIO2=Frame(root, bg="red",relief=GROOVE).pack()
button=Button(GPIO2,text="execute",bg=color,font=('Comic Sans MS',12,'bold'),borderwidth=5,command=hello).pack()
root.mainloop()