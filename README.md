This is the first project I have undertaken that involves C++
This project aims to simulate a game of chess within the terminal using ASCII characters
to simulate the board

This project will also track data from the game such as win/loss ratios for each player
and save previous games' moves to be replayed.

This project will be done in iterations, any four digit number refers to a UNSW course code,
a simple overview can be found below

#Iter0 - Iteration breakdown
Iterations 1 through 3 will be similar to content that we’ve seen in 1511 dealing with simple grid movement, however later iterations will include content from 1521 and 2521, including file/directory navigation, possible environment/global variables, sorting algorithms, etc.

#Iter1 - Setting up
Set up grid board
Create pieces related enums and structs
Create ascii art for terminal
Find out how to colour text?
Setup phase for settings

#Iter2 - Simple movement
Pieces when selected should be shown e.g > P < indicating you have selected a pawn
Pieces when selected cannot be unselected (like in chess where when you’ve touched a piece you have to move that piece, this could be a setting to toggle off/on)
This also has the added benefit of letting us separate some logic out
Pieces should move around how they are supposed to
Highlight valid moves maybe through !!!

#Iter3 - Winning the game and other game features
Once game has started phases should go as followed:
Select Piece -> Move Piece -> Pass turn to next player -> Loop
Pieces should be able to capture other pieces
Pawn promotion should be implemented
Should show when king is in check and should only allow valid moves
Lets the player win the game
Draw detection? (lowkey not sure how u even draw in chess im larping a little)

#Iter4 - Complex features
Save each move as the game progresses and save into some sort of file (text file perhaps?)
Let players view “replays” of the games by selecting these files, this will be done through the ascii interface and not with pipes such as <
Let players enter their names before playing and track wins/losses, games played, and store this data
Create rankings for this data
