CC:= g++
CPPFLAGS = -Wall -std=c++14 -g -Werror

all: app

app:
	$(CC) $(CPPFLAGS) decode.cpp -o decode

clean:
	rm -f decode out.txt
