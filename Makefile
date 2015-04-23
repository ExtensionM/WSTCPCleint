# Makefile
CC = g++
SRCS = $(wildcard *.cpp)
SRCS += $(wildcard src/*.cpp)
LIBDIR = -L /lib64
INCDIR = -I ~/Build/websocketpp/
LIBS = -lm -lboost_system -lusb-1.0 -lpthread -std=c++11 -lssl -lcrypto
EXECUTABLE = $(SRCS:.cpp=.out)

all:  $(EXECUTABLE)

$(EXECUTABLE):$(SRCS)
	$(CC) $(SRCS) $(LIBDIR) $(INCDIR) $(LIBS) -o $@
