CC:= g++
CPPFLAGS = -std=c++17 -g
PROGRAM:=decode

all: app

app:
	$(CC) $(CPPFLAGS) $(PROGRAM).cpp $(PROGRAM).hpp -o $(PROGRAM).bin

clean:
	rm -f $(PROGRAM) output.txt
