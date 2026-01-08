.PHONY : compile clean game server
default :
	echo "baka"
compile client main : client.o server.o serverHelp.o serverHelp.h tictactoe.o tictactoe.h
	@gcc -o client client.o serverHelp.o tictactoe.o
	@gcc -o main server.o serverHelp.o tictactoe.o
client.o : client.c serverHelp.h
	@gcc -c client.c
server.o : server.c serverHelp.h
	@gcc -c server.c
serverHelp.o : serverHelp.c serverHelp.h tictactoe.h
	@gcc -c serverHelp.c
tictactoe.o : tictactoe.c tictactoe.h
	@gcc -c tictactoe.c
server : main
	@./main
game : client
	@./client
clean :
	@rm -f *.o
	@rm -f client
	@rm -f main
