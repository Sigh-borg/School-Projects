## Name: Brian Ngeunjuntr
## Date:  12/10/2021
## Prog:  PropertyTax_GUI.py
## Descr:
##    Implements a property tax calculator using a graphical interface.

from tkinter import *

class PropertyTax_GUI:
    
    def __init__(self):
        # Main window
        self.mainWindow = Tk()
        self.mainWindow.title("Property Tax Calculator")
        self.mainWindow.geometry("300x120")

        # Frames to group components
        self.propertyValueFrame = Frame(self.mainWindow)
        self.assessmentFrame = Frame(self.mainWindow)
        self.propertyTaxFrame = Frame(self.mainWindow)
        self.buttonsFrame = Frame(self.mainWindow)

        # Actual property value input
        self.propertyValueLabel = Label(self.propertyValueFrame, \
                                        text = "Enter the actual property value: $")
        self.propertyValueEntry = Entry(self.propertyValueFrame, width = 10)

        self.propertyValueLabel.pack(side = "left")
        self.propertyValueEntry.pack(side = "left")

        # Assessment value
        self.aResultLabel = Label(self.assessmentFrame,
                                  text = "Assessment value:")
        self.assessmentLabel = Label(self.assessmentFrame, text = "$0.00")
                                   
        self.aResultLabel.pack(side = "left")
        self.assessmentLabel.pack(side = "left")

        # Property tax
        self.pResultLabel = Label(self.propertyTaxFrame,
                                  text = "Property Tax:")
        propertyTaxVar = StringVar()
        self.propertyTaxLabel = Label(self.propertyTaxFrame, text = "$0.00")
        propertyTaxVar.set("$0")
        
        self.pResultLabel.pack(side = "left")
        self.propertyTaxLabel.pack(side = "left")
        

        # Calculator button
        self.calcButton = Button(self.buttonsFrame,
                                 text = "Calculate Property Tax",
                                 bg = "#CCE5FF",
                                 command = self.calcPropertyInfo)
        self.calcButton.pack(side = "left")

        # Exit button
        self.exitButton = Button(self.buttonsFrame,
                                 text = "Exit",
                                 bg = "#FFCCCC",
                                 command = self.mainWindow.destroy)
        self.exitButton.pack(side = "left")
        
        # Pack the frames
        self.propertyValueFrame.pack()
        self.assessmentFrame.pack()
        self.propertyTaxFrame.pack()
        self.buttonsFrame.pack()
        
        self.mainWindow.mainloop()    

    def calcPropertyInfo(self):
        pValue = float(self.propertyValueEntry.get())
        assessment = pValue * 0.60
        propertyTax = assessment * 0.0064

        self.assessmentLabel.config(text = "${:,.2f}".format(assessment))
        self.propertyTaxLabel.config(text = "${:,.2f}".format(propertyTax))
        
    
def main():
    propertyTaxCalc = PropertyTax_GUI() 
    

main()
