CC:= gcc

all: app_link

app:
	$(CC) -c decode.c

app_link: app
	$(CC) -o decode decode.o

clean:
	@rm decode decode.o
