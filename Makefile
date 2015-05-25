# Makefile
CC = g++
SRCS = $(wildcard *.cpp)
SRCS += $(wildcard src/*.cpp)
LIBDIR = -L /lib64
INCDIR = -I websocketpp/  -I Jzon/
LIBS = -lm -lboost_system -lusb-1.0 -lpthread -std=c++11 -lssl -lcrypto
TARGET = main.out

all:  $(TARGET)

$(TARGET):$(SRCS)
	$(CC) $(SRCS) $(LIBDIR) $(INCDIR) $(LIBS) -o $@
