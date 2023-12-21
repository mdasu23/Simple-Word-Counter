# Makefile for ccwc

CC = g++
CFLAGS = -Wall -Wextra -std=c++11

ccwc: ccwc.cpp
		$(CC) $(CFLAGS) -o ccwc ccwc.cpp
clean:
		rm -f ccwc