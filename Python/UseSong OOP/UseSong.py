##Author:  Brian Ngeunjntr
##Date:    11/22/2021
##Class:   CIS1400 Prog & Logic
##Program: UseSong.py
## Descr:
##     Sample test of the Song class. It asks for user input and stores the data
##     about the song into a data file.

import Song

def main():
    
    print("Enter the song information for song #1")
    songArtist = input("Artist Name: ")
    songTitle = input("Track title: ")
    songLength = float(input("Track Length: "))
    songYear = int(input("Track Year: "))
    song1 = Song.Song(songArtist, songTitle, songLength, songYear)

    songFile = open("song_inventory.dat", "w")

    songFile.write("Song #1: " + str(songArtist)+", " + str(songTitle)+", " + str(songLength)+", " + str(songYear))
    
    print("Enter the song information for song #2")
    songArtist = input("Artist Name: ")
    songTitle = input("Track title: ")
    songLength = float(input("Track Length: "))
    songYear = int(input("Track Year: "))
    song2 = Song.Song(songArtist, songTitle, songLength, songYear)

    songFile.write("\nSong #2: " + str(songArtist)+", " + str(songTitle)+", " + str(songLength)+", " + str(songYear))

    songFile.close()

    totalLength = song1.getTime() + song2.getTime()

    print("The total length of the songs is", totalLength)
    print("The Song inventory has been written to file.")
    
main()

##SAMPLE OUTPUT:
##Enter the song information for song #1
##Artist Name: Coldplay
##Track title: Paradise
##Track Length: 4.39
##Track Year: 2011
##Enter the song information for song #2
##Artist Name: Imagine Dragons
##Track title: On Top of the World
##Track Length: 3.12
##Track Year: 2012
##The total length of the songs is 7.51
##The Song inventory has been written to file.
