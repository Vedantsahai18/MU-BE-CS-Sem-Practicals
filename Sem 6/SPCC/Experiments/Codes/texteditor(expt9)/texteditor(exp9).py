from tkinter import *
from tkinter import filedialog
from tkinter import messagebox
from tkinter.filedialog import askopenfilename, asksaveasfilename
import datetime

def normal():
    text.config(font=('Arial', 10))
    
def bold():
    text.config(font=('Arial', 10, 'bold'))

def italics():
    text.config(font=('Arial', 10, 'italic'))
    
def underline():
    text.config(font=('Arial', 10, 'underline'))

def opn():
    text.delete(1.0, END)

    file = open(askopenfilename(), 'r')

    if file != " ":
        txt = file.read()
        text.insert(INSERT, txt)
    
    else:
        pass

def save():
    filename = asksaveasfilename

    if filename:
        alltext = text.get(1.0, END)
        open(filename, 'w').write(alltext)

def copy():
    text.clipboard_clear()
    text.clipboard_append(text.selection_get())


def paste():
    try:
        txt = text.selection_get(selection="CLIPBOARD")
        text.insert(INSERT, txt)
    
    except:
        tkMessageBox.showerror('Error')

def clear():
    sel = text.get(SEL_FIRST, SEL_LAST)
    text.delete(SEL_FIRST, SEL_LAST)

root = Tk()
root.title("Text Editor")
menu = Menu(root)
filemenu = Menu(root)
root.config(menu=menu)
menu.add_cascade(label="File", menu=filemenu)
filemenu.add_cascade(label="Open", command=opn)
filemenu.add_cascade(label="Save", command=save)
filemenu.add_separator()
edit = Menu(root)
menu.add_cascade(label="Edit", menu=edit)
edit.add_cascade(label="Copy", command=copy)
edit.add_cascade(label="Paste", command=paste)
edit.add_separator()
formatmenu = Menu(root)
menu.add_cascade(label="Format", menu=formatmenu)
formatmenu.add_radiobutton(label="Normal", command=normal)
formatmenu.add_radiobutton(label="Bold", command=bold)
formatmenu.add_radiobutton(label="Italic", command=italics)
formatmenu.add_radiobutton(label="Underline", command=underline)
text = Text(root, height=50, width=100, font=("Arial", 10))
scroll = Scrollbar(root, command=text.yview)
scroll.config(command=text.yview)
scroll.pack(side=RIGHT, fill=Y)
text.pack()
root.resizable(0,0)
root.mainloop()