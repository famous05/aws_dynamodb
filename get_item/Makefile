CC=g++
CFLAGS=-c -Wall -g

LIBS =  -L/usr/local/lib -laws-cpp-sdk-core
LIBS += -L/usr/local/lib -laws-cpp-sdk-dynamodb
LIBS += -L/usr/local/lib -laws-cpp-sdk-dynamodbstreams
LIBS += -L/usr/lib/x86_64-linux-gnu -lcurl

SOURCES = get_item.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: get_item

get_item: get_item.o
	$(CC) get_item.o -o get_item $(LIBS)
get_item.o: get_item.cpp
	$(CC) $(CFLAGS) get_item.cpp

clean:
	rm -f *.o get_item
