print ("This is gui interface for the rasoberry pi moded B+ , Thanks!")
from tkinter import *
from tkinter.ttk import Combobox
# import matplotlib.pyplot as plt
import tkinter.font as tkfont
root=Tk()
root.geometry("1024x750")
root.maxsize(1024,750)
root.config(bg="#124576")
root.title("raspiGUI V 1.1")
def printme():
    value = combo.get()
    print(value)
    root.geometry("924x610")
data="GPIO2 "
a=len(data)
#f1=Frame(root,borderwidth=10, bg="#521364",relief=GROOVE).grid(row=0, column=2)
#pin=Label(root,text="raspiGUI",bg="#256853",borderwidth=5,height=1,font=('Comic Sans MS',20,'bold'), width=50,relief=GROOVE).grid(row=0,column=2)
#Widget for GPIO PIN 2

GPIO2=Frame(root, bg="red",relief=GROOVE).pack(side="top",fill="y")
pin=Label(GPIO2,text=data,borderwidth=5,height=2, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.pack(side="top",fill="y")

lst=["input","output","I2C Data"]
combo=Combobox(GPIO2,value=lst,height=2)
combo.set("-Select Mode-")
combo.pack(side="right",fill="x")
entry1=Entry(GPIO2,borderwidth=5,relief=GROOVE,bg="white")
entry1.pack(side="right",fill="x")
button=Button(GPIO2,text="execute",font=('Comic Sans MS',12,'bold'),borderwidth=5,height=2, width=a,command=printme).pack(side="right",fill="x")

#Widget for GPIO PIN 3

GPIO3=Frame(root,borderwidth=5, bg="red",relief=GROOVE).pack(side="top",fill="y")
pin=Label(GPIO3,text="GPIO3",borderwidth=5,bg="orange",height=2, width=a,relief=GROOVE,font=('Comic Sans MS',12,'bold'))
pin.pack(side="top",fill="y")

lst=["input","output","I2C Clock"]
combo=Combobox(GPIO2,value=lst,height=2)
combo.set("-Select Mode-")
combo.pack(side="top",fill="y")
entry1=Entry(GPIO2,borderwidth=5,relief=GROOVE,bg="white")
entry1.pack(side="top",fill="y")
button=Button(GPIO3,text="execute",font=('Comic Sans MS',12,'bold'),borderwidth=5,height=2, width=a,command=printme).pack(side="top",fill="y")


#Widget for GPIO PIN 4
r=3#Row number

GPIO4=Frame(root, bg="red",relief=GROOVE).pack(side="top",fill="y")
pin=Label(GPIO4,text="GPIO4",borderwidth=5,height=2, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.pack(side="top",fill="y")

lst=["input","output","I2C Data"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.pack(side="top",fill="y")
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.pack(side="top",fill="y")
button=Button(GPIO4,text="execute",font=('Comic Sans MS',12,'bold'),borderwidth=5,height=2, width=a,command=printme).pack(side="top",fill="y")

#Widget for GPIO PIN 5
r=4#Row number

GPIO4=Frame(root, bg="red",relief=GROOVE).pack(side="top",fill="y")
pin=Label(GPIO4,text="GPIO5",borderwidth=5,height=2, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.pack(side="top",fill="y")

lst=["input","output","I2C Data"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.pack(side="top",fill="y")
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.pack(side="top",fill="y")
button=Button(GPIO4,text="execute",font=('Comic Sans MS',12,'bold'),borderwidth=5,height=2, width=a,command=printme).pack(side="top",fill="y")
'''
#Widget for GPIO PIN 6
r=5#Row number

GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=0)
pin=Label(GPIO4,text="GPIO6",borderwidth=5,height=2, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=0,pady=5,)

lst=["input","output","I2C Data"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=1)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=2)
button=Button(GPIO4,text="execute",font=('Comic Sans MS',12,'bold'),borderwidth=5,height=2, width=a,command=printme).grid(row=r,column=3)

#Widget for GPIO PIN 7
r=6#Row number

GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=0)
pin=Label(GPIO4,text="GPIO7",borderwidth=5,height=2, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=0,pady=5,)

lst=["input","output","I2C Data"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=1)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=2)
button=Button(GPIO4,text="execute",font=('Comic Sans MS',12,'bold'),borderwidth=5,height=2, width=a,command=printme).grid(row=r,column=3)

#Widget for GPIO PIN 8
r=7#Row number

GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=0)
pin=Label(GPIO4,text="GPIO8",borderwidth=5,height=2, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=0,pady=5,)

lst=["input","output","I2C Data"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=1)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=2)
button=Button(GPIO4,text="execute",font=('Comic Sans MS',12,'bold'),borderwidth=5,height=2, width=a,command=printme).grid(row=r,column=3)

#Widget for GPIO PIN 9
r=8#Row number

GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=0)
pin=Label(GPIO4,text="GPIO9",borderwidth=5,height=2, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=0,pady=5,)

lst=["input","output","I2C Data"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=1,ipady=5)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=2,ipady=5)
button=Button(GPIO4,text="execute",font=('Comic Sans MS',12,'bold'),borderwidth=5,height=2, width=a,command=printme).grid(row=r,column=3)

#Widget for GPIO PIN 10
r=9#Row number

GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=0)
pin=Label(GPIO4,text="GPIO10",borderwidth=5,height=2, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=0,pady=5,)

lst=["input","output","I2C Data"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=1,ipady=5)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=2,ipady=5)
button=Button(GPIO4,text="execute",font=('Comic Sans MS',12,'bold'),borderwidth=5,height=2, width=a,command=printme).grid(row=r,column=3)

#Widget for GPIO PIN 11
r=10#Row number

GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=0)
pin=Label(GPIO4,text="GPIO11",borderwidth=5,height=2, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=0,pady=5,)

lst=["input","output","I2C Data"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=1,ipady=5)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=2,ipady=5)
button=Button(GPIO4,text="execute",font=('Comic Sans MS',12,'bold'),borderwidth=5,height=2, width=a,command=printme).grid(row=r,column=3)

#Widget for GPIO PIN 12
r=1#Row number

GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=6)
pin=Label(GPIO4,text="GPIO11",borderwidth=5,height=2, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=7,pady=5,padx=10)

lst=["input","output","I2C Data"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=8,ipady=5,padx=10)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=9,ipady=5,padx=10)
button=Button(GPIO4,text="execute",font=('Comic Sans MS',12,'bold'),borderwidth=5,height=2, width=a,command=printme)
button.grid(row=r,column=10,padx=10)

#Widget for GPIO PIN 13
r=2#Row number

GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=6)
pin=Label(GPIO4,text="GPIO13",borderwidth=5,height=2, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=7,pady=5,padx=10)

lst=["input","output","I2C Data"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=8,ipady=5,padx=10)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=9,ipady=5,padx=10)
button=Button(GPIO4,text="execute",font=('Comic Sans MS',12,'bold'),borderwidth=5,height=2, width=a,command=printme)
button.grid(row=r,column=10,padx=10)

#Widget for GPIO PIN 14
r=3#Row number

GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=6)
pin=Label(GPIO4,text="GPIO14",borderwidth=5,height=2, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=7,pady=5,padx=10)

lst=["input","output","I2C Data"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=8,ipady=5,padx=10)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=9,ipady=5,padx=10)
button=Button(GPIO4,text="execute",font=('Comic Sans MS',12,'bold'),borderwidth=5,height=2, width=a,command=printme)
button.grid(row=r,column=10,padx=10)

#Widget for GPIO PIN 15
r=4#Row number

GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=6)
pin=Label(GPIO4,text="GPIO15",borderwidth=5,height=2, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=7,pady=5,padx=10)

lst=["input","output","Serial Rx"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=8,ipady=5,padx=10)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=9,ipady=5,padx=10)
button=Button(GPIO4,text="execute",font=('Comic Sans MS',12,'bold'),borderwidth=5,height=2, width=a,command=printme)
button.grid(row=r,column=10,padx=10)


#Widget for GPIO PIN 16
r=5#Row number

GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=6)
pin=Label(GPIO4,text="GPIO16",borderwidth=5,height=2, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=7,pady=5,padx=10)

lst=["input","output","I2C Data"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=8,ipady=5,padx=10)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=9,ipady=5,padx=10)
button=Button(GPIO4,text="execute",font=('Comic Sans MS',12,'bold'),borderwidth=5,height=2, width=a,command=printme)
button.grid(row=r,column=10,padx=10)

#Widget for GPIO PIN 17
r=6#Row number

GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=6)
pin=Label(GPIO4,text="GPIO17",borderwidth=5,height=2, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=7,pady=5,padx=10)

lst=["input","output"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=8,ipady=5,padx=10)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=9,ipady=5,padx=10)
button=Button(GPIO4,text="execute",font=('Comic Sans MS',12,'bold'),borderwidth=5,height=2, width=a,command=printme)
button.grid(row=r,column=10,padx=10)

#Widget for GPIO PIN 18
r=7#Row number

GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=6)
pin=Label(GPIO4,text="GPIO18",borderwidth=5,height=2, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=7,pady=5,padx=10)

lst=["input","output","I2C Data"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=8,ipady=5,padx=10)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=9,ipady=5,padx=10)
button=Button(GPIO4,text="execute",font=('Comic Sans MS',12,'bold'),borderwidth=5,height=2, width=a,command=printme)
button.grid(row=r,column=10,padx=10)

#Widget for GPIO PIN 19
r=8#Row number

GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=6)
pin=Label(GPIO4,text="GPIO19",borderwidth=5,height=2, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=7,pady=5,padx=10)

lst=["input","output","I2C Data"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=8,ipady=5,padx=10)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=9,ipady=5,padx=10)
button=Button(GPIO4,text="execute",font=('Comic Sans MS',12,'bold'),borderwidth=5,height=2, width=a,command=printme)
button.grid(row=r,column=10,padx=10)

#Widget for GPIO PIN 20
r=9#Row number

GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=6)
pin=Label(GPIO4,text="GPIO20",borderwidth=5,height=2, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=7,pady=5,padx=10)

lst=["input","output","I2C Data"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=8,ipady=5,padx=10)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=9,ipady=5,padx=10)
button=Button(GPIO4,text="execute",font=('Comic Sans MS',12,'bold'),borderwidth=5,height=2, width=a,command=printme)
button.grid(row=r,column=10,padx=10)

#Widget for GPIO PIN 21
r=10#Row number

GPIO4=Frame(root, bg="red",relief=GROOVE).grid(row=r,column=6)
pin=Label(GPIO4,text="GPIO21",borderwidth=5,height=2, width=a,relief=GROOVE,bg="orange",font=('Comic Sans MS',12,'bold'))
pin.grid(row=r,column=7,pady=5,padx=10)

lst=["input","output","I2C Data"]
combo=Combobox(GPIO4,value=lst,height=2)
combo.set("-Select Mode-")
combo.grid(row=r,column=8,ipady=5,padx=10)
entry1=Entry(GPIO4,borderwidth=5,relief=GROOVE,bg="white")
entry1.grid(row=r,column=9,ipady=5,padx=10)
button=Button(GPIO4,text="execute",font=('Comic Sans MS',12,'bold'),borderwidth=5,height=2, width=a,command=printme)
button.grid(row=r,column=10,padx=10)

'''
root.mainloop()