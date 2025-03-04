CC = gcc
CFLAGS = -Wall -Wextra -I.
LDFLAGS = -lcurl -lcjson
OBJ = main.o api.o json_parser.o

all: shellbot

install_deps:
	sudo apt-get update
	sudo apt-get install -y libcurl4-openssl-dev libcjson-dev

shellbot: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o shellbot
