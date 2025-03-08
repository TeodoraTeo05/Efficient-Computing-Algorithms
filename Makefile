CC = g++
CCFLAGS = -Wall -Wextra -std=c++17 -O0 -lm

.PHONY: build clean

build: numarare trenuri drumuri

run-p1:
	./numarare
run-p2:
	./trenuri
run-p3:
	./drumuri

p1: numarare.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p2: trenuri.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p3: drumuri.cpp
	$(CC) -o $@ $^ $(CCFLAGS)

clean:
	rm -f numarare trenuri drumuri
