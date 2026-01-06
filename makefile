.PHONY : compile clean game server
default :
	echo "baka"
compile : client.c server.c serverHelp.c serverHelp.h tictactoe.c tictactoe.h
	@gcc -o client client.o serverHelp.o tictactoe.o
	@gcc -o main server.o networking.o
server : main
	@./main
game : client
clean :
	@rm -f *.o
	@rm -f client
	@rm -f server
