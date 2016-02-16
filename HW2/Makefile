#Makefile for HW 2

CC = g++

CFLAGS = -std=c++11 -pthread 

$TARGET = hw2

hw2: fa2_test.cpp
	$(CC) $(CFLAGS) fa2_test.cpp

all: hw2

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGG) -o $(TARGET) $(TARGET).cpp

clean:
	-rm -rf a.out
