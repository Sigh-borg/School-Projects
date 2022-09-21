##Author:  Brian Ngeunjntr
##Date:    11/22/2021
##Class:   CIS1400 Prog & Logic
##Program: Song.py
##Descr:
##    Definition of superclass Song

class Song:
    
    def __init__(self, art, titl, tim, yr):
        self.__artist = art
        self.__title = titl
        self.__time = tim
        self.__year = yr
        
    def setArtist(self, art):
        self.__artist = art
    def setTitle(self, titl):
        self.__title = titl
    def setTime(self, tim):
        self.__time = tim
    def setYear(self, yr):
        self.__year = yr
    
    def getArtist(self):
        return self.__artist
    def getTitle(self):
        return self.__title
    def getTime(self):
        return self.__time
    def getYear(self):
        return self.__year
    
    
        
    
