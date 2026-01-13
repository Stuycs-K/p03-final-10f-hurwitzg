# Dev Log:

This document must be updated daily every time you finish a work session.

## Gus Hurwitz

### 2026-01-06 - Created proposal, basic outline of the game, and readme
Roughly 15 minutes on readme and 5 on proposal. For the basic outline,
I created the array that displays the board and takes user input. The spot
on the grid that the user inputs will change, and this change is reflected on the screen.
I also created a couple helper methods to manage tasks such as checking if the game is over, setting up the board,
printing the board, changing the board, and translating user input into a spot on the grid. The work on the game took me roughly 90 minutes.

### 2026-01-07 - finished outline of the game, started on server
Roughly 15 minutes on game and 120 on server. I finalized the helper
methods in tictactoe.c and started on serverHelp, server, and client.
As of right now, the two clients can connect to the server. Next step
is to allow the clients to play once they connect.

### 2026-01-08 - 2026-01-11 - continuing on server
Roughly 3 hours on the server. Clients can now connect to each
other, and the server logs the game. Working on streamlining gameplay.

### 2026-01-12 - implementing select
Roughly 1 hour. Began implementing select so that the server knows who's turn it is and the clients
can know when to make a move.
