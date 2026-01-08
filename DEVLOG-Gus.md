# Dev Log:

This document must be updated daily every time you finish a work session.

## Gus Hurwitz

### 2026-01-06 - Created proposal, basic outline of the game, and readme
Roughly 15 minutes on readme and 5 on proposal. For the basic outline,
I created the array that displays the board and takes user input. The spot
on the grid that the user inputs will change, and this change is reflected on the screen.
I also created a couple helper methods to manage tasks such as checking if the game is over, setting up the board,
printing the board, changing the board, and translating user input into a spot on the grid. The work on the game took me roughly 90 minutes.

### 2026-01-07 - Finished game outline, started server
Roughly 10 minutes on game outline and 130 on the server.
I created a server that connects two clients. I then started
to work on the server logic so that the game is actually playable.
The server does all the processing for the game; the clients
are only players. Thus, the code is a little more complicated
than just sending data back and forth.
