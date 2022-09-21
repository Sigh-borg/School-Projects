# Author: Brian Ngeunjuntr
# Date:   11/15/21
# File:   CellPhone.py
# Descr:
#     Implementation of CellPhone class.
#

class CellPhone:
    # Python uses _init_ (dunder methods) to initialize attributes
    def __init__(self, manufact, model, retail, phNum):
        # "self" refers to the object upon which method was called
        self.__manufacturer = manufact # "__" indicates private
        self.__modelNumber = model
        self.__retailPrice = retail
        self.__phoneNumber = phNum
        return
    
    # Setters
    def setManufacturer(self, manufact):
        self.__manufacturer = manufact
        return
    def setModelNumber(self, model):
        self.__modelNumber = model
    def setRetailPrice(self, retail):
        self.__retailPrice = retail
        return
    def setPhoneNumber(self, phNum):
        self.__phoneNumber = phNum
        return
    
    # Getters
    def getManufacturer(self):
        return self.__manufacturer
    def getModelNumber(self):
        return self.__modelNumber
    def getRetailPrice(self):
        return self.__retailPrice
    def getPhoneNumber(self):
        return self.__phoneNumber
    
    # Module to perform action (aka behavior)
    def sendText(self, phNum, msg):
        print("Sending text message", msg)
        print("From:", self.__phoneNumber, " To:", phNum)
        return


# Main module to test
def main():
    myPhone = CellPhone("Google", "Pixel", 599.99, "555-5555")
    
    yourPhone = CellPhone("", "", 0.0, "")
    
    # Use setters
    yourPhone.setManufacturer("Apple")
    yourPhone.setModelNumber("iPhone")
    yourPhone.setRetailPrice(999.99)
    yourPhone.setPhoneNumber("555-1212")
    
    # Send text
    myPhone.sendText(yourPhone.getPhoneNumber(), "Hello World")
    
# start progam
main()
    