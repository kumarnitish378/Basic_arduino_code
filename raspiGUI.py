print ("This is gui interface for the rasoberry pi moded B+ , Thanks!")
from tkinter import *
from tkinter.ttk import Combobox
# import matplotlib.pyplot as plt
import tkinter.font as tkfont
root=Tk()
root.geometry("1000x530")
root.maxsize(1024,750)
root.config(bg="#124576")
root.title("raspiGUI V 1.1")
#Variable for color changing
color2 ='red'
color3='red'
color4='red'
color5='red'
color6='red'
color7='red'
color8='red'
color9='red'
color10='red'
color11='red'
color12='red'
color13='red'
color14='red'
color15='red'
color16='red'
color17='red'
color18='red'
color19='red'
color20='red'
color21='red'

#Variable for GPIO pin status
counter =IntVar()
var = IntVar()
counter.set(0)
var.set(0)
def printme():
    pass

def GPIO2(var,value):
    counter.set(var.get() + value)
    if counter.get()%2 == 0:
        color2='red'
    else:
        color2='green'
def GPIO3():
    pass
def GPIO4():
    pass
def GPIO5():
    pass
def GPIO6():
    pass
def GPIO7():
    pass
def GPIO8():
    pass
def GPIO9():
    pass
def GPIO10():
    pass
def GPIO11():
    pass
def GPIO12():
    pass
def GPIO13():
    pass
def GPIO14():
    pass
def GPIO15():
    pass
def GPIO16():
    pass
def GPIO17():
    pass
def GPIO18():
    pass
def GPIO19():
    pass
def GPIO20():
    pass
def GPIO21():
    pass


data="GPIO2 "
a=len(data)
#f1=Frame(root,borderwidth=10, bg="#521364",relief=GROOVE).grid(row=0, column=2)
#pin=Label(root,text="raspiGUI",bg="#256853",borderwidth=5,height=1,font=('Comic Sans MS',20,'bold'), width=50,relief=GROOVE).grid(row=0,column=2)

#Widget for GPIO PIN 2

GPIO2=Frame(root, bg="red",relief=GROOVE).grid(row=0,column=0)
pin=Label(GPIO2,text=data,borderwidth=5,height=1, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=1,column=0,ipady=3,pady=3,)

lst=["input","output","I2C Data"]
combo=Combobox(GPIO2,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=1,ipady=3,column=1)
entry1=Entry(GPIO2,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=1,ipady=3,column=2)

button=Button(GPIO2,text="execute",bg=color2,font=('Comic Sans MS',12,'bold'),borderwidth=5,height=1, width=a,command=lambda: GPIO2(counter, 1)).grid(row=1,ipady=3,column=3)

#Widget for GPIO PIN 3

GPIO3=Frame(root,borderwidth=5, bg="red",relief=GROOVE).grid(row=1,ipady=3,column=0)
pin=Label(GPIO3,text="GPIO3",borderwidth=5,bg="orange",height=1, width=a,relief=GROOVE,font=('Comic Sans MS',12,'bold'))
pin.grid(row=2,column=0,pady=3,)

lst=["input","output","I2C Clock"]
combo=Combobox(GPIO2,value=lst,height=2)
combo.grid(row=2,ipady=3,column=1)

combo.set("-Select Mode-")
entry1=Entry(GPIO2,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=2,ipady=3,column=2)
button=Button(GPIO3,text="execute",bg=color3,font=('Comic Sans MS',12,'bold'),borderwidth=5,height=1, width=a,command=printme).grid(row=2,ipady=3,column=3)


#Widget for GPIO PIN 4
r=3#Row number

GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,ipady=3,column=0)
pin=Label(GPIO4,text="GPIO4",borderwidth=5,height=1, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=0,ipady=3,pady=3,)

lst=["input","output"]
combo=Combobox(GPIO4,value=lst,height=1)
combo.set("-Select Mode-")
combo.grid(row=r,ipady=3,column=1)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,ipady=3,column=2)
button=Button(GPIO4,text="execute",bg=color4,font=('Comic Sans MS',12,'bold'),borderwidth=5,height=1, width=a,command=printme).grid(row=r,ipady=3,column=3)

#Widget for GPIO PIN 5
r=4#Row number

#GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,ipady=3,column=0)
pin=Label(GPIO4,text="GPIO5",borderwidth=5,height=1, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=0,ipady=3,pady=3,)

lst=["input","output"]
combo=Combobox(GPIO4,value=lst,height=1)
combo.set("-Select Mode-")
combo.grid(row=r,ipady=3,column=1)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,ipady=5,column=2)
button=Button(GPIO4,text="execute",bg=color5,font=('Comic Sans MS',12,'bold'),borderwidth=5,height=1, width=a,command=printme).grid(row=r,ipady=3,column=3)

#Widget for GPIO PIN 6
r=5#Row number

#GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,ipady=3,column=0)
pin=Label(GPIO4,text="GPIO6",borderwidth=5,height=1, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=0,ipady=3,pady=3,)

lst=["input","output","SPIO1"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,ipady=5,column=1)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,ipady=5,column=2)
button=Button(GPIO4,text="execute",bg=color6,font=('Comic Sans MS',12,'bold'),borderwidth=5,height=1, width=a,command=printme).grid(row=r,ipady=5,column=3)

#Widget for GPIO PIN 7
r=6#Row number

#GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,ipady=5,column=0)
pin=Label(GPIO4,text="GPIO7",borderwidth=5,height=1, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=0,ipady=5,pady=5,)

lst=["input","output","SPIO0"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,ipady=5,column=1)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,ipady=5,column=2)
button=Button(GPIO4,text="execute",bg=color7,font=('Comic Sans MS',12,'bold'),borderwidth=5,height=1, width=a,command=printme).grid(row=r,ipady=5,column=3)

#Widget for GPIO PIN 8
r=7#Row number

#GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,ipady=5,column=0)
pin=Label(GPIO4,text="GPIO8",borderwidth=5,height=1, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=0,ipady=5,pady=5,)

lst=["input","output","SPIO0"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,ipady=5,column=1)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,ipady=5,column=2)
button=Button(GPIO4,text="execute",bg=color8,font=('Comic Sans MS',12,'bold'),borderwidth=5,height=1, width=a,command=printme).grid(row=r,ipady=5,column=3)

#Widget for GPIO PIN 9
r=8#Row number

#GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=0)
pin=Label(GPIO4,text="GPIO9",borderwidth=5,height=1, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=0,pady=5,padx=10)

lst=["input","output","SPIO0"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=1,ipady=5,padx=10)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=2,ipady=5,padx=10)
button=Button(GPIO4,text="execute",bg=color9,font=('Comic Sans MS',12,'bold'),borderwidth=5,height=1, width=a,command=printme).grid(row=r,column=3)

#Widget for GPIO PIN 10
r=9#Row number

#GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=0)
pin=Label(GPIO4,text="GPIO10",borderwidth=5,height=1, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=0,pady=5,)

lst=["input","output"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=1,ipady=5)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=2,ipady=5)
button=Button(GPIO4,text="execute",bg=color10,font=('Comic Sans MS',12,'bold'),borderwidth=5,height=1, width=a,command=printme).grid(row=r,column=3)

#Widget for GPIO PIN 11
r=10#Row number

#GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=0)
pin=Label(GPIO4,text="GPIO11",borderwidth=5,height=1, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=0,pady=5,)

lst=["input","output"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=1,ipady=5)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=2,ipady=5)
button=Button(GPIO4,text="execute",bg=color11,font=('Comic Sans MS',12,'bold'),borderwidth=5,height=1, width=a,command=printme).grid(row=r,column=3)

#Widget for GPIO PIN 12
r=1#Row number

#GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=6)
pin=Label(GPIO4,text="GPIO12",borderwidth=5,height=1, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=7,pady=5,padx=10)

lst=["input","output","PWM"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=8,ipady=5,padx=10)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=9,ipady=5,padx=10)
button=Button(GPIO4,text="execute",bg=color12,font=('Comic Sans MS',12,'bold'),borderwidth=5,height=1, width=a,command=printme)
button.grid(row=r,column=10,padx=10)

#Widget for GPIO PIN 13
r=2#Row number

#GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=6)
pin=Label(GPIO4,text="GPIO13",borderwidth=5,height=1, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=7,pady=5,padx=10)

lst=["input","output","PWM"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=8,ipady=5,padx=10)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=9,ipady=5,padx=10)
button=Button(GPIO4,text="execute",bg=color13,font=('Comic Sans MS',12,'bold'),borderwidth=5,height=1, width=a,command=printme)
button.grid(row=r,column=10,padx=10)

#Widget for GPIO PIN 14
r=3#Row number

#GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=6)
pin=Label(GPIO4,text="GPIO14",borderwidth=5,height=1, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=7,pady=5,padx=10)

lst=["input","output"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=8,ipady=5,padx=10)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=9,ipady=5,padx=10)
button=Button(GPIO4,text="execute",bg=color14,font=('Comic Sans MS',12,'bold'),borderwidth=5,height=1, width=a,command=printme)
button.grid(row=r,column=10,padx=10)

#Widget for GPIO PIN 15
r=4#Row number

#GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=6)
pin=Label(GPIO4,text="GPIO15",borderwidth=5,height=1, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=7,pady=5,padx=10)

lst=["input","output","Serial Rx"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=8,ipady=5,padx=10)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=9,ipady=5,padx=10)
button=Button(GPIO4,text="execute",bg=color15,font=('Comic Sans MS',12,'bold'),borderwidth=5,height=1, width=a,command=printme)
button.grid(row=r,column=10,padx=10)


#Widget for GPIO PIN 16
r=5#Row number

#GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=6)
pin=Label(GPIO4,text="GPIO16",borderwidth=5,height=1, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=7,pady=5,padx=10)

lst=["input","output"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=8,ipady=5,padx=10)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=9,ipady=5,padx=10)
button=Button(GPIO4,text="execute",bg=color16,font=('Comic Sans MS',12,'bold'),borderwidth=5,height=1, width=a,command=printme)
button.grid(row=r,column=10,padx=10)

#Widget for GPIO PIN 17
r=6#Row number

#GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=6)
pin=Label(GPIO4,text="GPIO17",borderwidth=5,height=1, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=7,pady=5,padx=10)

lst=["input","output","SPI1"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=8,ipady=5,padx=10)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=9,ipady=5,padx=10)
button=Button(GPIO4,text="execute",bg=color17,font=('Comic Sans MS',12,'bold'),borderwidth=5,height=1, width=a,command=printme)
button.grid(row=r,column=10,padx=10)

#Widget for GPIO PIN 18
r=7#Row number

#GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=6)
pin=Label(GPIO4,text="GPIO18",borderwidth=5,height=1, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=7,pady=5,padx=10)

lst=["input","output","SPI1"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=8,ipady=5,padx=10)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=9,ipady=5,padx=10)
button=Button(GPIO4,text="execute",bg=color18,font=('Comic Sans MS',12,'bold'),borderwidth=5,height=1, width=a,command=printme)
button.grid(row=r,column=10,padx=10)

#Widget for GPIO PIN 19
r=8#Row number

#GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=6)
pin=Label(GPIO4,text="GPIO19",borderwidth=5,height=1, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=7,pady=5,padx=10)

lst=["input","output","SPI1"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=8,ipady=5,padx=10)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=9,ipady=5,padx=10)
button=Button(GPIO4,text="execute",bg=color19,font=('Comic Sans MS',12,'bold'),borderwidth=5,height=1, width=a,command=printme)
button.grid(row=r,column=10,padx=10)

#Widget for GPIO PIN 20
r=9#Row number

#GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=6)
pin=Label(GPIO4,text="GPIO20",borderwidth=5,height=1, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=7,pady=5,padx=10)

lst=["input","output","SPI1"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=8,ipady=5,padx=10)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=9,ipady=5,padx=10)
button=Button(GPIO4,text="execute",bg=color20,font=('Comic Sans MS',12,'bold'),borderwidth=5,height=1, width=a,command=printme)
button.grid(row=r,column=10,padx=10)

#Widget for GPIO PIN 21
r=10#Row number

#GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=6)
pin=Label(GPIO4,text="GPIO21",borderwidth=5,height=1, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=7,pady=5,padx=10)

lst=["input","output","SPI1"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=8,ipady=5,padx=10)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=9,ipady=5,padx=10)
button=Button(GPIO4,text="execute",bg=color21,font=('Comic Sans MS',12,'bold'),borderwidth=5,height=1, width=a,command=printme)
button.grid(row=r, column=10,padx=5)
root.mainloop()