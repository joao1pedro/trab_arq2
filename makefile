CC:= g++
CPPFLAGS = -std=c++17 -g

all: app

app:
	$(CC) $(CPPFLAGS) decode.cpp -o decode

clean:
	rm -f decode out.txt
