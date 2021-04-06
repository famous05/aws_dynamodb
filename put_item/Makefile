CC=g++
CFLAGS=-c -Wall -g

LIBS =  -L/usr/local/lib -laws-cpp-sdk-core
LIBS += -L/usr/local/lib -laws-cpp-sdk-dynamodb
LIBS += -L/usr/local/lib -laws-cpp-sdk-dynamodbstreams
LIBS += -L/usr/lib/x86_64-linux-gnu -lcurl

SOURCES = put_item.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: put_item

put_item: put_item.o
	$(CC) put_item.o -o put_item $(LIBS)
put_item.o: put_item.cpp
	$(CC) $(CFLAGS) put_item.cpp

clean:
	rm -f *.o put_item
